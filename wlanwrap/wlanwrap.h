// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� WLANWRAP_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// WLANWRAP_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�

#define WLANWRAP_API extern "C" __declspec(dllexport)

#include <wlanapi.h>

WLANWRAP_API int WlanOpenHandleWrap(PHANDLE phandle);
WLANWRAP_API int WlanCloseHandleWrap(PHANDLE phandle);
WLANWRAP_API PWLAN_INTERFACE_INFO_LIST WlanEnumInterfacesWrap(PHANDLE phandle);
WLANWRAP_API int WlanFreeMemoryWrap(PWLAN_INTERFACE_INFO_LIST memory);
WLANWRAP_API int WlanGetInterfacesCount(PWLAN_INTERFACE_INFO_LIST memory);
WLANWRAP_API int WlanGetInterfaceByIndex(PWLAN_INTERFACE_INFO_LIST list, int index, PWLAN_INTERFACE_INFO pInfo);

