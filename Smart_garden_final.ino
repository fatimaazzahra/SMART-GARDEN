#include <LiquidCrystal_I2C.h>
#include <AntaresESP8266MQTT.h>
#define ACCESSKEY "ca55fee49ab1a048:ac85441edd41a2b7"
#define WIFISSID "LIMBONG01"         
#define PASSWORD "nelaangela"     
#define projectName "SmartGarden01"
#define deviceName "smartgarden"

AntaresESP8266MQTT antares(ACCESSKEY);
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27 ,16, 2);

int kelembaban = (A0);
int cahaya = (D3);
int pump = (D4);
int lampu = (D5);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.init();
  lcd.backlight();
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  antares.setDebug(true);
  antares.wifiConnection(WIFISSID, PASSWORD);
  antares.setMqttServer();
  
  }

void loop() {
  antares.checkMqttConnection();
  int a = (analogRead(kelembaban));
  Serial.print("Sensor Cahaya Sebesar :");
  Serial.println(digitalRead(cahaya));
  Serial.print("Sensor Kelembapan Sebesar :");
  Serial.println(a);
  

  if (digitalRead(cahaya)== 0) {
     lcd.setCursor(0,0);
     lcd.print("Cukup Cahaya!");
     digitalWrite(lampu,LOW);
  }
  
  else {
     lcd.setCursor(0,0);
     lcd.print("Kurang Cahaya");
     delay(1000);
     digitalWrite(lampu,HIGH); }

  if ((a)> 600 )   {
     lcd.setCursor(0,1);
     lcd.print("Kelembaban: ");
     lcd.print(a);
     delay(1000);
     digitalWrite(pump,HIGH);
  }
  
  else {
     lcd.setCursor(0,1);
     lcd.print("Kelembaban: ");
     lcd.print(a);
     lcd.print("Kelembaban : ");
     lcd.print(a);
     lcd.print("%");
     delay(1000);
     digitalWrite(pump,LOW);
  }

  


  antares.add("Cahaya", cahaya);
  antares.add("Kelembaban", a);  
  antares.publish(projectName, deviceName);
  delay(5000);

}
