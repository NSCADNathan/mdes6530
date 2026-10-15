/*
  Light sensor to LED (like the Weevil Eye)

  Part A: LED turns on when it gets dark (threshold, on/off)
  Part B: LED brightness follows the light (smooth), see the commented block

  The circuit:
  - photoresistor from +5V to A0, 10K resistor from A0 to GND
    (a voltage divider: brighter light = higher reading)
  - LED attached from pin 6 to ground through 220 ohm resistor

  The threshold below is a guess. Your room may need a different number.

  Theverant, 2026
*/

const int sensorPin = A0;
const int ledPin = 6;
const int threshold = 500;   // darker than this = LED on

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int light = analogRead(sensorPin);

  // Part A: threshold
  if (light < threshold) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }

  // Part B: smooth. Comment out Part A above and uncomment this.
  // Darker = brighter LED, so we flip the value.
  // analogWrite(ledPin, 255 - (light / 4));

  delay(10);
}
