// wlanwrap.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "wlanwrap.h"
#include <wlanapi.h>
#include <iostream>

WLANWRAP_API int WlanOpenHandleWrap(PHANDLE phandle){
	DWORD dwNegotiatedVersion;
	int ret =  WlanOpenHandle(1, NULL, &dwNegotiatedVersion, phandle);
	//std::cout << ret << " || "<< phandle << " : " << *phandle << std::endl;
	return ret;
}

WLANWRAP_API int WlanCloseHandleWrap(PHANDLE phandle){
	//std::cout << phandle << std::endl;
	return WlanCloseHandle(*phandle, NULL);
}

WLANWRAP_API PWLAN_INTERFACE_INFO_LIST WlanEnumInterfacesWrap(PHANDLE phandle){
	PWLAN_INTERFACE_INFO_LIST pInterfaceList;
	WlanEnumInterfaces(*phandle, NULL, &pInterfaceList);
	//std::cout << pInterfaceList << std::endl;
	return pInterfaceList;
}

WLANWRAP_API int WlanFreeMemoryWrap(PWLAN_INTERFACE_INFO_LIST memory){
	//std::cout << memory << std::endl;
	WlanFreeMemory(memory);
	return 0;
}

WLANWRAP_API int WlanGetInterfacesCount(PWLAN_INTERFACE_INFO_LIST list){
	return list->dwNumberOfItems;
	//return 1;

}

WLANWRAP_API int WlanGetInterfaceByIndex(PWLAN_INTERFACE_INFO_LIST list, int index, PWLAN_INTERFACE_INFO pInfo){
	memcpy(pInfo, &(list->InterfaceInfo[index]), sizeof(WLAN_INTERFACE_INFO));
	/*pInfo->InterfaceGuid.Data1 = 123;
	pInfo->InterfaceGuid.Data2 = 456;
	pInfo->InterfaceGuid.Data3 = 789;
	memset(pInfo->InterfaceGuid.Data4, 2, 8);
	pInfo->isState = WLAN_INTERFACE_STATE::wlan_interface_state_connected;
	memset(pInfo->strInterfaceDescription, 0xE, 256*2);*/
	return 0;
}