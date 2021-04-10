
// zlgcanDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "zlgcan/zlgcan.h"

// Cusbcanfdx00udemoDlg 对话框
class CZlgcanDlg : public CDialog
{
// 构造
public:
	CZlgcanDlg(CWnd* pParent = NULL);	// 标准构造函数
// 对话框数据
	enum { IDD = IDD_ZLGCANDEMO_DIALOG };
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	void OnRecv();
// 实现
protected:
	HICON m_hIcon;
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	afx_msg void OnCbnSelchangeComboDevice();
	afx_msg void OnCbnSelchangeComboNetMode();
	afx_msg void OnBnClickedButtonOpen();
	afx_msg void OnBnClickedButtonInitcan();
	afx_msg void OnBnClickedButtonStartcan();
	afx_msg void OnBnClickedButtonReset();
	afx_msg void OnBnClickedButtonClose();
	afx_msg void OnBnClickedButtonSend();
	afx_msg void OnBnClickedButtonClear();
	DECLARE_MESSAGE_MAP()
private:
	void InitCombobox(int ctrl_id, int start, int end, int current);
	void EnableCtrl(BOOL opened);
	BOOL SetCustomBaudrate();
	BOOL SetTransmitType();
    BOOL SetResistanceEnable();
    BOOL SetBaudrate();
	static UINT WINAPI OnDataRecv(LPVOID data);
	void AddData(const ZCAN_Receive_Data* data, UINT len);
	void AddData(const ZCAN_ReceiveFD_Data* data, UINT len);
	void AddData(const CString& data);
private:
	int device_type_index_;
	int device_index_;
	int channel_index_;
	int work_mode_index_;
	int baud_index_;
	int abit_baud_index_;
	int dbit_baud_index_;
	BOOL custom_baud_enable_;
    BOOL resistance_enable_;
	int frame_type_index_;
	int protocol_index_;
	int canfd_exp_index_;
	int send_type_index_;
    int net_mode_index_;
	CListBox data_recv_list_;
	CString acc_code_;
	CString acc_mask_;
	CString id_;
	CString datas_;
	CString custom_baudrate_;
	CComboBox ctrl_device_type_;
	CComboBox ctrl_device_index_;
	CComboBox ctrl_channel_index_;
	DEVICE_HANDLE device_handle_;
	CHANNEL_HANDLE channel_handle_;
	IProperty* property_;
	BOOL start_;
	CButton ctrl_open_device_;
	CButton ctrl_int_can_;
	CButton ctrl_start_can_;
	CButton ctrl_close_device_;
	BOOL device_opened_;
	int filter_mode_;
};
