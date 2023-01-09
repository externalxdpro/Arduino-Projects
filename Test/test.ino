#define led 7

void setup()
{
    Serial.begin(9600);
    pinMode(led, OUTPUT);
    digitalWrite(led, HIGH);
}

void loop()
{
    if (Serial.available() > 0)
    {
        String outputString = "Serial.available() = " + (String) Serial.available();
        Serial.println(outputString);
    }
    else
    {
        Serial.println("Serial not available");
    }
//    pinMode(led, LOW);
//    delay(1000);
//    pinMode(led, HIGH);
//    delay(1000);
}
