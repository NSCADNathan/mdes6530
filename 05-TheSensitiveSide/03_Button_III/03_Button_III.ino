/*
  Button III

  Two buttons, one LED with two modes:
  - Press the RESET button: LED goes solid ON
  - Press the FADE button:  LED pulses in and out (fades up and down repeatedly)

  The circuit:
  - LED attached from pin 11 to ground through 220 ohm resistor
  - pushbutton (reset) attached to pin 8 from +3.3V
  - pushbutton (fade)  attached to pin 7 from +3.3V

  Based on the Button and Fade examples.
  Kludge by Theverant, 2022.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button
*/
// --- PIN NUMBERS ---
// We define all our pin numbers up here so they're easy to find and change.
// "const int" = a whole number that will never change during the program.

const int fadePin  = 8;  // the button that turns the LED ON
const int resetPin = 7;  // the button that turns the LED OFF
const int ledPin = 11;  // the LED output pin

// --- VARIABLES ---
// These all start with some default value but will change as the program runs.

int resetState = HIGH;  // current reading of the reset button (HIGH/LOW)
int fadeState  = LOW;   // current reading of the fade button (HIGH/LOW)
int LEDstate   = 0;     // tracks which MODE the LED is in: HIGH = solid, LOW = fading

int brightness  = 0;    // the LED's current brightness level (0 = off, 255 = full brightness)
int fadeAmount  = 5;    // how much to change brightness each step of the fade
                        // positive = getting brighter, negative = getting dimmer


// =============================================================================
// SETUP — runs ONE TIME when the board powers on
// =============================================================================

void setup() {

  pinMode(ledPin, OUTPUT);
  // This pin sends a signal OUT to the LED.

  pinMode(resetPin, INPUT);
  // This pin LISTENS for the reset button.

  pinMode(fadePin, INPUT);
  // This pin LISTENS for the fade button.
}


// =============================================================================
// LOOP — runs FOREVER, continuously, as long as the board has power
// =============================================================================

void loop() {

  resetState = digitalRead(resetPin);
  // Check: is the reset button being pressed right now?
  // HIGH = yes, LOW = no.

  fadeState = digitalRead(fadePin);
  // Check: is the fade button being pressed right now?


  if (resetState == HIGH) {
    LEDstate = HIGH;
    // Reset button is pressed — switch the LED into SOLID mode.
    // We're just updating the mode flag here. The actual output happens below.
  }
  else {
    if (fadeState == HIGH) {
      LEDstate = LOW;
      // Fade button is pressed — switch the LED into FADING mode.
    }
  }
  // If neither button is pressed, LEDstate stays whatever it was.
  // The LED holds its current mode.


  if (LEDstate == HIGH) {

    digitalWrite(ledPin, HIGH);
    // SOLID mode: just send full electricity to the LED.
    // digitalWrite can only do ON or OFF — no in-between.

  }
  else {
    if (LEDstate == LOW) {

      analogWrite(ledPin, brightness);
      // FADE mode: analogWrite lets you send a PARTIAL amount of electricity.
      // Unlike digitalWrite (which is just ON or OFF), analogWrite takes a number
      // from 0 to 255, where 0 is completely off and 255 is fully on.
      // By changing "brightness" over time, we create a fading effect.

      brightness = brightness + fadeAmount;
      // Each time through the loop, increase brightness by fadeAmount.
      // fadeAmount starts positive (getting brighter), then flips negative (getting dimmer).

      if (brightness <= 0 || brightness >= 255) {
        fadeAmount = -fadeAmount;
        // When brightness hits the bottom (0) or the top (255), reverse direction.
        // If fadeAmount was +5, it becomes -5 (now dimming).
        // If fadeAmount was -5, it becomes +5 (now brightening).
        // This creates the continuous pulse back and forth.
      }

      delay(30);
      // Pause for 30 milliseconds before the next loop.
      // Without this pause, the fade would happen so fast you couldn't see it.
      // delay() takes a number in milliseconds. 1000 = 1 second.

    } // end fade mode
  }

}
