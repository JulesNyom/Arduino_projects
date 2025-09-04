int red_led = 11;
int yellow_led = 10;
int green_led = 9;
int buttonPin = 2;
int buttonState;

void setup()
{
  pinMode(buttonPin, INPUT);
  pinMode(red_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  pinMode(green_led, OUTPUT);
}

void loop()
{
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed
  if (buttonState == HIGH) {
    // Emergency mode: go directly to yellow, then green
    analogWrite(red_led, 0);
    analogWrite(yellow_led, 255);
    delay(3000);
    analogWrite(yellow_led, 0);
    analogWrite(green_led, 255);
    delay(10000); // Green light stays on for 10 seconds
    
    // Return to normal cycle
    analogWrite(green_led, 0);
    analogWrite(yellow_led, 255);
    delay(3000);
    analogWrite(yellow_led, 0);
  } else {
    // Normal traffic light cycle
    analogWrite(red_led, 255);
    analogWrite(yellow_led, 0);
    analogWrite(green_led, 0);
    delay(7000);
    
    analogWrite(red_led, 0);
    analogWrite(yellow_led, 255);
    delay(3000);
    
    analogWrite(yellow_led, 0);
    analogWrite(green_led, 255);
    delay(10000);
    
    analogWrite(green_led, 0);
    analogWrite(yellow_led, 255);
    delay(3000);
  }
}