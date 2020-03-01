//
//
//        YKiss - convert the Yamaha YK-10 to a MIDI Keyboard
//                         h@Earture.org          
//

// Pin Definitions
const char cn_OUTPUT[] = {2,3,4,5,6,7,8,9,10};
const char cn_INPUT[] = {A0,A1,A2,A3,A4,A5};

uint8_t keyToMidiMap[49];

boolean keyPressed[49];

int noteVelocity = 127;

void setPinHigh(int value) {
  digitalWrite(value,HIGH);
  //delay(100);
}

void setPinLow(int value) {
  digitalWrite(value,LOW);
}

void setup() {
  
  // Map scan matrix buttons/keys to actual Midi note number. Lowest num 36 corresponds to C MIDI note.
  keyToMidiMap[0] = 36;
  
  keyToMidiMap[1] = 42;
  keyToMidiMap[2] = 41;
  keyToMidiMap[3] = 40;
  keyToMidiMap[4] = 39;
  keyToMidiMap[5] = 38;
  keyToMidiMap[6] = 37;
  
  keyToMidiMap[7] = 48;
  keyToMidiMap[1 + 7] = 47;
  keyToMidiMap[2 + 7] = 46;
  keyToMidiMap[3 + 7] = 45;
  keyToMidiMap[4 + 7] = 44;
  keyToMidiMap[5 + 7] = 43;
 
  keyToMidiMap[13] = 54;
  keyToMidiMap[1 + 13] = 53;
  keyToMidiMap[2 + 13] = 52;
  keyToMidiMap[3 + 13] = 51;
  keyToMidiMap[4 + 13] = 50;
  keyToMidiMap[5 + 13] = 49;
  
  keyToMidiMap[19] = 60;
  keyToMidiMap[1 + 19] = 59;
  keyToMidiMap[2 + 19] = 58;
  keyToMidiMap[3 + 19] = 57;
  keyToMidiMap[4 + 19] = 56;
  keyToMidiMap[5 + 19] = 55;

  keyToMidiMap[25] = 66;
  keyToMidiMap[1 + 25] = 65;
  keyToMidiMap[2 + 25] = 64;
  keyToMidiMap[3 + 25] = 63;
  keyToMidiMap[4 + 25] = 62;
  keyToMidiMap[5 + 25] = 61;

  keyToMidiMap[31] = 72;
  keyToMidiMap[1 + 31] = 71;
  keyToMidiMap[2 + 31] = 70;
  keyToMidiMap[3 + 31] = 69;
  keyToMidiMap[4 + 31] = 68;
  keyToMidiMap[5 + 31] = 67;

  keyToMidiMap[37] = 78;
  keyToMidiMap[1 + 37] = 77;
  keyToMidiMap[2 + 37] = 76;
  keyToMidiMap[3 + 37] = 75;
  keyToMidiMap[4 + 37] = 74;
  keyToMidiMap[5 + 37] = 73;

  keyToMidiMap[43] = 84;
  keyToMidiMap[1 + 43] = 83;
  keyToMidiMap[2 + 43] = 82;
  keyToMidiMap[3 + 43] = 81;
  keyToMidiMap[4 + 43] = 80;
  keyToMidiMap[5 + 43] = 79;


  for (int n = 0; n< 9; n += 1){
      pinMode(cn_OUTPUT[n], INPUT);
    }

  for (int n = 0; n< 6; n += 1){
      pinMode(cn_INPUT[n], OUTPUT);
    }

   //digitalWrite(A0,HIGH);

  

  Serial.begin(31250);
  delay(1000);

}

void loop() {

  for (int col = 0; col < 6; col++) {
    
    // shift scan matrix to following column
    setPinHigh(cn_INPUT[col]);

    // check if any keys were pressed - rows will have HIGH output in this case corresponding
    int groupValue0 = digitalRead(cn_OUTPUT[0]);
    int groupValue1 = digitalRead(cn_OUTPUT[1]);
    int groupValue2 = digitalRead(cn_OUTPUT[2]);
    int groupValue3 = digitalRead(cn_OUTPUT[3]);
    int groupValue4 = digitalRead(cn_OUTPUT[4]);
    int groupValue5 = digitalRead(cn_OUTPUT[5]);
    int groupValue6 = digitalRead(cn_OUTPUT[6]);
    int groupValue7 = digitalRead(cn_OUTPUT[7]);
    int groupValue8 = digitalRead(cn_OUTPUT[8]);
    
  

    // process if any combination of keys pressed
    if (groupValue0 != 0 || groupValue1 != 0 || groupValue2 != 0 || groupValue3 != 0
        || groupValue4 != 0 || groupValue5 != 0 || groupValue6 != 0
         || groupValue7 != 0 || groupValue8 != 0 
        ) {

      if (groupValue0 != 0 && !keyPressed[0]) {
        keyPressed[0] = true;
        noteOn(0x91, keyToMidiMap[0], noteVelocity);
      }
      
      if (groupValue1 != 0 && !keyPressed[col+1]) {
        keyPressed[col+1] = true;
        noteOn(0x91, keyToMidiMap[col + 1], noteVelocity);
      }

      if (groupValue2 != 0 && !keyPressed[col + 7]) {
        keyPressed[col + 7] = true;
        noteOn(0x91, keyToMidiMap[col + 7], noteVelocity);
      }

      if (groupValue3 != 0 && !keyPressed[col + 13]) {
        keyPressed[col + 13] = true;
        noteOn(0x91, keyToMidiMap[col + 13], noteVelocity);
      }

      if (groupValue4 != 0 && !keyPressed[col + 19]) {
        keyPressed[col + 19] = true;
        noteOn(0x91, keyToMidiMap[col + 19], noteVelocity);
      }

      if (groupValue5 != 0 && !keyPressed[col + 25]) {
        keyPressed[col + 25] = true;
        noteOn(0x91, keyToMidiMap[col + 25], noteVelocity);
      }

      if (groupValue6 != 0 && !keyPressed[col + 31]) {
        keyPressed[col + 31] = true;
        noteOn(0x91, keyToMidiMap[col + 31], noteVelocity);
      }

      if (groupValue7 != 0 && !keyPressed[col + 37]) {
        keyPressed[col + 37] = true;
        noteOn(0x91, keyToMidiMap[col + 37], noteVelocity);
      }

      if (groupValue8 != 0 && !keyPressed[col + 43]) {
        keyPressed[col + 43] = true;
        noteOn(0x91, keyToMidiMap[col + 43], noteVelocity);
      }

    }

    //  process if any combination of keys released
    if (groupValue0 == 0 && keyPressed[0]) {
      keyPressed[0] = false;
      noteOn(0x91, keyToMidiMap[0], 0);
    }
    
    if (groupValue1 == 0 && keyPressed[col + 1]) {
      keyPressed[col + 1] = false;
      noteOn(0x91, keyToMidiMap[col + 1], 0);
    }

    if (groupValue2 == 0 && keyPressed[col + 7]) {
      keyPressed[col + 7] = false;
      noteOn(0x91, keyToMidiMap[col + 7], 0);
    }

    if (groupValue3 == 0 && keyPressed[col + 13]) {
      keyPressed[col + 13] = false;
      noteOn(0x91, keyToMidiMap[col + 13], 0);
    }

    if (groupValue4 == 0 && keyPressed[col + 19]) {
      keyPressed[col + 19] = false;
      noteOn(0x91, keyToMidiMap[col + 19], 0);
    }

    if (groupValue5 == 0 && keyPressed[col + 25]) {
      keyPressed[col + 25] = false;
      noteOn(0x91, keyToMidiMap[col + 25], 0);
    }

    if (groupValue6 == 0 && keyPressed[col + 31]) {
      keyPressed[col + 31] = false;
      noteOn(0x91, keyToMidiMap[col + 31], 0);
    }

    if (groupValue7 == 0 && keyPressed[col + 37]) {
      keyPressed[col + 37] = false;
      noteOn(0x91, keyToMidiMap[col + 37], 0);
    }

    if (groupValue8 == 0 && keyPressed[col + 43]) {
      keyPressed[col + 43] = false;
      noteOn(0x91, keyToMidiMap[col + 43], 0);
    }

    setPinLow(cn_INPUT[col]);

  }

}


void noteOn(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}
