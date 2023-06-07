#include <Servo.h>

// C++ code
//Exercício 2

/*1) Explique como funcionam os métodos attach(), write() e read() da biblioteca
servo.h
R: attach() serve para vincular o objeto que é necessário criar para controlar o servo ao servo Motor do circuito;
write() serve para definir a posição do "braço" do servo motor a um numero inteiro;
read() serve para receber o valor daquela posição especifica em que o servo motor se encontra;
*/

/*2) Crie o circuito apresentado na imagem abaixo no tinkercad e faça um código
para controlar o servo motor de acordo com o valor do potenciômetro. O
potenciômetro possui valores de 0 a 1023 e o servo motor valores de 0 a 180.
Obs.: Para o correto funcionamento é preciso mapear o valor obtido no
potenciômetro para que o circuito funcione corretamente. Isso pode ser feito
utilizando uma das funções que foi apresentada no slide.
*/

#include <Servo.h>

Servo servoM; //criando um objeto usando a biblioteca para controlar o servomotor

int posicaoServo = 0;
int valorPotenciometro = 0;

const int potenciometro = 0;

// #define servoM 9;

void setup()
{
  Serial.begin(9600);
  servoM.attach(9); //vinculando o servo do pin 9 ao objeto servoM
  pinMode(potenciometro,INPUT);
}

void loop()
{
    
  valorPotenciometro = analogRead(potenciometro);
  posicaoServo = map(valorPotenciometro, 0, 1023, 0, 180);
  servoM.write(posicaoServo);
  
  Serial.print (valorPotenciometro);
  Serial.print (" ; convertido: ");
  Serial.println (posicaoServo);
  delay(1500);
  
  
}