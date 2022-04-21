
const int trigPin = 7;
const int echoPin = A0;
int red=9;
int green=10;
int blue=11;
long duration;
int distance;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");

  if (distance>30){
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(blue, LOW);
  }
  
  else if (distance>10){
    digitalWrite(red, HIGH);
    analogWrite(green, 85);
    digitalWrite(blue, LOW);
  }
  
  else{
    digitalWrite(red, HIGH);
    analogWrite(green, LOW);
    digitalWrite(blue, LOW);
  }

  delay(1000);
  
}
//Code adapted from, www.HowToMechatronics.com by Dejan Nedelkovski
