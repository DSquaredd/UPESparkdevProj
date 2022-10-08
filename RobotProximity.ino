//Motor Driver Pins
#define M1 6
#define M2 7
#define M3 8
#define M4 9

//Proximity sensor
#define TRIG 11
#define ECHO 10

//Directions
#define STOP 0
#define FORWARDS 1
#define BACKWARDS 2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
}

void goForward(){
  digitalWrite(M1,HIGH);
  digitalWrite(M2,LOW);
  digitalWrite(M3,HIGH);
  digitalWrite(M4,LOW);
  delay(1000);
}

void goBackward(){
  digitalWrite(M1,LOW);
  digitalWrite(M2,HIGH);
  digitalWrite(M3,LOW);
  digitalWrite(M4,HIGH);
  delay(1000);
}

void stopCar(){
  digitalWrite(M1,LOW);
  digitalWrite(M2,LOW);
  digitalWrite(M3,LOW);
  digitalWrite(M4,LOW);
  delay(1000);
}

void dance(){
  digitalWrite(M1,LOW);
  digitalWrite(M2,HIGH);
  digitalWrite(M3,HIGH);
  digitalWrite(M4,LOW);
  delay(2000);
}

float proximitySensor(){
  digitalWrite(TRIG,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG,LOW);

  double duration = pulseIn(ECHO,HIGH);

  double distance = ((duration / 2) * 0.0343);
  Serial.print("The distance is: ");
  Serial.print(distance);
  Serial.println("cm ");
  
  delay(10);
  return distance;
}

void Move(int dir){
  if (dir== FORWARDS){
    //goForward();
    goBackward();
  }else if(dir == BACKWARDS){
    //goBackward();
    dance();
  }else if(dir == STOP){
    stopCar();
  }
}


void loop() {

if(proximitySensor() <= 15){
  Move(STOP);
  Move(BACKWARDS);
  Move(STOP);
}else{
  Move(FORWARDS);
}
  delay(20);
}
