#include "ServoTimer2.h"
#include <SoftwareSerial.h>
#define S_PIN 9
#define T_PIN 10

#define BAUD_RATE 115200
#define RX_PIN 2
#define TX_PIN 3

SoftwareSerial senSerial(RX_PIN, TX_PIN);

ServoTimer2 s;
ServoTimer2 t;

int angle = 0;

void setup() {
  senSerial.begin(19200);
  Serial.begin(BAUD_RATE);
  s.attach(S_PIN);
  t.attach(T_PIN);
  s.write(angle);
  Serial.println("Receiver ready!");
}

void loop() {
  // while (!senSerial.available()) {
    
  //   s.write(angle + 750);
  //   delay(100);
  // }
  // angle = senSerial.read();
  // delay(100);
  while(!senSerial.available()){

  }
  int oldangle = senSerial.parseInt();
  angle = map(oldangle, 0 , 180, 750, 2250); //because the servo2 library maps to microS not angle
  s.write(angle);

  Serial.print("angle: ");
  Serial.println(oldangle);

  delay(100);
}