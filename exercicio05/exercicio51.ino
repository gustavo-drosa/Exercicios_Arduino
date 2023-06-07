// dados para LCD:
//lcd.setCursor(0, 0); --> coloca o cursor na (coluna 0, linha 0)
/*1) Para este exercício será necessário incluir a biblioteca LiquidCrystal.h e
inicializa-la [LiquidCrystal lcd(12, 11, 5, 4, 3, 2); e lcd.begin(16, 2);], e utilizar
as funções pinMode() e digitalWrite().
Sensor de Presença
Crie uma cópia do circuito e implemente um código para que ele funcione
como um sensor de presença. Caso detecte presença, acione o led e escreva
“Objeto detectado” no display lcd, caso contrário, desligue o led e escreva
“Objeto não detectado” no display lcd, como mostra na figura abaixo
*/


#include <LiquidCrystal.h>
#define IR 9
#define led 10

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
  
bool movimento = 0;

void setup()
{ 
  Serial.begin(9600);
  lcd.begin(16, 2); //inicia lcd
  pinMode(IR, INPUT);
  lcd.setCursor(0,0);
  
}

void loop()
{ 
  
  movimento = digitalRead(IR);
  
  switch(movimento){
    case 1:
    objetoDetectado();
    break;
    case 0:
  	objetoNaoDetectado();
  }
 /* if(movimento){
    objetoDetectado();
    Serial.println("objeto detectado");
  }else{
    objetoNaoDetectado();
    Serial.println("nenhuma presenca detectada");
  }*/
} 

void objetoDetectado(){
  lcd.clear();
  lcd.print("OBJETO");
  lcd.setCursor(0,1);
  lcd.print("DETECTADO!");
  delay(150);
}

void objetoNaoDetectado(){
  lcd.clear();
  lcd.print("OBJETO");
  lcd.setCursor(0,1);
  lcd.print("NAO DETECTADO");
  delay(150);
}