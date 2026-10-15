/*
  Pot to buzzer, with an LED showing the value

  Turning the pot changes the pitch. The LED gets brighter as the pitch goes up.
  The raw analogRead() value (0-1023) is used directly as the frequency in Hz.

  The circuit:
  - pot: outer legs to +5V and GND, MIDDLE leg (wiper) to A1
  - buzzer (passive) + leg to pin 4, - leg to GND
  - LED attached from pin 6 to ground through 220 ohm resistor

  Note: the LED is on pin 6, not 11. tone() uses Timer2, which breaks
  analogWrite() on pins 3 and 11.

  Theverant, 2026
*/

const int potPin = A0;
const int buzzerPin = 4;
const int ledPin = 6;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(potPin);   // 0 to 1023

  tone(buzzerPin, potValue);           // use it as a frequency, no scaling
  analogWrite(ledPin, potValue / 4);   // analogWrite only goes to 255, so divide by 4
  Serial.println (potValue);
}
