//#include <HCSR04.h>

//UltraSonicDistanceSensor distanceSensor(13, 12);  // Initialize sensor that uses digital pins 13 and 12.
// Arduino pin numbers
const int SW_pin = 4; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output

const int bled = 11;
const int gled = 10;
const int yled = 9;
const int rled = 5;
const int wled = 3;

int distX;

void setup () {
  pinMode(bled, OUTPUT);
  pinMode(gled, OUTPUT);
  pinMode(yled, OUTPUT);
  pinMode(rled, OUTPUT);
  pinMode(wled, OUTPUT);
  pinMode(SW_pin, INPUT_PULLUP);
  Serial.begin(9600);  // We initialize serial connection so that we could print values from sensor.
}

void loop () {
  // Every 500 miliseconds, do a measurement using the sensor and print the distance in centimeters.
  distX = (analogRead(X_pin));
   Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin)); 
  //println = print line and carriage return (next print command happens on new line)
  Serial.print(" | ");
  Serial.print("X-axis: ");
  Serial.print(distX);
  Serial.print(" | ");
  Serial.print("Y-axis: ");
  Serial.print(analogRead(Y_pin));
  Serial.print(" | ");
  Serial.print("\n\n"); // /n is a carriage return. Two puts two empty line spaces between this block and the block in the next loop
  delay(10);
  if (distX > 950) {
    digitalWrite (wled, HIGH);
  } else {
    digitalWrite (wled, LOW);
  }
  if ((distX > 40) && (distX < 70)){
    digitalWrite (rled, HIGH);
  } else {
    digitalWrite (rled, LOW);
  }
  if ((distX > 450) && (distX < 550)){
    digitalWrite (yled, HIGH);
  } else {
    digitalWrite (yled, LOW);
  }
  if ((distX > 200) && (distX < 450)){
    digitalWrite (gled, HIGH);
  } else {
    digitalWrite (gled, LOW);
  }

  if ((distX < 200)){
    digitalWrite (bled, HIGH);
  } else {
    digitalWrite (bled, LOW);
  }
 // Serial.println(distX);
  delay(100);
}
