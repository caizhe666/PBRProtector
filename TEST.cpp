#include "Main.h"

ThreadFunction(Protector)
{
	unsigned int DiskCount = 0;
	DWORD DiskInfo = GetLogicalDrives(); //获取系统中逻辑驱动器的数量，函数返回的是一个32位无符号整型数据。
	while (DiskInfo)//通过循环操作查看每一位数据是否为1，如果为1则磁盘为真,如果为0则磁盘不存在。
	{
		if (DiskInfo & 1)//通过位运算的逻辑与操作，判断是否为1
		{
			++DiskCount;
		}
		DiskInfo = DiskInfo >> 1;//通过位运算的右移操作保证每循环一次所检查的位置向右移动一位。
	}

	unsigned char MBR[MBR_SIZE]{ 0 };
	DWORD ReadSize = 0;
	HANDLE hDisk = CreateFile((TEXT*)lpParam, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
	SetFilePointer(hDisk, 0, 0, FILE_BEGIN);
	ReadFile(hDisk, MBR, MBR_SIZE, &ReadSize, NULL);

	EOP Size;
	for (unsigned int n = 0; n < 4; n++)
	{
		for (int i = 0; i < 4; i++)
		{
			Size.Part[n].c[i] = MBR[457 + 16 * n - i];
			Size.Part[n].l = HextoDec(Size.Part[n].c, sizeof(Size.Part[n].c));
		}
	}

	wTEXT Volume[MAX_PATH];				//Device
	DWORD Junk;
	wTEXT Path[MAX_PATH];			//C:
	wTEXT FullName[MAX_PATH];
	HANDLE hFind = FindFirstVolume(Volume, MAX_PATH);
	GetVolumePathNamesForVolumeName(Volume, Path, sizeof(Path), &Junk);
	FullName[0] = '\\';
	FullName[1] = '\\';
	FullName[2] = '.';
	FullName[3] = '\\';
	FullName[4] = Temp[0];
	FullName[5] = ':';
	FullName[6] = 0;
}