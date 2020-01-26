#include "Main.h"
#include "Functions.h"

int main()
{
	for (unsigned int i = 0; i < 1; i++)
	{
		cout << i << endl;
		system("pause");
		StartThread(PBRProtector, &i);
	}
	system("pause");
	if (CheckRegister())
	{
	}
	else
	{
		return 0;
	}
}

ThreadFunction(ReportErrors)
{
	MessageBox(NULL, (TEXT*)lpParam, _T("ERROR"), MB_OK | MB_ICONERROR);
	return 0;
}

DWORD ReportErrors(TEXT* strErrorText, const REPORTSTATE State)
{
	if (State == SUSPEND_REPORT)
	{
		MessageBox(NULL, strErrorText, _T("ERROR"), MB_OK | MB_ICONERROR);
	}
	else
	{
		if (State == CONTINUE_REPORT)
		{
			StartThread(ReportErrors, (LPVOID)strErrorText);
		}
		else
		{
			ReportErrors(_T("ERROR:UNKNOWN ERROR!"), CONTINUE_REPORT);
		}
	}
	return GetLastError();
}