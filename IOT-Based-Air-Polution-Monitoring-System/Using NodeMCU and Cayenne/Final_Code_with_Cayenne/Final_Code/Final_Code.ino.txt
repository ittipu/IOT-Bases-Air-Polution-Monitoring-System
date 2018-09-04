#define buz D0
#define redLed D1
#define greenLed D2
#define sensorPin A0

#define CAYENNE_PRINT Serial
#include <CayenneMQTTESP8266.h>
int sensorValue;
char ssid[] = "ICE_Innovation_lab";
char wifiPassword[] = "bolajabena15";
char username[] = "eecd27e0-1c3f-11e8-b6d4-35a0ad51f849";
char password[] = "ad1efb65d66fc1830a8915ce2df57662397bb3d2";
char clientID[] = "6a147440-b014-11e8-b20b-f17b9147793f";
void setup() {
  pinMode(buz, OUTPUT);
  pinMode(sensorPin, INPUT);
  pinMode(redLed,OUTPUT);
  pinMode(greenLed, OUTPUT);
  Serial.begin(9600);
  Cayenne.begin(username, password, clientID, ssid, wifiPassword);
}

void loop() {
  Cayenne.loop();
  sensorValue = analogRead(sensorPin);

  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);
  // Checks if it has reached the threshold value
  if (sensorValue <=600)
  {
    digitalWrite(buz, LOW);
    digitalWrite(greenLed, HIGH);
    digitalWrite(redLed, LOW);
  }
  else
  {
    digitalWrite(buz, HIGH);
    digitalWrite(greenLed,LOW);
    digitalWrite(redLed, HIGH);
  }
  delay(1000);
}
CAYENNE_OUT_DEFAULT()
{
 Cayenne.virtualWrite(0, sensorValue);
}

