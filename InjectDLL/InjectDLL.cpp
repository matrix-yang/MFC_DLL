// InjectDLL.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include "Windows.h"

#define WND_CLASS_NAME "Yuri's Revenge"
#define WND_TITLE "Yuri's Revenge"
#define DllFullPath "F:\\GitHub\\MFC_DLL\\Debug\\MFC_DLL.dll"

void injectDLL(){
	DWORD pid = 0;
	DWORD byteWriteSize = NULL;
	HANDLE processH = NULL;
	LPWORD addr = NULL;
	HANDLE threadH = NULL;
	//��ȡ��Ϸ���ھ�������ݴ����������ͱ���
	//�ɶ�ѡһ��FindWindow(WND_CLASS_NAME, NULL)
	HWND gameH = FindWindow(WND_CLASS_NAME, WND_TITLE);
	if (gameH != 0)
	{
		//���ݴ��ھ����ȡ����PID
		GetWindowThreadProcessId(gameH, &pid);
		if (pid!=0)
		{
			//���ݽ���PID��ȡ���̾��
			processH = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
			if (processH != NULL)
			{
				//����Ϸ���̷����ڴ�ռ�
				addr = (LPWORD)VirtualAllocEx(processH, NULL, 256, MEM_COMMIT, PAGE_READWRITE);
				if (addr!=NULL)
				{
					//д��Dllȫ·����
					WriteProcessMemory(processH, addr, DllFullPath, strlen(DllFullPath) + 1, &byteWriteSize);
					if (byteWriteSize>=strlen(DllFullPath))
					{
						threadH = CreateRemoteThread(processH,NULL,NULL,(LPTHREAD_START_ROUTINE)LoadLibraryA,addr,NULL,NULL);
						WaitForSingleObject(threadH, 0xFFFFFFF);   //�ȴ�ע����߳�ִ����ɣ����ȴ� 0xFFFFFFF����
						//�ͷ���Դ
						CloseHandle(threadH);
						VirtualFreeEx(processH,addr,256,MEM_DECOMMIT);
						CloseHandle(processH);
					}
					else
					{
						printf("ע��dllʧ��");
					}
				}
			}
			else
			{
				printf("�����ڴ�ռ�ʧ��");
			}
		}
		else
		{
			printf("��ȡ����PIDʧ��");
		}
	}else
	{
		printf("��ȡ���ھ��ʧ��");
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	printf("ע�����");
	injectDLL();
	getchar();
	return 0;
}

