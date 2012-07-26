require 'ffi'
require 'cstruct/win32struct'
module LibWifi
  extend FFI::Library

  # load library
  ffi_lib 'D:\src9\wlanwrap\Debug\wlanwrap.dll'
  
  attach_function :wlan_open_handle, :WlanOpenHandle, [], :pointer
  
end

handle = LibWifiBak.wlan_open_handle()
printf "\nwlan_open_handle handle=%d\n", handle