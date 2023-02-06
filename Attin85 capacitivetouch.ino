#include <CapacitiveSensor.h>
#define kbd_tr_tr // For turkish keyboard support
#include "DigiKeyboard.h" // 

int capSensePin = 2;
int touchedCutoff = 1000;
CapacitiveSensor   cs_1_2 = CapacitiveSensor(1,2);        // 1M resistor between pins 1 & 2, pin 2 is sensor pin, 

void setup(){
  DigiKeyboard.delay(2500); // For clean setup
  DigiKeyboard.sendKeyStroke(0);  
  cs_1_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
}

void loop(){
 
  // If the capacitive sensor reads above a certain threshold,
  //  Write the key.
 
  long start = millis();
  long sensorValue =  cs_1_2.capacitiveSensor(30);
 
 // Here is optional for reading sensor value. Serial reading is not easy with atting because there is no serail port at default. 
 //Writing values to screen is a easiest solution for me
 //DigiKeyboard.print(sensorValue); 
 //DigiKeyboard.sendKeyStroke(KEY_ENTER);

  if (sensorValue > touchedCutoff) {
    DigiKeyboard.print("KEY"); // WRITES "KEY"
    DigiKeyboard.sendKeyStroke(KEY_ENTER); // PRES ENTER KEY
    DigiKeyboard.delay(1000); // WAIT FOR CLEAN WORK this means you can write your pass with 1 second per.
  }
  DigiKeyboard.delay(100); 
}
