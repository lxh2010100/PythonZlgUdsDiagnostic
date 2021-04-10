
// demoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include <memory>
#include "demo.h"
#include "demoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
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

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()



static uint32 OnUDSTransmitFunc(void* ctx, const ZUDS_FRAME* frame, uint32 count)
{
	CdemoDlg *dlg = static_cast<CdemoDlg*>(ctx);
	return dlg->transmit(frame, count);
}

// CdemoDlg 对话框

CdemoDlg::CdemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CdemoDlg::IDD, pParent)
	, physical_addr_(_T("700"))
	, resp_addr_(_T("701"))
	, functional_addr_(_T("7DF"))
	, is_ext_frame_(FALSE)
	, session_keep_period_(2000)
	, session_keep_enable_(FALSE)
	, p2_timeout_(2000)
	, p2_more_(5000)
	, stmin_(20)
	, bs_(0)
	, fill_byte_(_T("CC"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CdemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_PHYSICAL_ADDR, physical_addr_);
	DDX_Text(pDX, IDC_EDIT_RESP_ADDR, resp_addr_);
	DDX_Text(pDX, IDC_EDIT_FUNC_ADDR, functional_addr_);
	DDX_Check(pDX, IDC_CHECK_EXT, is_ext_frame_);
	DDX_Control(pDX, IDC_COMBO_REQ_ADDR, request_addr_ctrl_);
	DDX_Control(pDX, IDC_COMBO_SESSION_KEEP_ADDR, session_keep_addr_ctrl_);
	DDX_Text(pDX, IDC_EDIT_PERIOD, session_keep_period_);
	DDX_Check(pDX, IDC_CHECK_SESSION_KEEP_ENABLE, session_keep_enable_);
	DDX_Control(pDX, IDC_COMBO_FORMAT, format_ctrl_);
	DDX_Text(pDX, IDC_EDIT_P2, p2_timeout_);
	DDX_Text(pDX, IDC_EDIT_P2_MORE, p2_more_);
	DDX_Text(pDX, IDC_EDIT_STMIN, stmin_);
	DDX_Text(pDX, IDC_EDIT_BS, bs_);
	DDX_Text(pDX, IDC_EDIT_FILL_BYTE, fill_byte_);
}

BEGIN_MESSAGE_MAP(CdemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_START, &CdemoDlg::OnBnClickedButtonStart)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON_STOP, &CdemoDlg::OnBnClickedButtonStop)
END_MESSAGE_MAP()


// CdemoDlg 消息处理程序

BOOL CdemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	request_addr_ctrl_.SetCurSel(0);
	session_keep_addr_ctrl_.SetCurSel(0);
	format_ctrl_.SetCurSel(0);
	uds_handle_ = ZUDS_Init(DoCAN);
	ZUDS_SetTransmitHandler(uds_handle_, this, OnUDSTransmitFunc);
	rx_thread_ = std::thread([this](){
		this->frameReceive();
	});

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CdemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CdemoDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CdemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CdemoDlg::OnBnClickedButtonStart()
{
	if (!device_enable_)
	{
		device_enable_ = openDevice();
		if (!device_enable_)
		{
			MessageBox(_T("打开设备失败"), _T("提示"));
			return;
		}
	}
	UpdateData(TRUE);
    format_version = format_ctrl_.GetCurSel();
	ZUDS_ISO15765_PARAM tp;
	tp.block_size = bs_;
	tp.fill_byte = _tcstoul(fill_byte_, 0, 16);
	tp.st_min = stmin_;
	tp.frame_type = is_ext_frame_;
    tp.version = format_version;
	tp.max_data_len = VERSION_0 == tp.version ? 8 : 64; // 帧数据最长长度
	ZUDS_SetParam(uds_handle_, PARAM_TYPE_ISO15765, &tp);
	ZUDS_SESSION_PARAM sparam;
	sparam.enhanced_timeout = p2_more_;
	sparam.timeout = p2_timeout_;
	ZUDS_SetParam(uds_handle_, PARAM_TYPE_SESSION, &sparam);

	startSessionKeep();

	ZUDS_REQUEST req;
	memset(&req, 0, sizeof(req));
	req.src_addr = _tcstoul(request_addr_ctrl_.GetCurSel() ? functional_addr_ : physical_addr_, 0, 16);
	req.dst_addr = _tcstoul(resp_addr_, 0, 16);
	req.suppress_response = 0;
	req.sid = 0x10; // 服务ID
	req.param_len = 1;
	req.param = new uint8[req.param_len];
	req.param[0] = 0x01;
	ZUDS_RESPONSE resp;
	ZUDS_Request(uds_handle_, &req, &resp);
	delete[] req.param;
	
	CString msg, temp;
	switch (resp.status)
	{
	case ZUDS_ERROR_OK:
		if (RT_POSITIVE == resp.type) // 积极响应
		{
			msg.Format(_T("积极响应: 服务ID:%X, 参数长度:%d, 参数:"), resp.positive.sid, resp.positive.param_len);
			for (uint32 i = 0; i < resp.positive.param_len; ++i)
			{
				temp.Format(_T("%02X "), resp.positive.param[i]);
			    msg.Append(temp);
			}
		}
		else // 消极响应
		{
			msg.Format(_T("消极响应: %02X %02X %02X"), resp.negative.neg_code, resp.negative.sid, resp.negative.error_code);
		}
		break;
	case ZUDS_ERROR_TIMEOUT:
		msg.Format(_T("响应超时"));
		break;
	case ZUDS_ERROR_TRANSPORT:
		msg.Format(_T("发送帧数据失败"));
		break;
	case ZUDS_ERROR_CANCEL:
		msg.Format(_T("请求中止"));
		break;
	case ZUDS_ERROR_SUPPRESS_RESPONSE:
		msg.Format(_T("抑制响应"));
		break;
	default:
		msg.Format(_T("其他错误"));
		break;
	}
	MessageBox(msg, _T("提示"));
}

bool CdemoDlg::openDevice()
{
	device_handle_ = ZCAN_OpenDevice(ZCAN_USBCANFD_200U, 0, 0);
	if (INVALID_DEVICE_HANDLE == device_handle_)
	{
		return false;
	}
	int channel_index{ 0 };
	IProperty *property = GetIProperty(device_handle_);
	char path[50] = {0};
	sprintf_s(path, "%d/canfd_standard", channel_index);
	char value[10] = {0};
	sprintf_s(value, "%d", 0); // 0代表CANFD ISO标准
	property->SetValue(path, value); // 设置canfd标准

	sprintf_s(path, "%d/canfd_abit_baud_rate", channel_index);
	sprintf_s(value, "%d", 500000); // 500kbps波特率
	property->SetValue(path, value); 
	sprintf_s(path, "%d/canfd_dbit_baud_rate", channel_index);
	property->SetValue(path, value); 

	ZCAN_CHANNEL_INIT_CONFIG config;
	memset(&config, 0, sizeof(config));
	config.can_type = TYPE_CANFD;
	config.canfd.mode = 0;
	channel_handle_ = ZCAN_InitCAN(device_handle_, 0, &config);
	if (INVALID_CHANNEL_HANDLE == channel_handle_)
	{
		ZCAN_CloseDevice(device_handle_);
		return false;
	}
	if (ZCAN_StartCAN(channel_handle_) != STATUS_OK)
	{
		ZCAN_CloseDevice(device_handle_);
		return false;
	}
	return true;
}

void CdemoDlg::OnClose()
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	rx_enable_ = false;
	if (rx_thread_.joinable())
	{
		rx_thread_.join();
	}
	if (device_handle_)
	{
		ZCAN_CloseDevice(device_handle_);
	}
	if (uds_handle_ != ZUDS_INVALID_HANDLE)
	{
		ZUDS_Release(uds_handle_);
	}
	CDialogEx::OnClose();
}


void CdemoDlg::OnBnClickedButtonStop()
{
	// TODO:  在此添加控件通知处理程序代码
	if (uds_handle_ != ZUDS_INVALID_HANDLE)
	{
		ZUDS_Stop(uds_handle_);
	}
}

static void UDSFrame2ZCAN(ZCAN_Transmit_Data* can, const ZUDS_FRAME* uds, uint32 count)
{
	for (uint32 i = 0; i < count; ++i)
	{
		auto &can_frm = can[i];
		auto &uds_frm = uds[i];
		memset(&can_frm, 0, sizeof(ZCAN_Transmit_Data));
		can_frm.frame.can_id = MAKE_CAN_ID(uds_frm.id, uds_frm.extend, uds_frm.remote, 0);
		can_frm.frame.can_dlc = uds_frm.data_len;
		memcpy(can_frm.frame.data, uds_frm.data, uds_frm.data_len);
	}
}

static void UDSFrame2ZCANFD(ZCAN_TransmitFD_Data* canfd, const ZUDS_FRAME* uds, uint32 count)
{
	for (uint32 i = 0; i < count; ++i)
	{
		auto &canfd_frm = canfd[i];
		auto &uds_frm = uds[i];
		memset(&canfd_frm, 0, sizeof(ZCAN_TransmitFD_Data));
		canfd_frm.frame.can_id = MAKE_CAN_ID(uds_frm.id, uds_frm.extend, uds_frm.remote, 0);
		canfd_frm.frame.len = uds_frm.data_len;
		memcpy(canfd_frm.frame.data, uds_frm.data, uds_frm.data_len);
	}
}

uint32 CdemoDlg::transmit(const ZUDS_FRAME *frame, uint32 count)
{
    if (VERSION_0 == format_version)
	{
		auto can = new ZCAN_Transmit_Data[count];
		std::unique_ptr<ZCAN_Transmit_Data[]> ptr_release{ can };
		UDSFrame2ZCAN(can, frame, count);
		return count == ZCAN_Transmit(channel_handle_, can, count) ? TRANSPORT_OK : TRANSPORT_ERROR;
	}
	else
	{
		auto canfd = new ZCAN_TransmitFD_Data[count];
		std::unique_ptr<ZCAN_TransmitFD_Data[]> ptr_release{ canfd };
		UDSFrame2ZCANFD(canfd, frame, count);
		return count == ZCAN_TransmitFD(channel_handle_, canfd, count) ? TRANSPORT_OK : TRANSPORT_ERROR;
	}
}

void CdemoDlg::startSessionKeep()
{
	if (session_keep_enable_)
	{
		if (session_keep_running_)
		{
			ZUDS_SetTesterPresent(uds_handle_, 0, nullptr);
		}
		ZUDS_TESTER_PRESENT_PARAM param;
		param.addr = _tcstoul(session_keep_addr_ctrl_.GetCurSel() ? functional_addr_ : physical_addr_, 0, 16);
		param.cycle = session_keep_period_;
		param.suppress_response = 1;
		ZUDS_SetTesterPresent(uds_handle_, 1, &param);
		session_keep_running_ = true;
	}
	else
	{
		if (session_keep_running_)
		{
			ZUDS_SetTesterPresent(uds_handle_, 0, nullptr);
		}
		session_keep_running_ = false;
	}
}

static void ZCAN2UDSFrame(ZUDS_FRAME* uds, const ZCAN_Receive_Data* can)
{
	memset(uds, 0, sizeof(ZUDS_FRAME));
	uds->id = GET_ID(can->frame.can_id);
	uds->extend = IS_EFF(can->frame.can_id);
	uds->remote = IS_RTR(can->frame.can_id);
	uds->data_len = can->frame.can_dlc;
	memcpy(uds->data, can->frame.data, uds->data_len);
}

static void ZCANFD2UDSFrame(ZUDS_FRAME* uds, const ZCAN_ReceiveFD_Data* canfd)
{
	memset(uds, 0, sizeof(ZUDS_FRAME));
	uds->id = GET_ID(canfd->frame.can_id);
	uds->extend = IS_EFF(canfd->frame.can_id);
	uds->remote = IS_RTR(canfd->frame.can_id);
	uds->data_len = canfd->frame.len;
	uds->data_len = uds->data_len > 8 ? 8 : uds->data_len;
	memcpy(uds->data, canfd->frame.data, uds->data_len);
}

void CdemoDlg::frameReceive()
{
	ZUDS_FRAME frame;
	ZCAN_Receive_Data can_data;
	ZCAN_ReceiveFD_Data canfd_data;
	bool hasData{ false };
	while (rx_enable_)
	{
		if (!device_enable_)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(2));
			continue;
		}
		hasData = false;
		if (1 == ZCAN_Receive(channel_handle_, &can_data, 1, 10))
		{
		    hasData = true;
			ZCAN2UDSFrame(&frame, &can_data);
			ZUDS_OnReceive(uds_handle_, &frame);
		}
		if (1 == ZCAN_ReceiveFD(channel_handle_, &canfd_data, 1, 10))
		{
		    hasData = true;
			ZCANFD2UDSFrame(&frame, &canfd_data);
			ZUDS_OnReceive(uds_handle_, &frame);
		}
		if (!hasData)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(2));
		}
	}
}
