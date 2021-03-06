/*
 HC-SR04 Ping distance sensor]
 VCC to arduino 5v GND to arduino GND
 Echo to Arduino pin 9 Trig to Arduino pin 8
 More info at: http://goo.gl/kJ8Gl
 超音波距離センサを使用してpiとシリアル通信を行うよ
 ゼミ室のドアに設置
 */

#define trigPin 8
#define echoPin 9
//const int trigPin = 8;
//const int echoPin = 9;
//const int speakerPin = 11;
int tmp;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
//  pinMode(speakerPin, OUTPUT);
  
}

void loop() {
  int duration, distance;
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  //読み込み
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
String s = String(distance);

  
//例外処理
  if (distance >= 400 || distance <= 0){
    Serial.write("0");
  }
//判定
  else if(distance <= 80){
    Serial.write("1");
    digitalWrite(trigPin, HIGH);
    delay(5000);
    Serial.write("0");
  }else{
    Serial.write("0");
  }

  delay(1000);
}
