#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); // Altere para 0x3F se não funcionar

void setup() {
  Wire.begin(8, 9); // SDA = 8, SCL = 9 (seguro no ESP32-S3)

  lcd.init();         // Inicializa o LCD
  lcd.backlight();    // Liga a luz de fundo

  // LINHA 1
  lcd.setCursor(0, 0); //  lcd.setCursor( COLUNA,  LINHA )
  lcd.print("LINHA 1");
  // LINHA 2
  lcd.setCursor(2, 1);
  lcd.print("LINHA 2");
  // LINHA 3
  lcd.setCursor(4, 2);
  lcd.print("LINHA 3");
  // LINHA 4
  lcd.setCursor(6, 3);
  lcd.print("LINHA 4");

}

void loop() {
  // Nada no loop por enquanto
}
