/*
  Light sensor to buzzer, raw

  Same idea as pot to buzzer, but with the photoresistor.
  The pitch barely moves. Why? (See the next sketch.)

  The circuit:
  - photoresistor from +5V to A0, 10K resistor from A0 to GND
  - buzzer (passive) + leg to pin 4, - leg to GND

  Theverant, 2026
*/

const int sensorPin = A0;
const int buzzerPin = 4;

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int light = analogRead(sensorPin);
  tone(buzzerPin, light);
}
