// C++ code
//Exercício 2

/*2) Crie o circuito apresentado na imagem abaixo no tinkercad e faça um código
para controlar o servo motor de acordo com o valor do potenciômetro. O
potenciômetro possui valores de 0 a 1023 e o servo motor valores de 0 a 180.
Obs.: Para o correto funcionamento é preciso mapear o valor obtido no
potenciômetro para que o circuito funcione corretamente. Isso pode ser feito
utilizando uma das funções que foi apresentada no slide.
*/

#include <Servo.h>

Servo servoM;
int posicaoServo = 0;
int valorPotenciometro = 0;

void setup()
{
  Serial.begin(9600);
  servoM.attach(9);
  pinMode(A2,INPUT);
}

void loop()
{
  	valorPotenciometro = analogRead(A2);
  	posicaoServo = map(valorPotenciometro, 0, 1023, 0, 180);
  	servoM.write(posicaoServo);
}