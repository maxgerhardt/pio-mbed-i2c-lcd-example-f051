#include <mbed.h>
#include "LiquidCrystal_I2C.h"

/* !change me! */
#define I2C_ADDRESS 0x27 
#define LCD_NUM_COLUMNS 20
#define LCD_NUM_LINES 4
#define LCD_I2C_SDA I2C_SDA /* board default pins */
#define LCD_I2C_SCL I2C_SCL 

//the library hardcodes the pin numbers for EN, RW and RS. as P2, P1, P0.
//#define En 0B00000100 // Enable bit
//#define Rw 0B00000010 // Read/Write bit
//#define Rs 0B00000001 // Register select bit
//data bis D4..D7 is expected on P4..P7
//backlight on P3.

LiquidCrystal_I2C lcd(I2C_ADDRESS, LCD_NUM_COLUMNS, LCD_NUM_LINES, LCD_I2C_SDA, LCD_I2C_SCL);
void setup();
void loop();
 
//Arduino style setup function
void setup() {
    lcd.init();
    for (int i = 0; i < 3; i++) {
        lcd.backlight();
        wait_ms(250);
        lcd.noBacklight();
        wait_ms(250);
    }
    lcd.backlight();
    lcd.setCursor(3, 0); // Start at character 4 on line 0
    lcd.print("Hello, world!");
    wait_ms(500);
    lcd.setCursor(2, 1);
    lcd.print("From YourDuino");
    wait_ms(500);
    lcd.setCursor(0, 2);
    lcd.print("20 by 4 Line Display");
    lcd.setCursor(1, 3);
    wait_ms(1000);
    lcd.print("DVSProductions.de");
    wait_ms(8000);
}
 
//print some random characters
void loop() {
    //lcd.setCursor(rand() % 20, rand() % 4);
    //lcd.print(rand() % 10);      
    for (int x = 0; x != 20; x++)
        for (int y = 0; y != 20; y++)
            lcd.print(rand() % 10);
}
 
//Behave like an Arduino
int main() {
    setup();
    while (true)loop();
}