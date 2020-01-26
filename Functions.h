#pragma once
#include "Main.h"
#include <ctime>

HANDLE StartThread(LPTHREAD_START_ROUTINE ProcName, __drv_aliasesMem LPVOID lpParameter);
BOOL CheckRegister(VOID);
ThreadFunction(PBRProtector);