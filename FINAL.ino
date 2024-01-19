
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#include <ArduinoJson.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

StaticJsonDocument<200> doc;

int pos0 = 102;
int pos180 = 512;

int JoyX = A0;  
int JoyY = A1;
int JoyX1 = A2;  
int JoyY1 = A3;
int JoyX2 = A6;  
int JoyY2 = A7;

int bot2 = 2;
int bot3 = 3;
int bot6 = 6;
int bot7 = 7;

int Led2=10;



int Servo0Position=90;
int Servo1Position=90;
int Servo2Position=90;
int Servo3Position=90;
int Servo4Position=90;
int Servo5Position=0;

long da;


void setup() { 
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(50);
  while (!Serial) continue;

  pinMode(Led2, OUTPUT);


  initial_position();
  delay(500);

  pinMode(bot2, INPUT_PULLUP);
  pinMode(bot3, INPUT_PULLUP);
  pinMode(bot6, INPUT_PULLUP);
  pinMode(bot7, INPUT_PULLUP);
}  

void loop() {

    
   if(digitalRead(bot7)==0){
     da=1;
     Serial.println(1);
   }
   if(digitalRead(bot6)==0){
     da=2;
     Serial.println(2);
   }
   if(digitalRead(bot3)==0){
     da=3;
     Serial.println(2);
   }
 
   switch(da){
    case 1:
        digitalWrite(Led2, HIGH);
        local();
        break;
    case 2:
        digitalWrite(Led2, LOW);
        cliente();
        break;
    case 3:
        digitalWrite(Led2, LOW);
        rutina();
        break;
    } 
}

void cliente(){

    if (Serial.available()) {
    String data = Serial.readStringUntil('\n');
    Serial.println(data);
    
    DeserializationError error = deserializeJson(doc, data);
    
    // Test if parsing succeeds.cd ..
    if (error) {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
      return;
   }

   }
    
    long s1 = doc["s1"];
    long s2 = doc["s2"];
    long s3 = doc["s3"];
    long s4 = doc["s4"];
    long s5 = doc["s5"];
    long s6 = doc["s6"];
    
    setServo(0, s1);
    setServo(1, s2);
    setServo(2, s3);
    setServo(13, s4);
    setServo(14, s5);
    setServo(15, s6);
    Serial.println(s1);
    Serial.println(s2);
    Serial.println(s3);
    Serial.println(s4);
    Serial.println(s5);
    Serial.println(s6);
    Serial.println("hola servos");
}


void local(){
  if (!digitalRead(bot2)) 
  { 
    Servo0Position=90;
    Servo1Position=80;
    Servo2Position=10;
    Servo3Position=90;
    Servo4Position=90;
    Servo5Position=0;

    setServo(0, Servo0Position);
    setServo(1, Servo1Position);
    setServo(2, Servo2Position);
    setServo(13, Servo3Position);
    setServo(14, Servo4Position);
    setServo(15, Servo5Position);
  }
  //SERVO 0
  if (analogRead(JoyX) > 800) 
  {
    if (Servo0Position < 400) 
    { 
      Servo0Position++; 
    }  
  }
  if (analogRead(JoyX) < 300) 
  { 
   if (Servo0Position > 10) 
    {
     Servo0Position--;
    }
  }
  delay(2); 
  setServo(0, Servo0Position); 

  //sERVO 1
  if (analogRead(JoyY) > 800) 
  {
    if (Servo1Position < 400) 
    { 
      Servo1Position++;
    }  
  }
  if (analogRead(JoyY) < 300) 
  { 
   if (Servo1Position > 10) 
    {
     Servo1Position--;
    }
  }
  delay(2); 
  setServo(1, Servo1Position); 

  //SERVO 2
  if (analogRead(JoyX1) > 800) 
  {
    if (Servo2Position < 400) 
    { 
      Servo2Position++; 
    }  
  }
  if (analogRead(JoyX1) < 300) 
  { 
   if (Servo2Position > 10) 
    {
     Servo2Position--;
    }
  }
  delay(2); 
  setServo(2, Servo2Position); 

  //SERVO 13
  if (analogRead(JoyY1) > 800) 
  {
    if (Servo3Position < 400) 
    { 
      Servo3Position++; 
    }  
  }
  if (analogRead(JoyY1) < 300) 
  { 
   if (Servo3Position > 10) 
    {
     Servo3Position--;
    }
  }
  delay(2); 
  setServo(13, Servo3Position);

  //SERVO 14
  if (analogRead(JoyX2) > 800) 
  {
    if (Servo4Position < 400) 
    { 
      Servo4Position++; 
    }  
  }
  if (analogRead(JoyX2) < 300) 
  { 
   if (Servo4Position > 10) 
    {
     Servo4Position--;
    }
  }
  delay(2); 
  setServo(14, Servo4Position); 

  //SERVO 15
  if (analogRead(JoyY2) > 800) 
  {
    if (Servo5Position < 400) 
    { 
      Servo5Position++; 
      if (Servo5Position > 90)  
      {
        Servo5Position = 90;
      }
    }  
  }
  if (analogRead(JoyY2) < 300) 
  { 
   if (Servo5Position > 10) 
    {
     Servo5Position--;
    }
  }
  delay(2); 
  setServo(15, Servo5Position);
}

void rutina() {
 
  delay(1000);
  setServo(0, 90);
  setServo(1, 80);
  setServo(2, 10);
  setServo(13, 90);
  setServo(14, 90);
  setServo(15, 0);
  delay(1000);

  
  setServo(0, 90);
  setServo(1, 80);
  setServo(2, 40);
  setServo(13, 35);
  setServo(14, 130);
  setServo(15, 50);
  delay(750);

  setServo(0, 90);
  setServo(1, 80);
  setServo(2, 40);
  setServo(13, 35);
  setServo(14, 40);
  setServo(15, 0);
  delay(750);

  setServo(0, 90);
  setServo(1, 80);
  setServo(2, 40);
  setServo(13, 35);
  setServo(14, 130);
  setServo(15, 0);
  delay(750);

 setServo(0, 90);
  setServo(1, 80);
  setServo(2, 40);
  setServo(13, 35);
  setServo(14, 40);
  setServo(15, 0);
  delay(750);

  setServo(0, 90);
  setServo(1, 80);
  setServo(2, 40);
  setServo(13, 35);
  setServo(14, 130);
  setServo(15, 0);
  delay(750);

setServo(0, 90);
  setServo(1, 80);
  setServo(2, 40);
  setServo(13, 35);
  setServo(14, 40);
  setServo(15, 0);
  delay(750);

  setServo(0, 90);
  setServo(1, 80);
  setServo(2, 40);
  setServo(13, 35);
  setServo(14, 130);
  setServo(15, 0);
  delay(750);

  setServo(0, 90);
  setServo(1, 80);
  setServo(2, 40);
  setServo(13, 35);
  setServo(14, 40);
  setServo(15, 0);
  delay(750);

  setServo(0, 90);
  setServo(1, 80);
  setServo(2, 40);
  setServo(13, 35);
  setServo(14, 130);
  setServo(15, 0);
  delay(2000);
  
/*Saludo 2*/
setServo(0, 140);
  setServo(1, 80);
  setServo(2, 40);
  setServo(13, 35);
  setServo(14, 40);
  setServo(15, 0);
  delay(750);

   setServo(0, 140);
  setServo(1, 80);
  setServo(2, 40);
  setServo(13, 35);
  setServo(14, 130);
  setServo(15, 0);
  delay(750);

  setServo(0, 140);
  setServo(1, 80);
  setServo(2, 40);
  setServo(13, 35);
  setServo(14, 40);
  setServo(15, 0);
  delay(750);

  setServo(0, 140);
  setServo(1, 80);
  setServo(2, 40);
  setServo(13, 35);
  setServo(14, 130);
  setServo(15, 0);
  delay(750);


setServo(0, 140);
  setServo(1, 80);
  setServo(2, 40);
  setServo(13, 35);
  setServo(14, 40);
  setServo(15, 0);
  delay(750);

  setServo(0, 140);
  setServo(1, 80);
  setServo(2, 40);
  setServo(13, 35);
  setServo(14, 130);
  setServo(15, 0);
  delay(750);

  setServo(0, 140);
  setServo(1, 80);
  setServo(2, 40);
  setServo(13, 35);
  setServo(14, 40);
  setServo(15, 0);
  delay(2000);
/*Saludo 3*/
   setServo(0, 40);
  setServo(1, 80);
  setServo(2, 40);
  setServo(13, 35);
  setServo(14, 40);
  setServo(15, 0);
  delay(750);

   setServo(0, 40);
  setServo(1, 80);
  setServo(2, 40);
  setServo(13, 35);
  setServo(14, 130);
  setServo(15, 0);
  delay(750);

   setServo(0, 40);
  setServo(1, 80);
  setServo(2, 40);
  setServo(13, 35);
  setServo(14, 40);
  setServo(15, 0);
  delay(750);

   setServo(0, 40);
  setServo(1, 80);
  setServo(2, 40);
  setServo(13, 35);
  setServo(14, 130);
  setServo(15, 0);
  delay(750);

   setServo(0, 40);
  setServo(1, 80);
  setServo(2, 40);
  setServo(13, 35);
  setServo(14, 40);
  setServo(15, 0);
  delay(750);

  setServo(0, 40);
  setServo(1, 80);
  setServo(2, 40);
  setServo(13, 35);
  setServo(14, 130);
  setServo(15, 0);
  delay(750);

   setServo(0, 40);
  setServo(1, 80);
  setServo(2, 40);
  setServo(13, 35);
  setServo(14, 40);
  setServo(15, 0);
  delay(750);

   setServo(0, 40);
  setServo(1, 80);
  setServo(2, 40);
  setServo(13, 35);
  setServo(14, 130);
  setServo(15, 0);
  delay(750);


}


void initial_position() {
  delay(500);
  setServo(0, 90);
  setServo(1, 80);
  setServo(2, 10);
  setServo(13, 90);
  setServo(14, 90);
  setServo(15, 0);
}

void setServo(int servo, int angle) {
  int duty;
  duty = map(angle, 0, 180, pos0, pos180);
  pwm.setPWM(servo, 0, duty);
}
