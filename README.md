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
1 | Arduino UNO R3
2 | Wire jumper
3 | Resistor 20KΩ 
4 | Breadboard 

## GUIDE

### STEP 1 : burn the MIDI firmware for Arduino Uno
  we use the great project <a href="https://github.com/kuwatay/mocolufa">mocoLUFA</a> to make Arduino UNO behive as a USB MIDI Driver

### STEP 2 : using the Arduino IDE to update program
  just burning the YKiss.ino to Arduino Uno
  
### STEP 3 : connect the 20PIN to Arduino
  from the <a href="https://github.com/Amehinou/YKiss/blob/master/yamahayk01sm.pdf">yamahayk01sm</a> document we can get the detail of  YK-10's 20PIN interface.
  
  just you see,the keyboard don't have any chips,but a pure matrix keyboard,
