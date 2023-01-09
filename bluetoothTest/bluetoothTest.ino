#include <SoftwareSerial.h>

#define rx 2
#define tx 3
SoftwareSerial BTserial(rx, tx);


void setup()
{
  Serial.begin(9600);
  Serial.println("Enter AT commands:");

  BTserial.begin(9600);
}

void loop()
{
  if (BTserial.available())
  {
    Serial.write(BTserial.read());
  }

  if (Serial.available())
  {
    BTserial.write(Serial.read());
  }
}
