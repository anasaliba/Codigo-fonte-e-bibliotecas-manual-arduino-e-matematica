#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// DEFINIÇÕES DO DISPLAY LCD
#define endereco  0x27   // Endereços I2C mais comuns: 0x27 ou 0x3F
#define colunas   16     // Número de colunas do display LCD
#define linhas    2      // Número de linhas do display LCD
// INSTANCIANDO O OBJETO DO DISPLAY LCD
LiquidCrystal_I2C lcd(endereco, colunas, linhas);
// VARIÁVEIS
int leituraAD; 
// Armazena o valor lido na entrada analógica (0 a 1023) 
int angulo; 
// Armazena o ângulo convertido a partir da leitura,→ analógica
void setup() {
Serial.begin(9600); // Inicializa a comunicação serial para depuração,→ (opcional)
lcd.init();
lcd.backlight();
lcd.clear();
// Inicializa a comunicação com o display LCD
// Liga a iluminação de fundo do display
// Limpa qualquer informação anterior no display
lcd.print("- Vamos medir! -"); // Mensagem inicial no display
delay(5000); // Aguarda 5 segundos antes de iniciar as leituras 
}
void loop() 
{
lcd.clear(); lcd.print("Angulo (graus)");
  // Realiza a leitura do potenciômetro conectado à entrada analógica A0
  leituraAD = analogRead(A0);
// Converte o valor analógico (0 a 1023) para um ângulo aproximado (0 a ,→ 280 graus)
angulo = (280 * (float)leituraAD / 1023) + 0.5;
  // Exibe o valor do ângulo na segunda linha do display LCD
  lcd.setCursor(0, 1);
  lcd.print(angulo);
delay(1000); // Aguarda 1 segundo antes de realizar a próxima leitura 
}