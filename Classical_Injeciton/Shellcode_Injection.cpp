#include <windows.h>
#include <iostream>
#include <tlhelp32.h>
using namespace std;
// x86 shellcode
UCHAR shellcode[] = { 0x55,  0x8B,  0xEC,  0x83,  0xEC,  0x5C,  0x53,  0x56,  0x57,  0xE8,  0x72,  0x01,  0x00,  0x00,  0x8B,  0xD0,  0x33,  0xDB,  0x8B,  0x42,  0x3C,  0x39,  0x5C,  0x10,  0x7C,  0x0F,  0x84,  0x9F,  0x00,  0x00,  0x00,  0x8B,  0x74,  0x10,  0x78,  0x85,  0xF6,  0x0F,  0x84,  0x93,  0x00,  0x00,  0x00,  0x8B,  0x44,  0x16,  0x24,  0x33,  0xC9,  0x8B,  0x7C,  0x16,  0x20,  0x03,  0xC2,  0x89,  0x45,  0xFC,  0x03,  0xFA,  0x8B,  0x44,  0x16,  0x1C,  0x8B,  0x74,  0x16,  0x18,  0x03,  0xC2,  0x89,  0x45,  0xF8,  0x4E,  0x66,  0x0F,  0x1F,  0x44,  0x00,  0x00,  0x8B,  0x04,  0x8F,  0x03,  0xC2,  0x80,  0x38,  0x47,  0x75,  0x4E,  0x80,  0x78,  0x01,  0x65,  0x75,  0x48,  0x80,  0x78,  0x02,  0x74,  0x75,  0x42,  0x80,  0x78,  0x03,  0x50,  0x75,  0x3C,  0x80,  0x78,  0x04,  0x72,  0x75,  0x36,  0x80,  0x78,  0x05,  0x6F,  0x75,  0x30,  0x80,  0x78,  0x06,  0x63,  0x75,  0x2A,  0x80,  0x78,  0x07,  0x41,  0x75,  0x24,  0x80,  0x78,  0x08,  0x64,  0x75,  0x1E,  0x80,  0x78,  0x09,  0x64,  0x75,  0x18,  0x80,  0x78,  0x0A,  0x72,  0x75,  0x12,  0x80,  0x78,  0x0B,  0x65,  0x75,  0x0C,  0x80,  0x78,  0x0C,  0x73,  0x75,  0x06,  0x80,  0x78,  0x0D,  0x73,  0x74,  0x07,  0x41,  0x3B,  0xCE,  0x76,  0xA3,  0xEB,  0x0F,  0x8B,  0x45,  0xFC,  0x8B,  0x5D,  0xF8,  0x0F,  0xB7,  0x04,  0x48,  0x8B,  0x1C,  0x83,  0x03,  0xDA,  0x8D,  0x45,  0xD0,  0xC7,  0x45,  0xD0,  0x4C,  0x6F,  0x61,  0x64,  0x50,  0xC7,  0x45,  0xD4,  0x4C,  0x69,  0x62,  0x72,  0xC7,  0x45,  0xD8,  0x61,  0x72,  0x79,  0x57,  0xC6,  0x45,  0xDC,  0x00,  0xE8,  0xA0,  0x00,  0x00,  0x00,  0x50,  0xFF,  0xD3,  0x33,  0xC9,  0xC7,  0x45,  0xA4,  0x75,  0x00,  0x73,  0x00,  0x66,  0x89,  0x4D,  0xB8,  0x8D,  0x4D,  0xE0,  0x51,  0x8D,  0x4D,  0xA4,  0xC7,  0x45,  0xA8,  0x65,  0x00,  0x72,  0x00,  0x51,  0xC7,  0x45,  0xAC,  0x33,  0x00,  0x32,  0x00,  0xC7,  0x45,  0xB0,  0x2E,  0x00,  0x64,  0x00,  0xC7,  0x45,  0xB4,  0x6C,  0x00,  0x6C,  0x00,  0xC7,  0x45,  0xE0,  0x4D,  0x65,  0x73,  0x73,  0xC7,  0x45,  0xE4,  0x61,  0x67,  0x65,  0x42,  0xC7,  0x45,  0xE8,  0x6F,  0x78,  0x57,  0x00,  0xFF,  0xD0,  0x50,  0xFF,  0xD3,  0x33,  0xC9,  0xC7,  0x45,  0xBC,  0x53,  0x00,  0x68,  0x00,  0x51,  0x66,  0x89,  0x4D,  0xF4,  0x8D,  0x4D,  0xEC,  0x51,  0x8D,  0x4D,  0xBC,  0xC7,  0x45,  0xC0,  0x65,  0x00,  0x6C,  0x00,  0x51,  0x6A,  0x00,  0xC7,  0x45,  0xC4,  0x6C,  0x00,  0x63,  0x00,  0xC7,  0x45,  0xC8,  0x6F,  0x00,  0x64,  0x00,  0xC7,  0x45,  0xCC,  0x65,  0x00,  0x00,  0x00,  0xC7,  0x45,  0xEC,  0x4C,  0x00,  0x59,  0x00,  0xC7,  0x45,  0xF0,  0x53,  0x00,  0x4D,  0x00,  0xFF,  0xD0,  0x5F,  0x5E,  0x33,  0xC0,  0x5B,  0x8B,  0xE5,  0x5D,  0xC3,  0xCC,  0xCC,  0xCC,  0xCC,  0xCC,  0x64,  0xA1,  0x30,  0x00,  0x00,  0x00,  0x8B,  0x40,  0x0C,  0x8B,  0x40,  0x14,  0x8B,  0x00,  0x8B,  0x00,  0x8B,  0x40,  0x10,  0xC3,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00 };
// x64 shellcode
/*UCHAR shellcode[] = { 0x48,  0x89,  0x5C,  0x24,  0x08,  0x48,  0x89,  0x74,  0x24,  0x10,  0x48,  0x89,  0x7C,  0x24,  0x18,  0x55,  0x41,  0x56,  0x41,  0x57,  0x48,  0x8B,  0xEC,  0x48,  0x81,  0xEC,  0x80,  0x00,  0x00,  0x00,  0xE8,  0x9D,  0x01,  0x00,  0x00,  0x4C,  0x8B,  0xC0,  0x33,  0xDB,  0x8B,  0xFB,  0x48,  0x63,  0x40,  0x3C,  0x42,  0x39,  0x9C,  0x00,  0x8C,  0x00,  0x00,  0x00,  0x0F,  0x84,  0xA7,  0x00,  0x00,  0x00,  0x42,  0x8B,  0x8C,  0x00,  0x88,  0x00,  0x00,  0x00,  0x85,  0xC9,  0x0F,  0x84,  0x97,  0x00,  0x00,  0x00,  0x45,  0x8B,  0x54,  0x08,  0x24,  0x49,  0x8D,  0x04,  0x08,  0x41,  0x8B,  0x4C,  0x08,  0x20,  0x4D,  0x03,  0xD0,  0x44,  0x8B,  0x58,  0x1C,  0x49,  0x03,  0xC8,  0x44,  0x8B,  0x48,  0x18,  0x4D,  0x03,  0xD8,  0x41,  0xFF,  0xC9,  0x8B,  0xD3,  0x8B,  0x01,  0x49,  0x03,  0xC0,  0x80,  0x38,  0x47,  0x75,  0x4E,  0x80,  0x78,  0x01,  0x65,  0x75,  0x48,  0x80,  0x78,  0x02,  0x74,  0x75,  0x42,  0x80,  0x78,  0x03,  0x50,  0x75,  0x3C,  0x80,  0x78,  0x04,  0x72,  0x75,  0x36,  0x80,  0x78,  0x05,  0x6F,  0x75,  0x30,  0x80,  0x78,  0x06,  0x63,  0x75,  0x2A,  0x80,  0x78,  0x07,  0x41,  0x75,  0x24,  0x80,  0x78,  0x08,  0x64,  0x75,  0x1E,  0x80,  0x78,  0x09,  0x64,  0x75,  0x18,  0x80,  0x78,  0x0A,  0x72,  0x75,  0x12,  0x80,  0x78,  0x0B,  0x65,  0x75,  0x0C,  0x80,  0x78,  0x0C,  0x73,  0x75,  0x06,  0x80,  0x78,  0x0D,  0x73,  0x74,  0x0D,  0xFF,  0xC2,  0x48,  0x83,  0xC1,  0x04,  0x41,  0x3B,  0xD1,  0x76,  0x9D,  0xEB,  0x0E,  0x8B,  0xC2,  0x41,  0x0F,  0xB7,  0x0C,  0x42,  0x41,  0x8B,  0x3C,  0x8B,  0x49,  0x03,  0xF8,  0xC7,  0x45,  0xC0,  0x4C,  0x6F,  0x61,  0x64,  0xC7,  0x45,  0xC4,  0x4C,  0x69,  0x62,  0x72,  0xC7,  0x45,  0xC8,  0x61,  0x72,  0x79,  0x57,  0xC6,  0x45,  0xCC,  0x00,  0xE8,  0xBF,  0x00,  0x00,  0x00,  0x48,  0x8B,  0xC8,  0x48,  0x8D,  0x55,  0xC0,  0xFF,  0xD7,  0x48,  0x8D,  0x4D,  0xE8,  0xC7,  0x45,  0xE8,  0x75,  0x00,  0x73,  0x00,  0xC7,  0x45,  0xEC,  0x65,  0x00,  0x72,  0x00,  0xC7,  0x45,  0xF0,  0x33,  0x00,  0x32,  0x00,  0xC7,  0x45,  0xF4,  0x2E,  0x00,  0x64,  0x00,  0xC7,  0x45,  0xF8,  0x6C,  0x00,  0x6C,  0x00,  0x66,  0x89,  0x5D,  0xFC,  0xC7,  0x45,  0xB0,  0x4D,  0x65,  0x73,  0x73,  0xC7,  0x45,  0xB4,  0x61,  0x67,  0x65,  0x42,  0xC7,  0x45,  0xB8,  0x6F,  0x78,  0x57,  0x00,  0xFF,  0xD0,  0x48,  0x8B,  0xC8,  0x48,  0x8D,  0x55,  0xB0,  0xFF,  0xD7,  0x45,  0x33,  0xC9,  0xC7,  0x45,  0xD0,  0x53,  0x00,  0x68,  0x00,  0x4C,  0x8D,  0x45,  0xA0,  0xC7,  0x45,  0xD4,  0x65,  0x00,  0x6C,  0x00,  0x48,  0x8D,  0x55,  0xD0,  0xC7,  0x45,  0xD8,  0x6C,  0x00,  0x63,  0x00,  0x33,  0xC9,  0xC7,  0x45,  0xDC,  0x6F,  0x00,  0x64,  0x00,  0xC7,  0x45,  0xE0,  0x65,  0x00,  0x00,  0x00,  0xC7,  0x45,  0xA0,  0x4C,  0x00,  0x59,  0x00,  0xC7,  0x45,  0xA4,  0x53,  0x00,  0x4D,  0x00,  0x66,  0x89,  0x5D,  0xA8,  0xFF,  0xD0,  0x4C,  0x8D,  0x9C,  0x24,  0x80,  0x00,  0x00,  0x00,  0x33,  0xC0,  0x49,  0x8B,  0x5B,  0x20,  0x49,  0x8B,  0x73,  0x28,  0x49,  0x8B,  0x7B,  0x30,  0x49,  0x8B,  0xE3,  0x41,  0x5F,  0x41,  0x5E,  0x5D,  0xC3,  0xCC,  0xCC,  0xCC,  0xCC,  0xCC,  0xCC,  0xCC,  0xCC,  0x65,  0x48,  0x8B,  0x04,  0x25,  0x60,  0x00,  0x00,  0x00,  0x48,  0x8B,  0x40,  0x18,  0x48,  0x8B,  0x40,  0x30,  0x48,  0x8B,  0x00,  0x48,  0x8B,  0x00,  0x48,  0x8B,  0x40,  0x10,  0xC3,  0x00,  0x00,  0x00,  0x00};*/
DWORD GetProcessPid(char* Processname);
BOOL InjectShellcode(DWORD Pid);
int main()
{
	char TProcName[] = "HostProc.exe";
	DWORD TProcID = GetProcessPid(TProcName);
	InjectShellcode(TProcID);
	system("pause");
	return 0;
}
DWORD GetProcessPid(char *Processname)
{
	HANDLE hProcessSnap = NULL;   //define snapshot
	DWORD ProcessID = 0;
	PROCESSENTRY32 pe32 = { 0 };
	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);   //create snapshot of all process in system
	pe32.dwSize = sizeof(PROCESSENTRY32);
	if (Process32First(hProcessSnap, &pe32))
	{
		do
		{
			if (!strcmp(Processname, pe32.szExeFile))
			{
				ProcessID = pe32.th32ProcessID;
				break;
			}
		} while (Process32Next(hProcessSnap, &pe32));
	}
	CloseHandle(hProcessSnap);
	return ProcessID;
}
BOOL InjectShellcode(DWORD Pid)
{
	HANDLE hProc = NULL;
	hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, Pid);
	LPVOID AllocMemory = VirtualAllocEx(hProc, NULL, sizeof(shellcode), MEM_COMMIT, PAGE_READWRITE);
	WriteProcessMemory(hProc, AllocMemory, shellcode, sizeof(shellcode), NULL);
	CreateRemoteThread(hProc, NULL, 0, (LPTHREAD_START_ROUTINE)AllocMemory, NULL, 0, NULL);	//问题出在这里, 和注入dll文件的程序入口点在loadlibrary不同, 要设置到shellcode开头.
	return true;
}