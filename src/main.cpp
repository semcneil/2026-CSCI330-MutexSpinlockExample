#include <Arduino.h>

// This version only prints from core 0 but receives data from core 1
bool core1TextAvailable = false;  // signal (semaphore) that core 1 has text
String core1Text = "";
// things to try
// make these volatile
// wait in core 1 for core1TextAvailable to be false before writing

void setup() {
  Serial.begin(4800);
  delay(3000);
  Serial.println("Core 1 starting");
}

void loop() {
  Serial.println("1");
  Serial.flush();
  if(core1TextAvailable) {
    String c1txt = core1Text;
    core1Text = "";
    core1TextAvailable = false;
    Serial.println(c1txt);
    Serial.flush();
  }
  delay(1);
}


void setup1() {
  delay(4000);
  Serial.println("Core 2 starting");
}

void loop1() {
  core1Text += "-\n";
  core1TextAvailable = true;
  delay(1);
}