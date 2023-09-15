#include <DHT11.h>



//kutuphaneler


#include <LiquidCrystal_I2C.h>

#include <Wire.h>



// LCD ekranın adresi------------------------------------------------------
#define LCD_ADDRESS 0x27

// LCD ekranın satır ve sütun sayısı----------------------------------------------------------
#define LCD_COLUMNS 16
#define LCD_ROWS 2

// LCD ekran nesnesi
LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);

void setup() {
  Serial.begin(9600);
  

  lcd.begin(LCD_COLUMNS, LCD_ROWS);
  lcd.backlight(); // Arka plan aydınlatmasını aç

  // Tarih ve saat bilgilerini ayarla
  lcd.setCursor(4, 0);
  lcd.print("erebusnisk");
 
}

void loop() {
   lcd.setCursor(5, 1);
  lcd.print(analogRead(A0));
  delay(1000);

}
