#pragma once


// CMainDialogWnd 对话框

class CMainDialogWnd : public CDialogEx
{
	DECLARE_DYNAMIC(CMainDialogWnd)

public:
	CMainDialogWnd(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMainDialogWnd();

// 对话框数据
	enum { IDD = IDD_MAINDIALOGWND };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedtest1();
};
