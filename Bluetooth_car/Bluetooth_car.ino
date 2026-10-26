int motor1Pin1 =2;
int motor1Pin2 =3;
int motor2Pin1= 4;
int motor2Pin2 =5;

unsigned char blue_data;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

pinMode(motor1Pin1,OUTPUT);
pinMode(motor1Pin2,OUTPUT);
pinMode(motor2Pin1,OUTPUT);
pinMode(motor2Pin2,OUTPUT);

digitalWrite(motor1Pin1,LOW);
digitalWrite(motor1Pin2,LOW);
digitalWrite(motor2Pin1,LOW);
digitalWrite(motor2Pin2,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0){
  blue_data = Serial.read();
  //MOVE FORWARD
if (blue_data == 'F') {
  digitalWrite(motor1Pin1,LOW);
digitalWrite(motor1Pin2,HIGH);
digitalWrite(motor2Pin1,LOW);
digitalWrite(motor2Pin2,HIGH);
}
// mOVE BACKWARD
  if (blue_data == 'B') {
  digitalWrite(motor1Pin1,HIGH);
digitalWrite(motor1Pin2,LOW);
digitalWrite(motor2Pin1,HIGH);
digitalWrite(motor2Pin2,LOW);
}

// TURN RIGHT
if (blue_data == 'R') {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}
// TURN LEFT
if (blue_data == 'L') {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
}
if (blue_data == 'S') {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}
}
}