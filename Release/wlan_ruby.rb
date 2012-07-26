require 'ffi'
require 'cstruct/win32struct'
module LibWifi
  extend FFI::Library

  # load library
  ffi_lib "#{File.dirname(__FILE__)}/wlanwrap.dll"
  ffi_convention :stdcall
  
  attach_function :wlan_open_handle, :WlanOpenHandleWrap, [:pointer], :int
  attach_function :wlan_close_handle, :WlanCloseHandleWrap, [:pointer], :int
  attach_function :wlan_enum_interfaces, :WlanEnumInterfacesWrap, [:pointer], :pointer
  attach_function :wlan_free_memory, :WlanFreeMemoryWrap, [:pointer], :int
  attach_function :wlan_count_interfaces, :WlanGetInterfacesCount, [:pointer], :int
  attach_function :wlan_get_interface_by_index, :WlanGetInterfaceByIndex, [:pointer, :int, :pointer], :int
end

class GUID < Win32Struct
  DWORD :data1
  WORD  :data2
  WORD  :data3
  BYTE  :data4,[8]
end
  
class WLAN_INTERFACE_INFO < Win32Struct
   GUID :InterfaceGuid
   WCHAR :strInterfaceDescription,[256]
   int32 :isState
end


phClientHandle = FFI::MemoryPointer.new(:pointer, 1, true)
ret = LibWifi.wlan_open_handle(phClientHandle)

p "HANDLE is ========", phClientHandle
p '='*50


pInterfaceHandle = FFI::MemoryPointer.new(:pointer, 0, true)
pInterfaceHandle = LibWifi.wlan_enum_interfaces(phClientHandle)

p "WLAN_INTERFACE_INFO_LIST is =============", pInterfaceHandle
p '='*50
count = LibWifi.wlan_count_interfaces(pInterfaceHandle)
p "interfaces count == #{count}"

interfaces = count.times.map do |index| 
	info = WLAN_INTERFACE_INFO.new
  LibWifi.wlan_get_interface_by_index(pInterfaceHandle, index, info.data)
	info
end

p interfaces
unless interfaces.empty?
	p interfaces[0].InterfaceGuid.data1
	p interfaces[0].InterfaceGuid.data2
	p interfaces[0].InterfaceGuid.data3
	p interfaces[0].InterfaceGuid.data4
	p interfaces[0].strInterfaceDescription
	p interfaces[0].isState
end

LibWifi.wlan_free_memory(pInterfaceHandle)
ret = LibWifi.wlan_close_handle(phClientHandle)
p "close handle return #{ret}"