#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigPin = 3;
const int echoPin = 2;

// Measure from the front of the ultrasonic sensor
// to the floor in centimeters.
const float sensorHeight = 200.0;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Height Meter");
  delay(2000);
  lcd.clear();
}

float getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0)
    return -1;

  return (duration * 0.0343) / 2.0;
}

void loop() {
  float total = 0;

float distanceToHead = getDistance();
    // Height in cm
    float height = sensorHeight - distanceToHead;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Height:");

    lcd.setCursor(0, 1);
    lcd.print(height, 1);
    lcd.print(" cm");
    delay(500);
  }
