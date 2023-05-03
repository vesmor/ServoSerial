// Sender
// Zack Kiener
const int SIGNAL_PIN1 = 2;
const int SIGNAL_PIN2 = 3; // Pin to send the signal to the second Arduino

int num = 0;

void setup()
{
  Serial.begin(19200);
  pinMode(SIGNAL_PIN1, OUTPUT);
  pinMode(SIGNAL_PIN2, OUTPUT);
  digitalWrite(SIGNAL_PIN1, LOW);
  digitalWrite(SIGNAL_PIN2, LOW);
  // delay(1000)
}

void loop()
{
  Serial.println("Enter desired degree:");
  while (Serial.available() == 0)
  { // indefinite loop until we enter a degree
  }
  num = Serial.parseInt();
  Serial.print("Servo is going to ");
  Serial.print(num);

  switch (num)
  {
  case 0: // Close No Power
    digitalWrite(SIGNAL_PIN1, LOW);
    digitalWrite(SIGNAL_PIN2, LOW);
    break;
  case 1: // Launch
    digitalWrite(SIGNAL_PIN1, HIGH);
    digitalWrite(SIGNAL_PIN2, LOW);
    break;
  case 2: // Abort
    digitalWrite(SIGNAL_PIN1, LOW);
    digitalWrite(SIGNAL_PIN2, HIGH);
    break;
  case 3: // Close/Active
    digitalWrite(SIGNAL_PIN1, HIGH);
    digitalWrite(SIGNAL_PIN2, HIGH);
    break;
  }

  // if (num == 1) {
  //   num = 1;
  //   digitalWrite(SIGNAL_PIN1, HIGH);  // Send a high signal to the second Arduino
  //   Serial.print(" High / t servo");
  // }
  // if (num == 2) {
  //   num = 2;
  //   digitalWrite(SIGNAL_PIN2, HIGH);
  //   Serial.print(" ");
  // }
  // if (num == 0) {
  //   num = 0;
  //   digitalWrite(SIGNAL_PIN2, LOW);
  // }
}
