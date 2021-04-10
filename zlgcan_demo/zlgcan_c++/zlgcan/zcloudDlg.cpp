// zcloudDlg.cpp : implementation file
//

#include "stdafx.h"
#include "zcloudDlg.h"
#include "zlgcanDemo.h"
#include "zlgcan/zlgcan.h"


// zcloudDlg dialog

IMPLEMENT_DYNAMIC(zcloudDlg, CDialog)

zcloudDlg::zcloudDlg(CWnd* pParent /*=NULL*/)
: CDialog(zcloudDlg::IDD, pParent)
{

}

zcloudDlg::~zcloudDlg()
{
}

void zcloudDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LIST_DEVICE, m_deviceList);
    DDX_Control(pDX, IDC_EDIT_HTTP_ADDR, m_httpAddr);
    DDX_Control(pDX, IDC_EDIT_HTTP_PORT, m_httpPort);
    DDX_Control(pDX, IDC_EDIT_MQTT_ADDR, m_mqttAddr);
    DDX_Control(pDX, IDC_EDIT_MQTT_PORT, m_mqttPort);
    DDX_Control(pDX, IDC_EDIT_USERNAME, m_username);
    DDX_Control(pDX, IDC_EDIT_PASSWORD, m_password);
}


BEGIN_MESSAGE_MAP(zcloudDlg, CDialog)
    ON_BN_CLICKED(IDC_BUTTON_CONNECT, &zcloudDlg::OnBnClickedButtonConnect)
    ON_BN_CLICKED(IDC_BUTTON_DISCONNECT, &zcloudDlg::OnBnClickedButtonDisconnect)
    ON_NOTIFY(NM_CLICK, IDC_LIST_DEVICE, &zcloudDlg::OnNMClickListDevice)
END_MESSAGE_MAP()

BOOL zcloudDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    m_httpAddr.SetWindowText(TEXT("zlab.zlgcloud.com"));
    m_httpPort.SetWindowText(TEXT("443"));
    m_mqttAddr.SetWindowText(TEXT("zlab.zlgcloud.com"));
    m_mqttPort.SetWindowText(TEXT("8143"));
    m_username.SetWindowText(TEXT("abc"));
    m_password.SetWindowText(TEXT("123"));

    LONG lStyle = GetWindowLong(m_deviceList.m_hWnd, GWL_STYLE);
    lStyle &= ~LVS_TYPEMASK;
    lStyle |= LVS_REPORT;
    SetWindowLong(m_deviceList.m_hWnd, GWL_STYLE, lStyle);

    DWORD dwStyle = m_deviceList.GetExtendedStyle();
    dwStyle |= LVS_EX_FULLROWSELECT;
    dwStyle |= LVS_EX_GRIDLINES;;
    m_deviceList.SetExtendedStyle(dwStyle);

    m_deviceList.InsertColumn(0, TEXT("设备ID"), LVCFMT_LEFT, 200);
    m_deviceList.InsertColumn(1, TEXT("状态"), LVCFMT_LEFT, 80);

    GetDlgItem(IDC_BUTTON_DISCONNECT)->EnableWindow(FALSE);
    GetDlgItem(IDOK)->EnableWindow(FALSE);

    return 0;
}

// zcloudDlg message handlers

void zcloudDlg::OnBnClickedButtonConnect()
{
    // TODO: Add your control notification handler code here
    {
        TCHAR buffer[255];
        USES_CONVERSION;
        m_httpAddr.GetWindowText(buffer, 255);
        const char* httpAddr = T2A(buffer);
        m_httpPort.GetWindowText(buffer, 255);
        const char* port = T2A(buffer);
        unsigned short httpPort = 0;
        while (*port)
        {
            httpPort *= 10;
            httpPort += *port - '0';
            ++port;
        }
        m_mqttAddr.GetWindowText(buffer, 255);
        const char* mqttAddr = T2A(buffer);
        m_mqttPort.GetWindowText(buffer, 255);
        port = T2A(buffer);
        unsigned short mqttPort = 0;
        while (*port)
        {
            mqttPort *= 10;
            mqttPort += *port - '0';
            ++port;
        }
        ZCLOUD_SetServerInfo(httpAddr, httpPort, mqttAddr, mqttPort);
        m_username.GetWindowText(buffer, 255);
        const char* username = T2A(buffer);
        m_password.GetWindowText(buffer, 255);
        const char* password = T2A(buffer);
        UINT ret = ZCLOUD_ConnectServer(username, password);
        switch (ret)
        {
        case 1:
            MessageBox(TEXT("连接服务器失败"), TEXT("ZCLOUD"), MB_OK | MB_ICONEXCLAMATION);
            return;
        case 2:
            MessageBox(TEXT("HTTP错误"), TEXT("ZCLOUD"), MB_OK | MB_ICONEXCLAMATION);
            return;
        case 3:
            MessageBox(TEXT("用户登录信息错误"), TEXT("ZCLOUD"), MB_OK | MB_ICONEXCLAMATION);
            return;
        case 4:
            MessageBox(TEXT("MQTT连接错误"), TEXT("ZCLOUD"), MB_OK | MB_ICONEXCLAMATION);
            return;
        default:
            break;
        }
    }
    const ZCLOUD_USER_DATA* data = ZCLOUD_GetUserData();
    if (data == NULL) return;
    for (size_t i=0; i<data->devCnt; ++i)
    {
        const ZCLOUD_DEVINFO& device = data->devices[i];
        USES_CONVERSION;
        LPCTSTR id = A2T(device.id);
        LPCTSTR status = device.status==0 ? TEXT("在线") : TEXT("离线");
        m_deviceList.InsertItem(0, id);
        m_deviceList.SetItemText(0, 1, status);
        m_deviceIndices.Add(device.devIndex);
    }

    m_httpAddr.EnableWindow(FALSE);
    m_httpPort.EnableWindow(FALSE);
    m_mqttAddr.EnableWindow(FALSE);
    m_mqttPort.EnableWindow(FALSE);
    m_username.EnableWindow(FALSE);
    m_password.EnableWindow(FALSE);
    m_deviceList.EnableWindow(TRUE);
    GetDlgItem(IDC_BUTTON_CONNECT)->EnableWindow(FALSE);
    GetDlgItem(IDC_BUTTON_DISCONNECT)->EnableWindow(TRUE);

    POSITION pos = m_deviceList.GetFirstSelectedItemPosition();
    GetDlgItem(IDOK)->EnableWindow(pos != NULL);
}

void zcloudDlg::OnBnClickedButtonDisconnect()
{
    // TODO: Add your control notification handler code here
    m_deviceList.DeleteAllItems();
    m_deviceIndices.RemoveAll();

    m_httpAddr.EnableWindow(TRUE);
    m_httpPort.EnableWindow(TRUE);
    m_mqttAddr.EnableWindow(TRUE);
    m_mqttPort.EnableWindow(TRUE);
    m_username.EnableWindow(TRUE);
    m_password.EnableWindow(TRUE);
    m_deviceList.EnableWindow(FALSE);
    GetDlgItem(IDC_BUTTON_CONNECT)->EnableWindow(TRUE);
    GetDlgItem(IDC_BUTTON_DISCONNECT)->EnableWindow(FALSE);
    GetDlgItem(IDOK)->EnableWindow(FALSE);
}

void zcloudDlg::OnNMClickListDevice(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
    // TODO: Add your control notification handler code here
    POSITION pos = m_deviceList.GetFirstSelectedItemPosition();
    GetDlgItem(IDOK)->EnableWindow(pos != NULL);
    if (pos != NULL)
    {
        int index = m_deviceList.GetNextSelectedItem(pos);
        m_deviceIndex = m_deviceIndices.GetAt(index);
    }
    *pResult = 0;
}

unsigned zcloudDlg::GetDeviceIndex() const
{
    return m_deviceIndex;
}
