// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 WLANWRAP_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// WLANWRAP_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。

#define WLANWRAP_API extern "C" __declspec(dllexport)

#include <wlanapi.h>

WLANWRAP_API int WlanOpenHandleWrap(PHANDLE phandle);
WLANWRAP_API int WlanCloseHandleWrap(PHANDLE phandle);
WLANWRAP_API PWLAN_INTERFACE_INFO_LIST WlanEnumInterfacesWrap(PHANDLE phandle);
WLANWRAP_API int WlanFreeMemoryWrap(PWLAN_INTERFACE_INFO_LIST memory);
WLANWRAP_API int WlanGetInterfacesCount(PWLAN_INTERFACE_INFO_LIST memory);
WLANWRAP_API int WlanGetInterfaceByIndex(PWLAN_INTERFACE_INFO_LIST list, int index, PWLAN_INTERFACE_INFO pInfo);

