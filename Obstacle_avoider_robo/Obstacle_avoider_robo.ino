int trigPin =9;  //Trig pin of HC-SR04
int echoPin =10; //Echo pin of HC-SR04

int backleft4 =4; //backward motion of Left motor
int fwdleft5 =5; //Forward motion of Left motor
int backright6=6; //backward motion of Right motor
int fwdright7=7; //Forward motion of Right motor

long duration , distance;
void setup() {
  delay(random(500,2000)); //Delay for a random time
  Serial.begin(9600);
  pinMode(backleft4,OUTPUT);
  pinMode(fwdleft5,OUTPUT);
  pinMode(backright6,OUTPUT);
  pinMode(fwdright7,OUTPUT);

  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(2);
  duration= pulseIn(echoPin,HIGH);  
  distance=(duration/58.2); //distance in cm
  delay(10);

if(distance>19){
  //MOVE FORWARD
digitalWrite(fwdright7,HIGH);
digitalWrite(backright6,LOW);
digitalWrite(fwdleft5,HIGH);
digitalWrite(backleft4,LOW);
}
else if(distance<18){
//STOP BRIEFLY
digitalWrite(fwdright7,LOW);
digitalWrite(backright6,LOW);
digitalWrite(fwdleft5,LOW);
digitalWrite(backleft4,LOW);
delay(500);

//MOVE BACKWARD
digitalWrite(fwdright7,LOW);
digitalWrite(backright6,HIGH);
digitalWrite(fwdleft5,LOW);
digitalWrite(backleft4,HIGH);
delay(500);

//STOP BRIEFLY
digitalWrite(fwdright7,LOW);
digitalWrite(backright6,LOW);
digitalWrite(fwdleft5,LOW);
digitalWrite(backleft4,LOW);
delay(100);

//MOVE FORWARD AND TURN
digitalWrite(fwdright7,HIGH);
digitalWrite(backright6,LOW);
digitalWrite(fwdleft5,LOW);
digitalWrite(backleft4,LOW);
delay(500);
}

}
