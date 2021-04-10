#pragma once
#include "afxcmn.h"
#include "afxwin.h"

#include "resource.h"

// zcloudDlg dialog

class zcloudDlg : public CDialog
{
	DECLARE_DYNAMIC(zcloudDlg)

public:
	zcloudDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~zcloudDlg();

    unsigned GetDeviceIndex() const;

// Dialog Data
	enum { IDD = IDD_DIALOG_CLOUD };

public:
    afx_msg void OnBnClickedButtonConnect();
    afx_msg void OnBnClickedButtonDisconnect();
    afx_msg void OnNMClickListDevice(NMHDR *pNMHDR, LRESULT *pResult);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

    virtual BOOL OnInitDialog();

private:
    CListCtrl m_deviceList;
    CEdit m_httpAddr;
    CEdit m_httpPort;
    CEdit m_mqttAddr;
    CEdit m_mqttPort;
    CEdit m_username;
    CEdit m_password;
    
    CArray<int> m_deviceIndices;
    int m_deviceIndex;
};
