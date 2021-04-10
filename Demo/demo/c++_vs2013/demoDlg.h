
// demoDlg.h : 头文件
//

#pragma once
#include <thread>
#include "afxwin.h"
#include "zlgcan.h"
#include "zuds.h"

// CdemoDlg 对话框
class CdemoDlg : public CDialogEx
{
// 构造
public:
	CdemoDlg(CWnd* pParent = NULL);	// 标准构造函数
// 对话框数据
	enum { IDD = IDD_DEMO_DIALOG };
	uint32 transmit(const ZUDS_FRAME *frame, uint32 count);
	void frameReceive();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonStop();
	afx_msg void OnClose();
// 实现
protected:
	HICON m_hIcon;
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	bool openDevice(); // 打开CAN(FD)卡
	void startSessionKeep();
private:
	CString physical_addr_;
	CString resp_addr_;
	CString functional_addr_;
	BOOL is_ext_frame_;
	CComboBox request_addr_ctrl_;
	CComboBox session_keep_addr_ctrl_;
	int session_keep_period_;
	BOOL session_keep_enable_;
	CComboBox format_ctrl_;
    int format_version;
	int p2_timeout_;
	int p2_more_;
	int stmin_;
	int bs_;
	CString fill_byte_;
	bool device_enable_{ false };
	DEVICE_HANDLE device_handle_;
	CHANNEL_HANDLE channel_handle_;
	ZUDS_HANDLE uds_handle_;
	bool session_keep_running_{ false };
	bool rx_enable_{ true };
	std::thread rx_thread_;
};
