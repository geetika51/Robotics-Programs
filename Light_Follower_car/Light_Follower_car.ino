//Define LDR and Motor driver pins

const int leftLdrPin = A0;
const int rightLdrPin = A1;
const int enA =10;
const int in1 =9;
const int in2 =8;
const int enB =5;
const int in3 =7;
const int in4 =6;
void setup() {
  // Set motor driver pins as output
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
Serial.begin(9600);
}

void loop() {
  //Read LDR values
  int leftLdrValue = analogRead(leftLdrPin);
int rightLdrValue = analogRead(rightLdrPin);

//Map ldr values to motor speeds
int leftMotorSpeed =map(leftLdrValue,0,1023,0,255);
int rightMotorSpeed =map(rightLdrValue,0,1023,0,255);

Serial.print("left ldr value : ");
Serial.println(leftLdrValue);
Serial.print("Right ldr value : ");
Serial.println(rightLdrValue);

//Set motor directions based on LDR values
if(leftLdrValue<500 && rightLdrValue>500){
  //turn right
  digitalWrite(in1,LOW);
   digitalWrite(in2,HIGH);
    digitalWrite(in3,HIGH);
     digitalWrite(in4,LOW);
}
else if(leftLdrValue>500 && rightLdrValue<600){
  //turn left
  digitalWrite(in1,HIGH);
   digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
     digitalWrite(in4,HIGH);
}else {
  //go straight
  digitalWrite(in1,LOW);
   digitalWrite(in2,HIGH);
    digitalWrite(in3,LOW);
     digitalWrite(in4,HIGH);
}

//Set motor Speed
analogWrite(enA,leftMotorSpeed);
analogWrite(enB,rightMotorSpeed);
}
