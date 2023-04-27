//FIXME: servo can not be powered by the same arduino providing it power, or the serial monitor is unable to be opened

#include "Servo.h"
#define S_PIN 9
#define T_PIN 10

#define BAUD_RATE 115200
#define RX_PIN 7
#define OPEN 90
#define CLOSE 0

Servo s;
Servo t;

void setup()
{
  Serial.begin(BAUD_RATE);
  pinMode(RX_PIN, INPUT_PULLUP);
  s.attach(S_PIN);
  s.write(CLOSE);

  t.attach(T_PIN);
  
  //Initialization If reciever is powered first Otherwise the delay should be fine
  // if(digitalRead(RX_PIN) == LOW){
  // while(digitalRead(RX_PIN) == LOW); //its gonna be LOW becuase theres no power for a bit
  // while(digitalRead(RX_PIN) == HIGH);//PINS are all HIGH when initialized so we have to wait for them to not be
  // }
  // OR we could just wait lol
  
  delay(1000);
  Serial.println("Receiver ready!");
}

void loop()
{
  if (digitalRead(RX_PIN) == HIGH)
  {
    Serial.println("HIGH");
    s.write(CLOSE);
  }
  if (digitalRead(RX_PIN) == LOW)
  {
    Serial.println("LOW");
    s.write(OPEN);
  }
}
