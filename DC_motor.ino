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
  lcd.print("Voltage: ");
}

void loop() {
  // Read potentiometer value and calculate voltage
  int potentioValue = analogRead(A0);
  float voltage = potentioValue * (5.0 / 1023.0);
  
  Serial.println(voltage);
  
  // Update LCD display
  lcd.setCursor(0, 0);
  lcd.print("Voltage: ");
  lcd.print(voltage);
  lcd.print("V   ");  // Extra spaces to clear previous values
  
  directionControl();
  delay(3000);
}

void directionControl() {
  // Read current potentiometer value for speed control
  int potentioValue = analogRead(A0);
  int motorSpeed = map(motorSpeed, 0, 1023, 0, 255);
  analogWrite(enA, potentioValue);

  // Turn on motor A clockwise
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // delay(3000);

  // Reverse direction
  // digitalWrite(in1, LOW);
  // digitalWrite(in2, HIGH);
  // delay(3000);

  
  // Display time on second line
  lcd.setCursor(0, 1);
  lcd.print("Time: ");
  lcd.print(millis()/1000);
  lcd.print("s    ");
}