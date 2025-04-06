/*
* min 984 mid 1500 max 2005
*	
*/

#include <LCD-I2C.h>
#include <Wire.h>
#define potPin 4
int potVal = 0;
int percent;
LCD_I2C lcd(0x27, 16, 2); // Default address of most PCF8574 modules, change according

void setup() {
      Serial.begin(115200);
    delay(1000);
    Wire.begin();
    lcd.begin(&Wire);
    lcd.display();
    lcd.backlight();
}

void loop()
{
    
    
    
    // Reading potentiometer value
    potVal = analogRead(4);
    Serial.println(potVal);
    percent = map(potVal, 1500, 2005, 0, 100); // convert reading to a percentage
    lcd.print(percent ); 
    lcd.print("%" );// You can make spaces using well... spaces
    delay(100);
    lcd.clear();
    lcd.setCursor(0, 0); // Or setting the cursor in the desired position.
}
