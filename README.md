To compile on linux with AVR-GCC and avrdude installed:

1.  Type "make" at the command prompt

2.  Type "make program" at the

The following are set in the MAKEFILE and you may need to change them based on your system:

AVRDUDE_PROGRAMMER = avrispmkII
AVRDUDE_PORT = usb

The above was tested OK on Ubuntu with an AVRISP MKII programmer connected to the serial port.  
I believe this will also work with an arduino used as a programmer.
