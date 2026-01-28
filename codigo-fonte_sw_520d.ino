#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define ENTRADA 7
#define LED 13

#define ENDERECO_LCD 0x27
#define COLUNAS 16
#define LINHAS 2

LiquidCrystal_I2C lcd(ENDERECO_LCD, COLUNAS, LINHAS);

void setup() {
  pinMode(ENTRADA, INPUT_PULLUP); // pull-up interno
  pinMode(LED, OUTPUT);

  digitalWrite(LED, LOW);

  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Sensor SW-520D");
  lcd.setCursor(0, 1);
  lcd.print("Inicializando");
  delay(2000);
}

void loop() {
  int estado = digitalRead(ENTRADA);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Superficie:");

  lcd.setCursor(0, 1);
  if (estado == LOW) {   // movimento / inclinacao detectada
    digitalWrite(LED, HIGH);
    lcd.print("INCLINADA");
  } else {
    digitalWrite(LED, LOW);
    lcd.print("NAO INCLINADA");
  }

  delay(500);
}
