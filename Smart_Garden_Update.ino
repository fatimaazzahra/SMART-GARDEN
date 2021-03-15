#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27 ,16, 2);
int a = (A0);
int b = (D6);
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.init();
  lcd.backlight();
  
  

}

void loop() {
  Serial.println(digitalRead(b));
  Serial.println(analogRead(a));

  if (digitalRead(b)== 0) {
     lcd.setCursor(0,0);
     lcd.print("Cukup Cahaya!");
     delay(1000);
     
  }
  else {
     lcd.setCursor(0,0);
     lcd.print("Kurang Cahaya");
     delay(1000);

  if (analogRead(a) <600 ) {
     lcd.setCursor(0,1);
     lcd.print("Cukup  Lembab");
     delay(1000);
     
  }
  else {
     lcd.setCursor(0,1);
     lcd.print("Kurang Lembab");
     delay(1000);
    
  }
    
}
}
