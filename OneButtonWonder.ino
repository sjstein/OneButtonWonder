/* OneButtonWonder 
 *  Author: Josh Stein
 *  Date : 6-Dec-2018
 *  
 *   Program to act like a single-button USB keyboard. When an input pin is pulled low (int buttonPin), the Arduino 
 *   will send a keyPressed message to the USB port. When the input pin is let to float high, the Arduino sends a
 *   keyReleased message. 
 *   
 *   We also utilize the two controllable on-board LEDS to show status.
 */

// Define ASCII values of certain keys 
#define KEY_LEFT_CTRL  0x80
#define KEY_LEFT_SHIFT 0x81
#define KEY_LEFT_ALT   0x82
#define KEY_LEFT_GUI   0x83
#define KEY_RIGHT_CTRL 0x84
#define KEY_RIGHT_SHIFT    0x85
#define KEY_RIGHT_ALT  0x86
#define KEY_RIGHT_GUI  0x87

// Make sure to include this library to have access to USB Keyboard functions.
#include <Keyboard.h> 

int RXLED = 17;  // Receive LED 
int buttonPin = 3;


void setup()
{
 pinMode(RXLED, OUTPUT);  
 pinMode(buttonPin, INPUT);
 digitalWrite(buttonPin, HIGH);         // Pull the button input high 
}

void loop()
{
  while(digitalRead(buttonPin) == 0)    // Is button low (pressed)?
  {
    digitalWrite(RXLED, LOW);           // Turn on rxLED to indicate we see the button press
    Keyboard.press(KEY_LEFT_CTRL);      // Press the required key (USB)
    delay(50);                          // debounce switch input a bit
    if (digitalRead(buttonPin) == 1) {  // Is button high (released)?
      Keyboard.release(KEY_LEFT_CTRL);  // Release key (USB)
      break;                            // Escape out of while loop
    }
  }
 digitalWrite(RXLED, HIGH);              // Turn off the RXLED to indicate we are not seeing button press
}
