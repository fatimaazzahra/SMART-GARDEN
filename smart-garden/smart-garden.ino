#include <LiquidCrystal_I2C.h>
#define sensorLDR A0

LiquidCrystal_I2C lcd(//alamat I2C modul, 16, 2);

void setup(){
    Serial.begin(9600);
    lcd.begin(16,2);
    lcd.init();

    //nyalakan backlight
    lcd.backlight();
}

void loop(){
    int sensor_cahaya = analogRead(sensorLDR);
    //Serial.println(sensor_cahaya);
    //Serial.println(sensor_lembab);

    if (sensor_cahaya < 700){
        digitalWrite(#pinLED, LOW);
        lcd.setCursor(0,0);
        lcd.print("Cahaya Cukup");
    }
    else {
        digitalWrite(pinLED, HIGH);
        lcd.setCursor(0,0);
        lcd.print("Cahaya Kurang");
    }

    if (sensor_lembab < 400){
        digitalWrite(#pinsensor, HIGH);
        lcd.setCursor(0,1);
        lcd.print("Kurang Lembab");
    }
    else {
        digitalWrite(#pinsensor, LOW);
        lcd.setCursor(0,1);
        lcd.print("Cukup Lembab");
    }
    delay(1000);
}
