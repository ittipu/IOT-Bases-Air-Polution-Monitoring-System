#include <SoftwareSerial.h>
const int sensorPin= 0;
#include <LiquidCrystal.h> 
LiquidCrystal lcd(12,11, 5, 4, 3, 2);
void setup() 
{
  pinMode(8, OUTPUT);
  lcd.begin(16,2);
  Serial.begin(115200);
  pinMode(sensorPin, INPUT);
}
void loop()
{
  float air_quality = analogRead(sensorPin);
  Serial.print("Air Quality: ");
  Serial.println(air_quality);
  lcd.setCursor(0,0);
  lcd.print ("Air Quality: ");
  lcd.print (air_quality);
  if (air_quality<=300)
  {
    lcd.setCursor(0,1);
    lcd.print("!!!!Fresh Air!!!");
    digitalWrite(8, LOW);
  }
  else if( air_quality>300 && air_quality<=400)
  {

    lcd.setCursor(0,1);
    lcd.print("!!!!Poor Air!!!!");
    digitalWrite(8, LOW);
  }
  else if (air_quality>450 )
  {
    lcd.setCursor(0,0);
    lcd.print("!!!!!Danger!!!!!");
    lcd.setCursor(0,1);
    lcd.print("Go to Fresh Air.");
    digitalWrite(8, HIGH);   // turn the LED on
  }
  delay(1000);
}
  
  



