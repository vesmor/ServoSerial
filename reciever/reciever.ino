#include "Servo.h"
#include <SoftwareSerial.h>
#define S_PIN 9
#define T_PIN 10

#define BAUD_RATE 9600
#define RX_PIN 2
#define TX_PIN 3

SoftwareSerial senSerial(RX_PIN, TX_PIN);

Servo s;
Servo t;
int angle = 0;

void setup() {
  senSerial.begin(19200);
  s.attach(S_PIN);
  t.attach(T_PIN);
}

void loop() {
  while (!senSerial.available()) {
    
    s.write(angle);
  }
  angle = senSerial.read();
}