/* Fade 2 LEDs independantly

 >> Modified by Theverant. Public domain, feel the love. Changes to original code noted with ʇ

/* Blink without Delay

 Turns on and off a light emitting diode(LED) connected to a digital
 pin, without using the delay() function. This means that other code
 can run at the same time without being interrupted by the LED code.

 The circuit:
 * LED attached from pin 13 to ground.
 ʇ Second LED attached to PMW pin 11
 * Note: on most Arduinos, there is already an LED on the board
 that's attached to pin 13, so no hardware is needed for this example.


 created 2005
 by David A. Mellis
 modified 8 Feb 2010
 by Paul Stoffregen

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay

ʇ additional code stolen from here:
ʇ https://forum.arduino.cc/index.php?topic=12004.msg91552#msg91552

 */

// constants won't change. Used here to
// set pin numbers:
const int ledPin = 13; // the number of the LED pin
const int pwmPin = 11; // ʇ the number of the PMW LED pin
int brightness = 0; // ʇ how bright the LED is


int periode = 2000; // ʇ period of PWM fading in and out

// Variables will change:
int ledState = LOW; // ledState used to set the LED

long previousMillis = 0; // will store last time LED was updated

// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long interval = 1000; // interval at which to blink (milliseconds)
long pwmTime = 0; // ʇ pwm timer
int value; // ʇ holder value for pwm value

void setup() {
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
  pinMode(pwmPin, OUTPUT); // ʇ added pin
}

void loop()
{


 analogWrite(pwmPin, 255); // sets the value (range from 0 to 255)

  }