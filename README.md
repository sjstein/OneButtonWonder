# OneButtonWonder
Arduino source code for a simple single-key USB keyboard emulator

I put this together as a simple way of binding a hardware pushbutton which mimics a single keypress (selectable in code) when the button is pressed. My goal was to have a simple way of activating the "push to talk" feature on Discord while riding my indoor bike trainer and playing the game Zwift https://zwift.com/. 

I also designed a 3D mount to attach the Arduino and a pushbutton to my handlebars with a cable-tie.

Hardware manifest:
------------------
Microcontroller : Arduino Pro Micro https://www.sparkfun.com/products/12640
    (this is a nice small form factor Arduino with a USB connector on it and uses the ATmega32U4 so has the USB transceiver built-in,   allowing it to pretend to be a keyboard or mouse with standard Arduino library calls)
Pushbutton : Anything from C&K in the 8020 line (https://www.ckswitches.com/products/switches/product-details/Pushbutton/8020/). 
    Make sure to verify dimensions if you want to fit it in the mount.
Mount : Find a 3D printer, and print out the file located here. Note, for now this is strictly for a 32mm (dia) bar. I will investigate what it would take to make this a modifyable thing in the future if there is enough interest.
