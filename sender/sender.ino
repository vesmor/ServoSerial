#include <SoftwareSerial.h>
#define BAUD_RATE 9600
#define RX_PIN 2
#define TX_PIN 3

#define OPEN 0
#define CLOSE 90

SoftwareSerial recSerial(RX_PIN, TX_PIN);
int C = 0;

void setup() {
  Serial.begin(BAUD_RATE);
  recSerial.begin(19200);
}


void loop() {
  //Send
  Serial.println("Enter an angle from 0-180:");
  //Wait for user input
  while (!Serial.available()) {  }
  C = Serial.parseInt();
  Serial.flush();
  //In case we dont get the right values
  if(C==0){recSerial.write(CLOSE);}
  if(C==1){recSerial.write(OPEN);}
  Serial.print(angle);
  delay(100);
}
