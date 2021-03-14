#include <LiquidCrystal_I2C.h>
#define sensorLDR D0
#define sensorsoil A0
#define relay D1

LiquidCrystal_I2C lcd(//alamat I2C modul, 16, 2);

void setup(){
    Serial.begin(9600);
    lcd.begin(16,2);
    lcd.init();
    pinMode(relay, OUTPUT);
    
    //nyalakan backlight
    lcd.backlight();
}

void loop(){
    int sensor_cahaya = digitalRead(sensorLDR);
    int sensor_lembab = analogRead(sensorsoil);
    //Serial.println(sensor_cahaya);
    //Serial.println(sensor_lembab);

    if (sensor_cahaya == 1){
        digitalWrite(#pinLED, HIGH);
        lcd.setCursor(0,0);
        lcd.print("Cahaya Kurang");
    }
    else {
        digitalWrite(#pinLED, LOW);
        lcd.setCursor(0,0);
        lcd.print("Cahaya Cukup");
    }

    if (sensor_lembab < 400){
        digitalWrite(#pinrelay, HIGH);
        lcd.setCursor(0,1);
        lcd.print("Kurang Lembab");
    }
    else {
        digitalWrite(#pinrelay, LOW);
        lcd.setCursor(0,1);
        lcd.print("Cukup Lembab");
    }
    delay(1000);
}
