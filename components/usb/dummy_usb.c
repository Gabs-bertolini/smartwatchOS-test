/* Minimal stub for 'usb' component to satisfy BSP dependency during CMake configure.
   This does not provide USB functionality. If your application needs USB, replace
   this with the proper 'usb' component or remove the stub. */

void __attribute__((weak)) usb_stub(void) {}
