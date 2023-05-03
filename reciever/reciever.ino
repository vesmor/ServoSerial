// Receiver

#include "Servo.h"

#define T_PIN 7
#define S_PIN 12
#define CLOSE 91
#define OPEN 0
Servo s;
Servo t;

const int SIGNAL_PIN1 = 3;
const int SIGNAL_PIN2 = 5;
// Pin to receive the signal from the first Arduino
// Pin to control the buzzer
int num = 3;

void setup()
{
  Serial.begin(19200);
  // make sure we pin up at the beginnning
  pinMode(SIGNAL_PIN1, INPUT_PULLUP);
  pinMode(SIGNAL_PIN2, INPUT_PULLUP);

  s.attach(S_PIN);
  t.attach(T_PIN);

  s.write(91); // get it into starting positon
  t.write(91);
  delay(1000);
}

void loop()
{
  // get the exact same num value sender is sending
  num = ((digitalRead(SIGNAL_PIN2) == HIGH) << 1) + (digitalRead(SIGNAL_PIN1) == HIGH);
  Serial.print(num);
  Serial.print(" ");
  Serial.print(digitalRead(SIGNAL_PIN2) == HIGH);
  Serial.print(" ");
  Serial.println(digitalRead(SIGNAL_PIN1) == HIGH);
  switch (num)
  {
  case 0:           // Disconnected
    s.write(CLOSE); // get it into starting positon
    t.write(CLOSE);
    break;

  case 1:          // Launch
    s.write(OPEN); // get it into starting positon
    t.write(OPEN);
    break;
  case 2:          // Abort
    s.write(OPEN); // get it into starting positon
    t.write(CLOSE);
    break;
  case 3: // Close - Active
    delay(10000);
    s.write(CLOSE);
    t.write(CLOSE);
    break;
  }
}
