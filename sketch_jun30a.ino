#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display
#include <DHT.h>
#include <DHT_U.h>
int PIN = 2; //defines the digital pin connected to the DHT sensor
#define Type DHT11
float h;
float t;
float f;
const int digPower = 8;
int sensor;
DHT dht(PIN,Type);
void setup() {
 Serial.begin(9600);
 dht.begin();
 pinMode(digPower,OUTPUT);
 lcd.init();         // initialize the lcd
 lcd.backlight();    // Turn on the LCD screen backlight
}

void loop() {
delay(2000);
  h = dht.readHumidity();
  t = dht.readTemperature();// Read temperature as Celsius (the default)
  f = (9.0*t/5.0)+32;// converts temperature in celcius to Fahrenheit 
   lcd.setCursor(0, 0);
   lcd.print("Hum:");
   lcd.print(h);
   lcd.setCursor(0, 1);
   lcd.print("Temp:");
   lcd.print(t);
   lcd.print(" ");
   lcd.print(f);
   lcd.clear();
   digitalWrite(digPower,HIGH);
   delay (100);
   sensor = analogRead(A0);
   digitalWrite(digPower,LOW);
   //Serial.println(sensor); I used this to calibrate the sensor
   if (sensor < 170 ){
      lcd.print("soil wet");
      lcd.print("Pump:OFF");
      delay (1800000);
   }
   else {
      lcd.print("soil wet");
      lcd.print("Pump:ON");
      //Pump starting Algorithm
      delay (5000);
   }
  delay(1000);  
}
