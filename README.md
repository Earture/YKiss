# YKiss
convert the Yamaha YK-10/20/01 to a MIDI Keyboard by only using a arduino uno

<p align="center">
  <a href="https://earture.org">
    <img width=50% src="">
  </a> 
</p>
Yamaha YK-10 (YK-01/20) Keyboard is a optional part for the Yamaha CX5M Music Computer which is a great meachine with FM model builed in.but the keyboard only has a 20PIN interface,therefor we can use YKiss to add MIDI interface and making the nice keyboard GREAT AGAIN !

## Material

No | Description 
---|-----------
1 | Arduino UNO R3*
2 | Wire jumper
3 | Resistor 20KΩ 
4 | Breadboard 

 * please don't use the chinese chiper editon of arduino UNO, for the Mega16U2 was replaced by the CH130 usb to serial chip.
## GUIDE

### STEP 1 : burn the MIDI firmware for Arduino Uno
  we use the great project <a href="https://github.com/kuwatay/mocolufa">mocoLUFA</a> to make Arduino UNO behive as a USB MIDI Driver,first you should follow the guide in <a href="http://morecatlab.akiba.coocan.jp/lab/index.php/aruino/midi-firmware-for-arduino-uno-moco/?lang=en">morecat_lab</a> ,Install the dualMocoLUFA firmware to Mega8u2/16U2
  #### download the dualMocoLUFA firmware: <a href="https://github.com/Amehinou/YKiss/blob/master/YKiss/dualMoco.hex">Mega16U2</a>

### STEP 2 : using the Arduino IDE to update program
  just burning the YKiss.ino to Arduino Uno,before connect Uno to PC, don't forget to install a jumper between pin4 and pin6 on ICSP connector for Mega8u2/16U2 when you buring the program. 
  
### STEP 3 : connect the 20PIN to Arduino
  from the <a href="https://github.com/Amehinou/YKiss/blob/master/yamahayk01sm.pdf">yamahayk01sm</a> document we can get the detail of  YK-10's 20PIN interface.

### STEP 4 : enjoy the YK-10 with Ykiss just as a normal midi keyboard !
  don't need MIDI cable*,just use the USB to connet to your PC,of course you should uninstall the jumper between pin4 and pin6 first !
  just you see,the keyboard don't have any chips,but a pure matrix keyboard,
  
 * if you want to use MIDI OUTPUT cable connecting other MIDI Driver,you can make it yourself by using the TX pin
