// FIXME: theres some type of weird bug where the receiver arduino being attached to usb will work but attaching it to the sender will reset it back to 0

// #include <SoftwareSerial.h>
#define BAUD_RATE 115200
#define TX_PIN 3

#define OPEN 1
#define CLOSE 0

int mode = CLOSE;

void setup()
{
  Serial.begin(BAUD_RATE);
  pinMode(TX_PIN, OUTPUT);
  digitalWrite(TX_PIN, HIGH);
  delay(1000);
}

// send random angle between 0 and 180 to receiver with servo attached
void loop()
{

  Serial.println("Enter 0. Close or 1. Open:");

  while (!Serial.available())
  {
  }

  mode = Serial.parseInt();
  Serial.println(mode);
  if (mode == OPEN)
  {
    mode = CLOSE;
    digitalWrite(TX_PIN, LOW);
    Serial.println("Opening to 90 degrees");
  }
  else if (mode == CLOSE)
  {
    mode = CLOSE;
    digitalWrite(TX_PIN, HIGH);
    Serial.println("Closing to 0 degrees");
  }
}
