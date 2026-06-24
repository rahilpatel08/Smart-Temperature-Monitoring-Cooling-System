#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

const int sensorPin = A0;

const int greenLED = 2;
const int yellowLED = 3;
const int redLED = 4;

const int motorPin = 5;

void setup() {

  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(motorPin, OUTPUT);

  Serial.begin(9600);

  lcd.begin(16, 2);

  lcd.setCursor(0, 0);
  lcd.print("Smart Temp");
  lcd.setCursor(0, 1);
  lcd.print("System Start");

  delay(2000);
  lcd.clear();
}

void loop() {

  int sensorValue = analogRead(sensorPin);

  float voltage = sensorValue * (5.0 / 1023.0);

  float temperature = (voltage - 0.5) * 100.0;

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(temperature, 1);
  lcd.print((char)223);
  lcd.print("C");

  if (temperature < 30) {

    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);

    analogWrite(motorPin, 0);

    lcd.setCursor(0, 1);
    lcd.print("Fan: OFF");

  }

  else if (temperature <= 35) {

    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);

    analogWrite(motorPin, 80);

    lcd.setCursor(0, 1);
    lcd.print("Fan: SLOW");

  }

  else if (temperature <= 40) {

    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);

    analogWrite(motorPin, 170);

    lcd.setCursor(0, 1);
    lcd.print("Fan: MEDIUM");

  }

  else {

    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);

    analogWrite(motorPin, 255);

    lcd.setCursor(0, 1);
    lcd.print("Fan: MAX");

  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" C | Fan PWM: ");

  if (temperature < 30)
    Serial.println("0");
  else if (temperature <= 35)
    Serial.println("80");
  else if (temperature <= 40)
    Serial.println("170");
  else
    Serial.println("255");

  delay(1000);
}