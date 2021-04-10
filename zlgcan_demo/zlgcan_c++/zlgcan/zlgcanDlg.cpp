
// zlgcanDlg.cpp : 实现文件
//

#include "stdafx.h"
#include <process.h>
#include "zlgcanDemo.h"
#include "zlgcanDlg.h"
#include "zlgcan/zlgcan.h"
#include "utility.h"
#include "zcloudDlg.h"

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

// Cusbcanfdx00udemoDlg 对话框

CZlgcanDlg::CZlgcanDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CZlgcanDlg::IDD, pParent)
	, device_type_index_(0)
	, device_index_(0)
	, channel_index_(0)
	, work_mode_index_(0)
	, abit_baud_index_(0)
	, dbit_baud_index_(0)
	, custom_baud_enable_(FALSE)
	, resistance_enable_(TRUE)
	, frame_type_index_(0)
	, protocol_index_(1)
	, canfd_exp_index_(0)
	, send_type_index_(0)
	, acc_code_(_T("00000000"))
	, acc_mask_(_T("FFFFFFFF"))
	, id_(_T("00000001"))
	, datas_(_T("00 11 22 33 44 55 66 77"))
	, custom_baudrate_(_T(""))
	, filter_mode_(1)
    , net_mode_index_(0)
    , baud_index_(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	device_opened_ = FALSE;
	start_ = FALSE;
}

void CZlgcanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_CBIndex(pDX, IDC_COMBO_DEVICE, device_type_index_);
	DDX_CBIndex(pDX, IDC_COMBO_DEVICE_INDEX, device_index_);
	DDX_CBIndex(pDX, IDC_COMBO_CHANNEL_INDEX, channel_index_);
	DDX_CBIndex(pDX, IDC_COMBO_DEVICE_INDEX2, work_mode_index_);
	DDX_CBIndex(pDX, IDC_COMBO_ABIT, abit_baud_index_);
	DDX_CBIndex(pDX, IDC_COMBO_ABIT2, dbit_baud_index_);
	DDX_CBIndex(pDX, IDC_COMBO_BAUD, baud_index_);
	DDX_Check(pDX, IDC_CHECK_CUSTOM_BAUDRATE, custom_baud_enable_);
	DDX_Check(pDX, IDC_CHECK_RESISTANCE, resistance_enable_);
	DDX_CBIndex(pDX, IDC_COMBO_FRAME_TYPE, frame_type_index_);
	DDX_CBIndex(pDX, IDC_COMBO_PROTOCOL, protocol_index_);
	DDX_CBIndex(pDX, IDC_COMBO_CANFD_EXP, canfd_exp_index_);
	DDX_CBIndex(pDX, IDC_COMBO_SEND_TYPE, send_type_index_);
	DDX_Control(pDX, IDC_LIST1, data_recv_list_);
	DDX_Text(pDX, IDC_EDIT_ACC_CODE, acc_code_);
	DDV_MaxChars(pDX, acc_code_, 8);
	DDX_Text(pDX, IDC_EDIT_ACC_MASK, acc_mask_);
	DDV_MaxChars(pDX, acc_mask_, 8);
	DDX_Text(pDX, IDC_EDIT_FILTER_START2, id_);
	DDV_MaxChars(pDX, id_, 8);
	DDX_Text(pDX, IDC_EDIT_FILTER_START3, datas_);
	DDX_Control(pDX, IDC_COMBO_DEVICE, ctrl_device_type_);
	DDX_Control(pDX, IDC_COMBO_DEVICE_INDEX, ctrl_device_index_);
	DDX_Control(pDX, IDC_COMBO_CHANNEL_INDEX, ctrl_channel_index_);
	DDX_Text(pDX, IDC_EDIT_CUSTOM_BAUDRATE, custom_baudrate_);
	DDX_Control(pDX, IDC_BUTTON_OPEN, ctrl_open_device_);
	DDX_Control(pDX, IDC_BUTTON_INITCAN, ctrl_int_can_);
	DDX_Control(pDX, IDC_BUTTON_STARTCAN, ctrl_start_can_);
	DDX_Control(pDX, IDC_BUTTON_CLOSE, ctrl_close_device_);
	DDX_CBIndex(pDX, IDC_COMBO_FILTER_MODE, filter_mode_);
	DDX_CBIndex(pDX, IDC_COMBO_NET_MODE, net_mode_index_);
}

BEGIN_MESSAGE_MAP(CZlgcanDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_OPEN, &CZlgcanDlg::OnBnClickedButtonOpen)
	ON_BN_CLICKED(IDC_BUTTON_INITCAN, &CZlgcanDlg::OnBnClickedButtonInitcan)
	ON_BN_CLICKED(IDC_BUTTON_STARTCAN, &CZlgcanDlg::OnBnClickedButtonStartcan)
	ON_BN_CLICKED(IDC_BUTTON_RESET, &CZlgcanDlg::OnBnClickedButtonReset)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &CZlgcanDlg::OnBnClickedButtonClose)
	ON_BN_CLICKED(IDC_BUTTON_SEND, &CZlgcanDlg::OnBnClickedButtonSend)
	ON_CBN_SELCHANGE(IDC_COMBO_DEVICE, &CZlgcanDlg::OnCbnSelchangeComboDevice)
	ON_CBN_SELCHANGE(IDC_COMBO_NET_MODE, &CZlgcanDlg::OnCbnSelchangeComboNetMode)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CZlgcanDlg::OnBnClickedButtonClear)
END_MESSAGE_MAP()


// Cusbcanfdx00udemoDlg 消息处理程序

BOOL CZlgcanDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	InitCombobox(IDC_COMBO_DEVICE_INDEX, 0, 32, 0);
	OnCbnSelchangeComboDevice();
    GetDlgItem(IDC_STATIC_SEP)->EnableWindow(FALSE);
    SetDlgItemText(IDC_EDIT_LOCAL_PORT, TEXT("1080"));
    SetDlgItemText(IDC_EDIT_REMOTE_ADDR, TEXT("192.168.28.222"));
    SetDlgItemText(IDC_EDIT_REMOTE_PORT, TEXT("4001"));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CZlgcanDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CZlgcanDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CZlgcanDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

typedef struct _DeviceInfo
{
	UINT device_type;  //设备类型
	UINT channel_count;//设备的通道个数
}DeviceInfo;
static const DeviceInfo kDeviceType[] = {
    {ZCAN_USBCAN1, 1},
    {ZCAN_USBCAN2, 2},
    {ZCAN_USBCAN_E_U, 1},
    {ZCAN_USBCAN_2E_U, 2},
	{ZCAN_PCIE_CANFD_100U, 1},
	{ZCAN_PCIE_CANFD_200U, 2},
	{ZCAN_PCIE_CANFD_400U, 4},
	{ZCAN_USBCANFD_200U, 2},
	{ZCAN_USBCANFD_100U, 1},
	{ZCAN_USBCANFD_MINI, 1},
    {ZCAN_CANETTCP, 1},
    {ZCAN_CANETUDP, 1},
	{ZCAN_CLOUD, 1},
};

void CZlgcanDlg::OnBnClickedButtonOpen()
{
	UpdateData(TRUE);
    if (kDeviceType[device_type_index_].device_type == ZCAN_CLOUD)
    {
        zcloudDlg dlg;
        if (IDCANCEL == dlg.DoModal())
        {
            return;
        }
        device_index_ = dlg.GetDeviceIndex();
    }
    device_handle_ = ZCAN_OpenDevice(kDeviceType[device_type_index_].device_type, device_index_, 0);
	if (INVALID_DEVICE_HANDLE == device_handle_)
	{
		AddData(_T("打开设备失败!"));
		return;
	}
	device_opened_ = TRUE;
	EnableCtrl(TRUE);
}

static const UINT kAbitTiming[] = {
    0x00018B2E,//1Mbps
    0x00018E3A,//800kbps
    0x0001975E,//500kbps
    0x0001AFBE,//250kbps
    0x0041AFBE,//125kbps
    0x0041BBEE,//100kbps
    0x00C1BBEE //50kbps
};
static const UINT kDbitTiming[] = {
    0x00010207,//5Mbps
    0x0001020A,//4Mbps
    0x0041020A,//2Mbps
    0x0081830E //1Mbps
};
static const BYTE kTiming0[] = {
	0x00,//1000kbps
	0x00,//800kbps
	0x00,//500kbps
	0x01,//250kbps
	0x03,//125kbps
	0x04,//100kbps
	0x09,//50kbps
	0x18,//20kbps
	0x31,//10kbps
	0xBF //5kbps
};
static const BYTE kTiming1[] = {
	0x14,//1000kbps
	0x16,//800kbps
	0x1C,//500kbps
	0x1C,//250kbps
	0x1C,//125kbps
	0x1C,//100kbps
	0x1C,//50kbps
	0x1C,//20kbps
	0x1C,//10kbps
	0xFF //5kbps
};
static const unsigned kBaudrate[] = {
    1000000,
    800000,
    500000,
    250000,
    125000,
    100000,
    50000,
    20000,
    10000,
    5000
};

void CZlgcanDlg::OnBnClickedButtonInitcan()
{
	if (!device_opened_)
	{
		AddData(_T("设备还没打开!"));
		return;
	}
	ZCAN_CHANNEL_INIT_CONFIG config;
	memset(&config, 0, sizeof(config));
    UpdateData(TRUE);
    UINT type = kDeviceType[device_type_index_].device_type;
    const BOOL cloudDevice = type==ZCAN_CLOUD;
    const BOOL netDevice = type==ZCAN_CANETUDP || type==ZCAN_CANETTCP;
    const BOOL tcpDevice = type==ZCAN_CANETTCP;
    const BOOL server = net_mode_index_ == 0;
    const BOOL usbcanfd = type==ZCAN_USBCANFD_100U ||
        type==ZCAN_USBCANFD_200U || type==ZCAN_USBCANFD_MINI;
    const BOOL pciecanfd = type==ZCAN_PCIE_CANFD_100U ||
        type==ZCAN_PCIE_CANFD_200U || type==ZCAN_PCIE_CANFD_400U;
    const BOOL canfdDevice = usbcanfd || pciecanfd;

    property_ = GetIProperty(device_handle_);
    if (cloudDevice)
    {
    }
    else if (netDevice)
    {
        char path[50] = {0};
        char value[100] = {0};
        TCHAR buffer[100] = {0};
        if (tcpDevice)
        {
            sprintf_s(path, "%d/work_mode", channel_index_);
            sprintf_s(value, "%d", server?1:0);
            property_->SetValue(path, value);
            if (server)
            {
                sprintf_s(path, "%d/local_port", channel_index_);
                GetDlgItemText(IDC_EDIT_LOCAL_PORT, buffer, 100);
                sprintf_s(value, "%s", Utility::W2AEx(buffer).c_str());
                property_->SetValue(path, value);
            } // server
            else
            {
                sprintf_s(path, "%d/ip", channel_index_);
                GetDlgItemText(IDC_EDIT_REMOTE_ADDR, buffer, 100);
                sprintf_s(value, "%s", Utility::W2AEx(buffer).c_str());
                property_->SetValue(path, value);
                sprintf_s(path, "%d/work_port", channel_index_);
                GetDlgItemText(IDC_EDIT_REMOTE_PORT, buffer, 100);
                sprintf_s(value, "%s", Utility::W2AEx(buffer).c_str());
                property_->SetValue(path, value);
            }
        } // tcp
        else
        {
            sprintf_s(path, "%d/local_port", channel_index_);
            GetDlgItemText(IDC_EDIT_LOCAL_PORT, buffer, 100);
            sprintf_s(value, "%s", Utility::W2AEx(buffer).c_str());
            property_->SetValue(path, value);
            sprintf_s(path, "%d/ip", channel_index_);
            GetDlgItemText(IDC_EDIT_REMOTE_ADDR, buffer, 100);
            sprintf_s(value, "%s", Utility::W2AEx(buffer).c_str());
            property_->SetValue(path, value);
            sprintf_s(path, "%d/work_port", channel_index_);
            GetDlgItemText(IDC_EDIT_REMOTE_PORT, buffer, 100);
            sprintf_s(value, "%s", Utility::W2AEx(buffer).c_str());
            property_->SetValue(path, value);
        }
    }
    else
    {
        //设置波特率
        if (custom_baud_enable_)
        {	
            if (!SetCustomBaudrate())
            {
                AddData(_T("设置自定义波特率失败!"));
                return;
            }
        }
        else
        {
            if (!canfdDevice && !SetBaudrate())
            {
                AddData(_T("设置波特率失败!"));
                return;
            }
        }
        if (pciecanfd)
        {
            //设置发送方式
            if (!SetTransmitType())
            {
                AddData(_T("设置发送方式失败!"));
                return;
            }
        }
        if (usbcanfd) {
            IProperty* p = GetIProperty(device_handle_);
            char path[50] = {0};
            char value[100] = {0};
            sprintf_s(path, "%d/canfd_standard", channel_index_);
            sprintf_s(value, "%d", 0);
            property_->SetValue(path, value);
        }
        if (canfdDevice)
        {
            config.can_type = TYPE_CANFD;
            config.canfd.mode = work_mode_index_;
            config.canfd.abit_timing = kAbitTiming[abit_baud_index_];
            config.canfd.dbit_timing = kDbitTiming[dbit_baud_index_];
            config.canfd.filter = filter_mode_;
            config.canfd.acc_code = _tcstoul(acc_code_, 0, 16);
            config.canfd.acc_mask = _tcstoul(acc_mask_, 0, 16);
        }
        else
        {
            config.can_type = TYPE_CAN;
            config.can.mode = work_mode_index_;
            config.can.timing0 = kTiming0[baud_index_];
            config.can.timing1 = kTiming1[baud_index_];
            config.can.filter = filter_mode_;
            config.can.acc_code = _tcstoul(acc_code_, 0, 16);
            config.can.acc_mask = _tcstoul(acc_mask_, 0, 16);
        }
    }

	channel_handle_ = ZCAN_InitCAN(device_handle_, channel_index_, &config);
	if (INVALID_CHANNEL_HANDLE == channel_handle_)
	{
		AddData(_T("初始化CAN失败!"));
		return;
	}
    if (usbcanfd)
    {
        if (resistance_enable_ && !SetResistanceEnable())
        {
            AddData(_T("设置终端电阻失败!"));
            return;
        }
    }
	ctrl_int_can_.EnableWindow(FALSE);
}

void CZlgcanDlg::OnBnClickedButtonStartcan()
{
	if (ZCAN_StartCAN(channel_handle_) != STATUS_OK)
	{
		AddData(_T("启动CAN失败!"));
		return;
	}
	ctrl_start_can_.EnableWindow(FALSE);
	start_ = TRUE;
	_beginthreadex(NULL, 0, OnDataRecv, this, 0, NULL);
}

void CZlgcanDlg::OnBnClickedButtonReset()
{
	if (ZCAN_ResetCAN(channel_handle_) != STATUS_OK)
	{
		AddData(_T("复位失败!"));
		return;
	}
	ctrl_start_can_.EnableWindow(TRUE);
	start_ = FALSE;
}

void CZlgcanDlg::OnBnClickedButtonClose()
{
	// TODO: Add your control notification handler code here
	ZCAN_CloseDevice(device_handle_);
	start_ = FALSE;
	EnableCtrl(FALSE);
	ctrl_start_can_.EnableWindow(TRUE);
	ctrl_int_can_.EnableWindow(TRUE);
	device_opened_ = FALSE;
}

void CZlgcanDlg::OnBnClickedButtonSend()
{
	UpdateData(TRUE);
	if (datas_.IsEmpty())
	{
		AddData(_T("数据为空"));
		return;
	}
	UINT id = _tcstoul(id_, 0, 16);
	string data = Utility::W2AEx(datas_);
	UINT result;//发送的帧数
	if (0 == protocol_index_)//can
	{
		ZCAN_Transmit_Data can_data;
		memset(&can_data, 0, sizeof(can_data));
		can_data.frame.can_id = MAKE_CAN_ID(id, frame_type_index_, 0, 0);
		can_data.frame.can_dlc = Utility::split(can_data.frame.data, CAN_MAX_DLEN, data, ' ', 16);
		can_data.transmit_type = send_type_index_;
		result = ZCAN_Transmit(channel_handle_, &can_data, 1);
	}
	else //canfd
	{
		ZCAN_TransmitFD_Data canfd_data;
		memset(&canfd_data, 0, sizeof(canfd_data));
		canfd_data.frame.can_id = MAKE_CAN_ID(id, frame_type_index_, 0, 0);
		canfd_data.frame.len = Utility::split(canfd_data.frame.data, CANFD_MAX_DLEN, data, ' ', 16);
		canfd_data.transmit_type = send_type_index_;
		result = ZCAN_TransmitFD(channel_handle_, &canfd_data, 1);
	}
	if (result != 1)
	{
		AddData(_T("发送数据失败!"));
	}
	else
	{
		AddData(_T("发送数据成功"));
	}
}

void CZlgcanDlg::InitCombobox( int ctrl_id, int start, int end, int current )
{
	CComboBox* ctrl = static_cast<CComboBox*>(GetDlgItem(ctrl_id));
	ASSERT(ctrl != NULL);
	ctrl->ResetContent();
	CString temp;
	for (int i = start; i < end; ++i)
	{
		temp.Format(_T("%d"), i);
		ctrl->AddString(temp);
	}
	ctrl->SetCurSel(current);
}

void CZlgcanDlg::OnCbnSelchangeComboDevice()
{
	UpdateData(TRUE);
	InitCombobox(IDC_COMBO_CHANNEL_INDEX, 0, kDeviceType[device_type_index_].channel_count, 0);
    UINT type = kDeviceType[device_type_index_].device_type;
    const BOOL cloudDevice = type==ZCAN_CLOUD;
    const BOOL netDevice = type==ZCAN_CANETUDP || type==ZCAN_CANETTCP;
    const BOOL tcpDevice = type==ZCAN_CANETTCP;
    const BOOL usbcanfd = type==ZCAN_USBCANFD_100U ||
        type==ZCAN_USBCANFD_200U || type==ZCAN_USBCANFD_MINI;
    const BOOL pciecanfd = type==ZCAN_PCIE_CANFD_100U ||
        type==ZCAN_PCIE_CANFD_200U || type==ZCAN_PCIE_CANFD_400U;
    const BOOL canfdDevice = usbcanfd || pciecanfd;

    GetDlgItem(IDC_COMBO_DEVICE_INDEX2)->EnableWindow(!cloudDevice && !netDevice);
    GetDlgItem(IDC_CHECK_RESISTANCE)->EnableWindow(usbcanfd);
    GetDlgItem(IDC_COMBO_BAUD)->EnableWindow(!canfdDevice && !netDevice && !cloudDevice);
    GetDlgItem(IDC_COMBO_ABIT)->EnableWindow(canfdDevice);
    GetDlgItem(IDC_COMBO_ABIT2)->EnableWindow(canfdDevice);
    GetDlgItem(IDC_CHECK_CUSTOM_BAUDRATE)->EnableWindow(!cloudDevice && !netDevice);
    GetDlgItem(IDC_EDIT_CUSTOM_BAUDRATE)->EnableWindow(!cloudDevice && !netDevice);
    GetDlgItem(IDC_COMBO_FILTER_MODE)->EnableWindow(!cloudDevice && !netDevice);
    GetDlgItem(IDC_EDIT_ACC_CODE)->EnableWindow(!cloudDevice && !netDevice);
    GetDlgItem(IDC_EDIT_ACC_MASK)->EnableWindow(!cloudDevice && !netDevice);
    GetDlgItem(IDC_STATIC_WORK_MODE)->EnableWindow(!cloudDevice && !netDevice);
    GetDlgItem(IDC_STATIC_BAUD)->EnableWindow(!canfdDevice && !netDevice && !cloudDevice);
    GetDlgItem(IDC_STATIC_A_BAUDRATE)->EnableWindow(canfdDevice);
    GetDlgItem(IDC_STATIC_D_BAUDRATE)->EnableWindow(canfdDevice);
    GetDlgItem(IDC_STATIC_CUSTOM_BAUDRATE)->EnableWindow(!cloudDevice && !netDevice);
    GetDlgItem(IDC_STATIC_FILTER_MODE)->EnableWindow(!cloudDevice && !netDevice);
    GetDlgItem(IDC_STATIC_ACC_CODE)->EnableWindow(!cloudDevice && !netDevice);
    GetDlgItem(IDC_STATIC_ACC_MASK)->EnableWindow(!cloudDevice && !netDevice);

    GetDlgItem(IDC_STATIC_NET_MODE)->EnableWindow(tcpDevice);
    GetDlgItem(IDC_COMBO_NET_MODE)->EnableWindow(tcpDevice);
    OnCbnSelchangeComboNetMode();
}

void CZlgcanDlg::OnCbnSelchangeComboNetMode()
{
	UpdateData(TRUE);
    UINT type = kDeviceType[device_type_index_].device_type;
    BOOL tcpDevice = type==ZCAN_CANETTCP;
    BOOL udpDevice = type==ZCAN_CANETUDP;
    if (tcpDevice)
    {
        const BOOL server = net_mode_index_ == 0;
        GetDlgItem(IDC_STATIC_LOCAL_PORT)->EnableWindow(server);
        GetDlgItem(IDC_STATIC_REMOTE_PORT)->EnableWindow(!server);
        GetDlgItem(IDC_STATIC_REMOTE_ADDR)->EnableWindow(!server);
        GetDlgItem(IDC_EDIT_LOCAL_PORT)->EnableWindow(server);
        GetDlgItem(IDC_EDIT_REMOTE_PORT)->EnableWindow(!server);
        GetDlgItem(IDC_EDIT_REMOTE_ADDR)->EnableWindow(!server);
    } else if (udpDevice)
    {
        GetDlgItem(IDC_STATIC_LOCAL_PORT)->EnableWindow(TRUE);
        GetDlgItem(IDC_STATIC_REMOTE_PORT)->EnableWindow(TRUE);
        GetDlgItem(IDC_STATIC_REMOTE_ADDR)->EnableWindow(TRUE);
        GetDlgItem(IDC_EDIT_LOCAL_PORT)->EnableWindow(TRUE);
        GetDlgItem(IDC_EDIT_REMOTE_PORT)->EnableWindow(TRUE);
        GetDlgItem(IDC_EDIT_REMOTE_ADDR)->EnableWindow(TRUE);
    } else
    {
        GetDlgItem(IDC_STATIC_LOCAL_PORT)->EnableWindow(FALSE);
        GetDlgItem(IDC_STATIC_REMOTE_PORT)->EnableWindow(FALSE);
        GetDlgItem(IDC_STATIC_REMOTE_ADDR)->EnableWindow(FALSE);
        GetDlgItem(IDC_EDIT_LOCAL_PORT)->EnableWindow(FALSE);
        GetDlgItem(IDC_EDIT_REMOTE_PORT)->EnableWindow(FALSE);
        GetDlgItem(IDC_EDIT_REMOTE_ADDR)->EnableWindow(FALSE);
    }
}

void CZlgcanDlg::EnableCtrl( BOOL opened )
{
	ctrl_device_type_.EnableWindow(!opened);
	ctrl_device_index_.EnableWindow(!opened);
	ctrl_channel_index_.EnableWindow(!opened);
	ctrl_open_device_.EnableWindow(!opened);
}

//设置自定义波特率, 需要从CANMaster目录下的baudcal生成字符串
BOOL CZlgcanDlg::SetCustomBaudrate()
{
	char path[50] = {0};
	char value[100] = {0};
	string baudrate = Utility::W2AEx(custom_baudrate_);
	sprintf_s(path, "%d/baud_rate_custom", channel_index_);
	sprintf_s(value, "%s", baudrate.data());
	return 1 == property_->SetValue(path, value);
}

UINT WINAPI CZlgcanDlg::OnDataRecv( LPVOID data )
{
	CZlgcanDlg* this_ = static_cast<CZlgcanDlg*>(data);
	if (this_)
	{
		this_->OnRecv();
	}
	return 0;
}

void CZlgcanDlg::OnRecv()
{
	ZCAN_Receive_Data can_data[100];
	ZCAN_ReceiveFD_Data canfd_data[100];
	UINT len;
	while(start_)
	{
		if (len = ZCAN_GetReceiveNum(channel_handle_, TYPE_CAN))
		{
			len = ZCAN_Receive(channel_handle_, can_data, 100, 50);
			AddData(can_data, len);
		}
		if (len = ZCAN_GetReceiveNum(channel_handle_, TYPE_CANFD))
		{
			len = ZCAN_ReceiveFD(channel_handle_, canfd_data, 100, 50);
			AddData(canfd_data, len);
		}
	}
}

void CZlgcanDlg::AddData( const ZCAN_Receive_Data* data, UINT len )
{
	char item[200];
	for (UINT i = 0; i < len; ++i)
	{
		const ZCAN_Receive_Data& can = data[i];
		const canid_t& id = can.frame.can_id;
		sprintf_s(item, "接收到CAN ID:%08X %s %s 长度:%d 数据:", GET_ID(id), IS_EFF(id)?"扩展帧":"标准帧"
			, IS_RTR(id)?"远程帧":"数据帧", can.frame.can_dlc);
		for (UINT i = 0; i < can.frame.can_dlc; ++i)
		{
			size_t item_len = strlen(item);
			sprintf_s(&item[item_len], 200-item_len, "%02X ", can.frame.data[i]);
		}
		AddData(CString(item));
	}
}

void CZlgcanDlg::AddData( const ZCAN_ReceiveFD_Data* data, UINT len )
{
	char item[300];
	for (UINT i = 0; i < len; ++i)
	{
		const ZCAN_ReceiveFD_Data& canfd = data[i];
		const canid_t& id = canfd.frame.can_id;
		sprintf_s(item, "接收到CANFD ID:%08X %s %s 长度:%d 数据:", GET_ID(id), IS_EFF(id)?"扩展帧":"标准帧"
			, IS_RTR(id)?"远程帧":"数据帧", canfd.frame.len);
		for (UINT i = 0; i < canfd.frame.len; ++i)
		{
			size_t item_len = strlen(item);
			sprintf_s(&item[item_len], 300-item_len, "%02X ", canfd.frame.data[i]);
		}
		AddData(CString(item));
	}
}

void CZlgcanDlg::AddData( const CString& data )
{
	data_recv_list_.AddString(data);
	data_recv_list_.SetCurSel(data_recv_list_.GetCount() - 1);
}

void CZlgcanDlg::OnClose()
{
	// TODO: Add your message handler code here and/or call default
    if (ZCLOUD_IsConnected())
    {
        ZCLOUD_DisconnectServer();
    }
	OnBnClickedButtonClose();
	CDialog::OnClose();
}
void CZlgcanDlg::OnBnClickedButtonClear()
{
	data_recv_list_.ResetContent();
}

BOOL CZlgcanDlg::SetTransmitType()
{
	char path[50] = {0};
	char value[100] = {0};
	sprintf_s(path, "%d/send_type", channel_index_);
	sprintf_s(value, "%d", send_type_index_);
	return 1 == property_->SetValue(path, value);
}

//设置终端电阻使能
BOOL CZlgcanDlg::SetResistanceEnable()
{
	char path[50] = {0};
	sprintf_s(path, "%d/initenal_resistance", channel_index_);
	char value[10] = {0};
	sprintf_s(value, "%d", resistance_enable_);
	return 1 == property_->SetValue(path, value);
}

BOOL CZlgcanDlg::SetBaudrate()
{
	char path[50] = {0};
	sprintf_s(path, "%d/baud_rate", channel_index_);
	char value[10] = {0};
	sprintf_s(value, "%d", kBaudrate[baud_index_]);
	return 1 == property_->SetValue(path, value);
}
