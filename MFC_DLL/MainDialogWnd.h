#pragma once


// CMainDialogWnd �Ի���

class CMainDialogWnd : public CDialogEx
{
	DECLARE_DYNAMIC(CMainDialogWnd)

public:
	CMainDialogWnd(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMainDialogWnd();

// �Ի�������
	enum { IDD = IDD_MAINDIALOGWND };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedtest1();
};
