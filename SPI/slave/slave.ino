#include <SPI.h>

uint8_t button = 2;
uint8_t led = 7;

bool received;
byte slaveReceived, slaveSend;

int buttonValue;

void setup()
{
    Serial.begin(115200);

    pinMode(button, INPUT);
    pinMode(led, OUTPUT);
    pinMode(MISO, OUTPUT);

    SPCR |= _BV(SPE);

    SPI.attachInterrupt();
}

ISR (SPI_STC_vect)
{
    slaveReceived = SPDR;
    received = true;
}

void loop()
{
    if (received)
    {
        if (slaveReceived == 1)
        {
            digitalWrite(led, HIGH);
            Serial.println("Slave LED ON");
        }
        else
        {
            digitalWrite(led, LOW);
            Serial.println("Slave LED OFF");
        }

        buttonValue = digitalRead(button);

        if (buttonValue == HIGH) slaveSend = 1;
        else slaveSend = 0;

        SPDR = slaveSend;
        delay(1000);
    }
}
