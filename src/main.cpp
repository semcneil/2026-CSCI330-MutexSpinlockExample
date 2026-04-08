#include <Arduino.h>

spin_lock_t *lock;  // store lock here

void setup() {
  Serial.begin(4800);
  // Claim a spinlock (0-15)
  uint32_t lock_num = spin_lock_claim_unused(true);
  lock = spin_lock_instance(lock_num);

  delay(3000);
  Serial.println("Core 0 starting");
  Serial.println("Using spinlock #" + String(lock_num));
  delay(5000);
}

void loop() {
  spin_lock_unsafe_blocking(lock);  // does not prevent deadlocks (lock already checked out by this core)
  // Serial.println("1");
  Serial.println("1111111111111111111111111111111");  // starts with more of these since loop starts before loop1 due to delays
  spin_unlock_unsafe(lock);
}


void setup1() {
  delay(10000);
  Serial.println("Core 1 starting");
}

void loop1() {
  spin_lock_unsafe_blocking(lock);  // does not prevent deadlocks (lock already checked out by this core)
  Serial.println("-------------------------------");
  spin_unlock_unsafe(lock);  // release lock
}