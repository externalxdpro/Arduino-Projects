#include <SPI.h>

uint8_t button = 2;
uint8_t led = 7;

int buttonValue;

void setup()
{
    Serial.begin(115200);

    pinMode(button, INPUT);
    pinMode(led, OUTPUT);

    SPI.begin();
    SPI.setClockDivider(SPI_CLOCK_DIV8);
    digitalWrite(SS, HIGH);
}

void loop()
{
    byte masterSend, masterReceive;
    buttonValue = digitalRead(button);

    if (buttonValue == HIGH) masterSend = 1;
    else masterSend = 0;

    digitalWrite(SS, LOW);
    masterReceive = SPI.transfer(masterSend);

    if (masterReceive == 1) 
    {
        digitalWrite(led, HIGH);
        Serial.println("Master LED ON");
    }
    else
    {
        digitalWrite(led, LOW);
        Serial.println("Master LED OFF");
    }

    delay(1000);
}
