/*
  Light sensor to buzzer, with the serial monitor and map()

  1. Open Tools > Serial Monitor (set to 9600 baud) or Serial Plotter.
  2. Cover the sensor, then shine a light on it. Note the lowest and highest numbers.
  3. Put those into sensorMin and sensorMax below.
  4. map() stretches that real range across the pitches you want.

  The circuit:
  - photoresistor from +5V to A0, 10K resistor from A0 to GND
  - buzzer (passive) + leg to pin 4, - leg to GND
  - LED attached from pin 6 to ground through 220 ohm resistor

  Theverant, 2026
*/

const int sensorPin = A0;
const int buzzerPin = 4;
const int ledPin = 6;

// Replace with the numbers you saw in the serial monitor
int sensorMin = 200;
int sensorMax = 800;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);          // must match the baud rate in the serial monitor
}

void loop() {
  int light = analogRead(sensorPin);

  // map(value, fromLow, fromHigh, toLow, toHigh)
  int pitch = map(light, sensorMin, sensorMax, 100, 1000);
  pitch = constrain(pitch, 100, 1000);   // map() doesn't clamp, so keep it in range

  tone(buzzerPin, pitch);
  analogWrite(ledPin, map(pitch, 100, 1000, 0, 255));   // same value, scaled for the LED

  Serial.println(light);       // println prints each reading on its own line
  delay(100);                  // slow it down so the numbers are readable
}
