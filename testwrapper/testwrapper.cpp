// testwrapper.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"

#include "wlanwrap.h"


int _tmain(int argc, _TCHAR* argv[])
{
	HANDLE handle;
	WlanOpenHandleWrap(&handle);
	std::cout << handle;
    WLAN_INTERFACE_INFO info;
	//WlanGetInterfaceByIndex(NULL, 0, &info);
	//std::cout << info.InterfaceGuid.Data1;
	getchar();
	return 0;
}
