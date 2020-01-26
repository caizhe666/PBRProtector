#include "Main.h"
#include "Functions.h"
#include "MD5.h"

//注册检测 在时间内返回TRUE,否则返回FALSE
BOOL CheckRegister(VOID) {
	ifstream input_RegisterInfo("./Register.inf", ios::in);
	if (!input_RegisterInfo)
	{
		ReportErrors(_T("ERROR:打开注册文件失败!"), SUSPEND_REPORT);
		return 0;
	}
	string strInput;
	getline(input_RegisterInfo, strInput);
	if (strInput == "{HEAD_REGISTER_INFO}")
	{
		getline(input_RegisterInfo, strInput);
		if (strInput == "[BODY_USER_INFO]")
		{
			string UserName;
			string UserPassword;
			string PrivateKey;
			getline(input_RegisterInfo, UserName);
			getline(input_RegisterInfo, UserPassword);
			getline(input_RegisterInfo, PrivateKey);
			string AllString = UserName + UserPassword;
			Md5Encode MD5String;
			string MD5 = MD5String.Encode(AllString);
			if (MD5 == PrivateKey)
			{
				getline(input_RegisterInfo, strInput);
				if (strInput == "[FOOT_REGISTER_INFO]")
				{
					return TRUE;
				}
				else
				{
					return FALSE;
				}
			}
			else
			{
				return FALSE;
			}
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
		return FALSE;
	}
}