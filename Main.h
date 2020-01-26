#pragma once

#include <iostream>
#include <Windows.h>
#include <string>
#include <algorithm>
#include <conio.h>
#include <fstream>
#include <errno.h>
#include <io.h>
#include <istream>
#include <vector>
#include <set>
#include <algorithm>
#include <list>
#include <shellapi.h>
#include <conio.h>
#include <tchar.h>

using namespace std;

typedef BOOL REPORTSTATE;
#ifdef ANSI
typedef const CHAR TEXT;
typedef CHAR wTEXT;
#else
typedef const WCHAR TEXT;
typedef WCHAR wTEXT;
#endif

#define SUSPEND_REPORT (REPORTSTATE)TRUE
#define CONTINUE_REPORT (REPORTSTATE)FALSE

DWORD ReportErrors(TEXT* strErrorText, REPORTSTATE State);

#define ThreadFunction(name) DWORD WINAPI name(LPVOID lpParam)

#define MBR_SIZE 512
#define SECTOR_SIZE 512

typedef struct _PARTITION {
	unsigned char c[4];
	UINT64 l;
}PT, * PPT;

typedef struct _ENDOFPARTITION {
	PT Part[4];
}EOP, * PEOP;

typedef struct _PBR_DATA {
	UINT64 PointerToPBRSector;
	unsigned char PointerToPBRSectorData[SECTOR_SIZE];
	char FullPath[7];
}PBR_DATA, * PPBR_DATA;

typedef struct _PBR {
	PPBR_DATA Datas;

	unsigned int PartitionCount;
	UINT64 StartPBRSector;
}PBR, * PPBR;

unsigned long HextoDec(const unsigned char* hex, int length);