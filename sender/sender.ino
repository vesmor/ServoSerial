// FIXME: theres some type of weird bug where the receiver arduino being attached to usb will work but attaching it to the sender will reset it back to 0

// #include <SoftwareSerial.h>
#define BAUD_RATE 115200
#define TX_PIN 3

#define CLOSE 0
#define OPEN 1

int mode = 0;

void setup()
{
  Serial.begin(BAUD_RATE);

  pinMode(TX_PIN, OUTPUT);
}

// send random angle between 0 and 180 to receiver with servo attached
void loop()
{
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

  Serial.println("Enter 0. Close or 1. Open:");

  while (!Serial.available())
  {
  }

  mode = Serial.parseInt();
  if (mode == OPEN)
  {
    mode = OPEN;
    digitalWrite(TX_PIN, HIGH);
    Serial.println("Opening to 180 degrees");
  }
  else if (mode == CLOSE)
  {
    mode = CLOSE;
    digitalWrite(TX_PIN, LOW);
    Serial.println("Closing to 0 degrees");
  }

  delay(50);
}
