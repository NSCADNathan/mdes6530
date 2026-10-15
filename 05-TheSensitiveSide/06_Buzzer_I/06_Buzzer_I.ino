/*
  Buzzer I: active vs. passive

  Two buzzers on the board, one active and one passive. The sketch runs the
  same test on one, then on the other, so you can hear the difference.

  Each buzzer gets:
    1. a plain on/off beep with digitalWrite()
    2. tone() at 1000 Hz, then 400 Hz

  What you should hear:
    ACTIVE buzzer:  a beep for step 1, then the same fixed note for step 2
                    (it ignores the frequency)
    PASSIVE buzzer: only a click for step 1, then two different pitches for step 2

  The circuit:
  - active buzzer + leg to pin 11, - leg to GND
  - passive buzzer + leg to pin 4, - leg to GND

  Theverant, 2026
*/

const int activePin = 11;
const int passivePin = 4;

void setup() {
  pinMode(activePin, OUTPUT);
  pinMode(passivePin, OUTPUT);
}

// Runs the same test on whichever pin you hand it
void testBuzzer(int pin) {
  // 1. just power on and off
  digitalWrite(pin, HIGH);
  delay(300);
  digitalWrite(pin, LOW);
  delay(500);

  // 2. ask for specific frequencies
  tone(pin, 1000);    // 1000 Hz
  delay(400);
  tone(pin, 400);     // 400 Hz
  delay(400);
  noTone(pin);
  delay(500);
}

void loop() {
  testBuzzer(activePin);    // first the active buzzer
  delay(1000);              // gap so you can tell them apart
  testBuzzer(passivePin);   // then the passive one
  delay(2000);
}
