//Define the motoror driver pins for the right motoror
int motor1 = 6;
int motor2 = 7;
int enA = 5;

//Define the motoror driver pins for the left motoror
int motor3 = 8;
int motor4 = 9;
int enB = 10;

//Define the sensor pins
int leftIR = A5;
int rightIR = A4;

void setup() {
  // Set pin modes
  pinMode(leftIR, INPUT);
  pinMode(rightIR, INPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);
}

void loop() {
  // If both IR sensors detect a black surface
  if (digitalRead(leftIR) == HIGH && digitalRead(rightIR) == HIGH) {
    // Stop the robot by giving 0V
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, LOW);
    analogWrite(enA, 0);
    analogWrite(enB, 0);
  } else if (digitalRead(leftIR) == LOW && digitalRead(rightIR) == LOW) {
    //move forward by giving 5v to positive terminals and 0v to negative ternminals of bith motorors
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, HIGH);
    digitalWrite(motor4, LOW);
    analogWrite(enA, 255);
    analogWrite(enB, 255);
  } else {
    //STOP IF BOTH CONDITIONS ARE NOT WORKING
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, LOW);
    analogWrite(enA, 0);
    analogWrite(enB, 0);
  }
}
