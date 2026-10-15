/*
  Two buttons, two tones

  Button on pin 7 plays a low tone, button on pin 8 plays a high tone.
  Needs the PASSIVE buzzer. An active buzzer ignores the frequency.

  The circuit (same wiring as the Button sketches):
  - passive buzzer + leg to pin 4, - leg to GND
  - pushbutton attached to pin 7 from +5V, 10K resistor from pin 7 to GND
  - pushbutton attached to pin 8 from +5V, 10K resistor from pin 8 to GND

  (The active buzzer on pin 11 stays on the board but isn't used here.)

  Theverant, 2026
*/

const int lowPin = 7;
const int highPin = 8;
const int buzzerPin = 4;

void setup() {
  pinMode(lowPin, INPUT);
  pinMode(highPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  if (digitalRead(lowPin) == HIGH) {
    tone(buzzerPin, 262);      // roughly middle C
  }
  else if (digitalRead(highPin) == HIGH) {
    tone(buzzerPin, 523);      // one octave up
  }
  else {
    noTone(buzzerPin);         // nothing pressed: silence
  }
}
