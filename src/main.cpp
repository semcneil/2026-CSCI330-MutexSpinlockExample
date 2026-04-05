/*
  This tests different methods to signal between cores for using Serial.
  Check out the different branches to see different methods
  This software is in the public domain.
  Use at your own risk. No guarantees that this is done correctly.

  Seth McNeill
  2026 April 05
*/

#include <Arduino.h>

auto_init_mutex(my_mutex);  // Create a mutex lock

void setup() {
  Serial.begin(4800);
  delay(3000);
  Serial.println("Core 1 starting");
}

void loop() {
  mutex_enter_blocking(&my_mutex);  // check out mutex
  // Serial.println("1");
  Serial.println("1111111111111111111111111111111");
  mutex_exit(&my_mutex);  // return mutex
}


void setup1() {
  delay(4000);
  Serial.println("Core 2 starting");
}

void loop1() {
  mutex_enter_blocking(&my_mutex);  // check out mutex
  Serial.println("-------------------------------");
  mutex_exit(&my_mutex); // return mutex
}