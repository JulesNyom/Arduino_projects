#include <LiquidCrystal.h>

// Motor A connections
int enA = 9;
int in1 = 7;
int in2 = 2;

// LCD setup
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Set motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  
  // Set potentiometer pin as input
  pinMode(A0, INPUT);
  
  Serial.begin(9600);
  
  // Set up LCD
  lcd.begin(16, 2);
  lcd.print("Motor Control");
  delay(1000);
  lcd.clear();
}

void loop() {
  // Read potentiometer value and calculate voltage
  int potentioValue = analogRead(A0);
  float voltage = potentioValue * (5.0 / 1023.0);
  
  // RPM calculatio : Assuming max 330 RPM at full voltage, scaled by potentiometer
  float rotationSpeed = voltage * 3306;
  
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.print("V, RPM: ");
  Serial.println(rotationSpeed);
  
  // Update LCD display
  lcd.setCursor(0, 0);
  lcd.print("V:");
  lcd.print(voltage);
  lcd.print("V  RPM:");
  lcd.print(rotationSpeed);
  lcd.print("   ");
  
  lcd.setCursor(0, 1);
  lcd.print("Time:");
  lcd.print(millis()/1000);
  lcd.print("s    ");
  
  // Control motor
  directionControl();
  
  // scroll 13 positions (string length) to the left
  // to move it offscreen left:
  for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(150);
  }

  // scroll 29 positions (string length + display length) to the right
  // to move it offscreen right:
  for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
    // scroll one position right:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(150);
  }

  // scroll 16 positions (display length + string length) to the left
  // to move it back to center:
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(150);
  }

  // delay at the end of the full loop:
  delay(100);
}

void directionControl() {
  // Read current potentiometer value for speed control
  int potentioValue = analogRead(A0);
  int motorSpeed = map(potentioValue, 0, 1023, 0, 255);
  analogWrite(enA, motorSpeed);

  // Turn on motor A clockwise
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  
   // Reverse direction
  // digitalWrite(in1, LOW);
  // digitalWrite(in2, HIGH);
  // delay(3000);
}