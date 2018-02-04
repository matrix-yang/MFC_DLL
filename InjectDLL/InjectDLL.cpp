// InjectDLL.cpp : 定义控制台应用程序的入口点。
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
	//获取游戏窗口句柄，根据窗口类名，和标题
	//可二选一，FindWindow(WND_CLASS_NAME, NULL)
	HWND gameH = FindWindow(WND_CLASS_NAME, WND_TITLE);
	if (gameH != 0)
	{
		//根据窗口句柄获取进程PID
		GetWindowThreadProcessId(gameH, &pid);
		if (pid!=0)
		{
			//根据进程PID获取进程句柄
			processH = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
			if (processH != NULL)
			{
				//在游戏进程分配内存空间
				addr = (LPWORD)VirtualAllocEx(processH, NULL, 256, MEM_COMMIT, PAGE_READWRITE);
				if (addr!=NULL)
				{
					//写入Dll全路径名
					WriteProcessMemory(processH, addr, DllFullPath, strlen(DllFullPath) + 1, &byteWriteSize);
					if (byteWriteSize>=strlen(DllFullPath))
					{
						threadH = CreateRemoteThread(processH,NULL,NULL,(LPTHREAD_START_ROUTINE)LoadLibraryA,addr,NULL,NULL);
						WaitForSingleObject(threadH, 0xFFFFFFF);   //等待注入的线程执行完成，最多等待 0xFFFFFFF毫秒
						//释放资源
						CloseHandle(threadH);
						VirtualFreeEx(processH,addr,256,MEM_DECOMMIT);
						CloseHandle(processH);
					}
					else
					{
						printf("注入dll失败");
					}
				}
			}
			else
			{
				printf("分配内存空间失败");
			}
		}
		else
		{
			printf("获取进程PID失败");
		}
	}else
	{
		printf("获取窗口句柄失败");
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	printf("注入程序");
	injectDLL();
	getchar();
	return 0;
}

