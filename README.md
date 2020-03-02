# 🌊YKiss 
![Build Status](https://github.com/Amehinou/YKiss/workflows/YKiss/badge.svg)

convert the Yamaha YK-10/20/01 🎹 to a MIDI Keyboard by only using a arduino uno

<p align="center">
  <a href="https://raw.githubusercontent.com/Amehinou/YKiss/master/YKiss.jpg">
    <img width=100% src="https://raw.githubusercontent.com/Amehinou/YKiss/master/YKiss.jpg">
  </a> 
</p>
Yamaha YK-10 (YK-01/20) Keyboard is a optional part for the Yamaha CX5M Music Computer which is a great meachine with FM model build in.but the keyboard only has a 20PIN interface,therefor we can use YKiss to add MIDI interface and make the nice keyboard GREAT AGAIN !

## ✏️Material

No | Description 
---|-----------
1 | Arduino UNO R3*
2 | Wire jumper
3 | Resistor 20KΩ 
4 | Breadboard 

 * please don't use the chinese cheaper editon of arduino UNO, for the Mega16U2 was replaced by the CH340 usb to serial chip.
## 🍤GUIDE

### STEP 1 : burn the MIDI firmware for Arduino Uno
  we use the great project <a href="https://github.com/kuwatay/mocolufa">mocoLUFA</a> to make Arduino UNO behaved as a USB MIDI Device,first you should follow the guide in <a href="http://morecatlab.akiba.coocan.jp/lab/index.php/aruino/midi-firmware-for-arduino-uno-moco/?lang=en">morecat_lab</a> ,Installing the dualMocoLUFA firmware to Mega8u2/16U2
  If you have questions about the mocoLUFA documentation, you can also follow the steps below：
  #### 1-1. download the dualMocoLUFA firmware: <a href="https://raw.githubusercontent.com/Amehinou/YKiss/master/YKiss/dualMoco.hex">Mega16U2</a>
  #### 1-2. Updating the Atmega16U2 on an Uno using DFU
  please see the <a href="https://www.arduino.cc/en/Hacking/DFUProgramming8U2">offical doc</a> for how to use DFU to burn firmware

### STEP 2 : using the Arduino IDE to update program
  just burning the YKiss.ino to Arduino Uno,before connecting Uno to PC, don't forget to install <a href="http://morecatlab.akiba.coocan.jp/lab/wp-content/uploads/2013/09/IMGP9378-150x150.jpg">a jumper between pin4 and pin6 on ICSP connector </a>for Mega8u2/16U2 when you buring the program. 
  
### STEP 3 : connect the 20PIN to Arduino
  from the <a href="https://github.com/Amehinou/YKiss/blob/master/yamahayk01sm.pdf">yamahayk01sm</a> document we can get the detail of  YK-10's 20PIN interface.just you see,the keyboard don't have any chips,but a pure matrix keyboard,so it makes things easier！
  
20PIN | UNO
---|-----------
11 to 16 | A0 to A5
2 to 10 | 2 to 10
* please connect 20K Pull-down resistor to all used PIN
<p align="center">
  <a href="https://raw.githubusercontent.com/Amehinou/YKiss/master/connect.jpg">
    <img width=50% src="https://raw.githubusercontent.com/Amehinou/YKiss/master/connect.jpg">
  </a> 
   <a href="https://raw.githubusercontent.com/Amehinou/YKiss/master/20PIN.jpg">
    <img width=50% src="https://raw.githubusercontent.com/Amehinou/YKiss/master/20PIN.jpg">
  </a> 
</p>

### STEP 4 : enjoy the YK-10 with Ykiss just as a normal midi keyboard !
  don't need MIDI cable*,just useing the USB to connet to your PC,of course you should uninstall the jumper between pin4 and pin6 first !
 
 * if you want to use MIDI OUTPUT cable to connect other MIDI Drvice,you can make it yourself by using the TX pin
 
## 👍THANKS
#### <a href="http://www.codetinkerhack.com/2012/11/how-to-turn-piano-toy-into-midi.html?m=1">Code Tinker Hack</a>
#### <a href="https://groups.google.com/forum/#!topic/london-hack-space/lhE5M1SvkMQ">London Hackspaceck</a>
#### <a href="https://github.com/kuwatay/mocolufa">mocoLUFA</a>

## 🙏I'm an 8bit fan，you can contact me ！
my website is <a href="https://earture.org">Earture.org</a>

