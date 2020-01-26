#include "Functions.h"
#include "Main.h"

HANDLE StartThread(LPTHREAD_START_ROUTINE ProcName, __drv_aliasesMem LPVOID lpParameter)
{
	HANDLE hProc = CreateThread(NULL, 0, ProcName, lpParameter, 0, NULL);
	if (hProc == NULL)
	{
		ReportErrors(_T("ERROR:ÎÞÐ§µÄ¾ä±ú!"), CONTINUE_REPORT);
		return NULL;
	}
	return hProc;
}