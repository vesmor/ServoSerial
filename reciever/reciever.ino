#include "Servo.h"
#define S_PIN 9
#define T_PIN 10

#define BAUD_RATE 115200
#define RX_PIN 7
#define OPEN 0
#define CLOSE 90

Servo s;
Servo t;

int angle = 0;

void setup()
{
  Serial.begin(BAUD_RATE);
  pinMode(RX_PIN, INPUT_PULLUP);

  s.attach(S_PIN);
  t.attach(T_PIN);
  s.write(OPEN);
  delay(1000);
  Serial.println("Receiver ready!");
}

void loop()
{

  if (digitalRead(RX_PIN) == LOW)
  {
    Serial.println("LOW");
    s.write(CLOSE);
  }
  if (digitalRead(RX_PIN) == HIGH)
  {
    Serial.println("HIGH");
    s.write(OPEN);
  }

  delay(100);
}
