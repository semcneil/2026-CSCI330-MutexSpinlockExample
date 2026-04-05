#include <Arduino.h>


void setup() {
  Serial.begin(4800);
  delay(3000);
  Serial.println("Core 1 starting");
}

bool usingSerial = false;
void loop() {
  if(!usingSerial) {
    usingSerial = true;
    if(usingSerial) {
      Serial.println("1");
    }
    usingSerial = false;
  }
}


void setup1() {
  delay(4000);
  Serial.println("Core 2 starting");
}

void loop1() {
  if(!usingSerial) {
    usingSerial = true;
    if(usingSerial) {
      Serial.println("-");
    }
    usingSerial = false;
  }
}