//FIXME: theres some type of weird bug where the receiver arduino being attached to usb will work but attaching it to the sender will reset it back to 0

#include <SoftwareSerial.h>
#define BAUD_RATE 115200
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

//send random angle between 0 and 180 to receiver with servo attached
void loop() {
  // //Send
  // Serial.println("Enter an angle from 0-180:");
  // //Wait for user input
  // while (!Serial.available()) {  }
  // C = Serial.parseInt();
  // Serial.flush();
  // //In case we dont get the right values
  // if(C==0)recSerial.print(CLOSE);
  // if(C==1)recSerial.print(OPEN);
  // Serial.print(angle);
  // delay(100);

  long angle = random(0, 180);
  recSerial.print(angle);
  recSerial.flush();
  
  delay(100);
  Serial.println(angle);
  delay(1500);
}