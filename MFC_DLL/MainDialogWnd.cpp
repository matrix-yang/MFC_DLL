// MainDialogWnd.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_DLL.h"
#include "MainDialogWnd.h"
#include "afxdialogex.h"


#define MoneyS 0x0B373A6C;
// CMainDialogWnd �Ի���

IMPLEMENT_DYNAMIC(CMainDialogWnd, CDialogEx)

CMainDialogWnd::CMainDialogWnd(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMainDialogWnd::IDD, pParent)
{

}

CMainDialogWnd::~CMainDialogWnd()
{
}

void CMainDialogWnd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMainDialogWnd, CDialogEx)
	ON_BN_CLICKED(test1, &CMainDialogWnd::OnBnClickedtest1)
END_MESSAGE_MAP()


// CMainDialogWnd ��Ϣ�������

void CMainDialogWnd::OnBnClickedtest1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	TRACE("gameinfo:����money=%d", *(int *)0x0B373A6C);
	*(int *)0x0B373A6C = 99999;
	TRACE("gameinfo:����money=%d", *(int *)0x0B373A6C);
}
