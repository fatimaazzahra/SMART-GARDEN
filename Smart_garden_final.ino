#include <LiquidCrystal_I2C.h>
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
  
  

}

void loop() {
  int a = (analogRead(kelembaban));
  int persen = map(a, 0, 1023, 0, 100);
  Serial.print("Sensor Cahaya Sebesar :");
  Serial.println(digitalRead(cahaya));
  Serial.print("Sensor Kelembapan Sebesar :");
  Serial.print(persen);
  Serial.println("%");

  if (digitalRead(cahaya)== 0) {
     lcd.setCursor(0,0);
     lcd.print("Cukup Cahaya!");
     digitalWrite(lampu,LOW);
     
     
     
     
  }
  else {
     lcd.setCursor(0,0);
     lcd.print("Kurang Cahaya");
     delay(1000);
     digitalWrite(lampu,HIGH);

  if ((persen)< 50 )   {
     lcd.setCursor(0,1);
     lcd.print("Kelembaban : ");
     lcd.print(persen);
     lcd.print("%");
     digitalWrite(pump,LOW);
     
     
     
  }
  else {
     lcd.setCursor(0,1);
     lcd.print("Kelembaban : ");
     lcd.print(persen);
     lcd.print("%");
     delay(1000);
     digitalWrite(pump,HIGH);
     
    
  }
    
}
}
