// C++ code
/*
A prótese do projeto utiliza servo motores para realizar o movimento dos
dedos. Pensando nisso, neste exercício iremos simular o funcionamento da
prótese através do tinkercad. Para isso, é preciso montar um circuito
utilizando 5 servo motores, cada um sendo conectado a um pino digital
(lembre-se de conectar em pinos digitais PWM do arduino - Pinos 11, 10, 9,
6, 5, 3).

Depois que o circuito estiver montado, crie uma função que recebe 5
valores inteiros, um para cada servo (que controla um dedo da prótese).
A função desenvolvida deverá ser usada na função loop para simular
alguma posição dos dedos que represente algum gesto (por exemplo, o hang
loose).

Explicação do funcionamento do servo motor na prótese: para a
realização dos movimentos na prótese usamos o valor mínimo do servo
motor para representar os dedos que estão abertos e o valor máximo para os
dedos que devem ser fechados
*/

#include <Servo.h>

Servo servoDedao;
Servo servoIndicador;
Servo servoMedio;
Servo servoAnelar;
Servo servoMinimo;

int posMax = 180;

String dedo;

void setup() {
  Serial.begin(9600);

  servoDedao.attach(11);
  servoIndicador.attach(10);
  servoMedio.attach(9);
  servoAnelar.attach(6);
  servoMinimo.attach(5);

  posicaoInicial();

  aguardeComando();
}

void loop() {
  Serial.println(dedo);
  
  if (dedo.equals("1")) {
     comandosDedao();
     aguardeComando();
    
  } else if (dedo.equals("2")) {
    comandosIndicador();
    aguardeComando();
    
  } else if (dedo.equals("3")) {
    comandosMedio();
    aguardeComando();
    
  } else if (dedo.equals("4")) {
    comandosAnelar();
    aguardeComando();
    
  } else if (dedo.equals("5")) {
    comandosMinimo();
    aguardeComando();
    
  } else if (dedo.equals("r")) {
    posicaoInicial();
    aguardeComando();
    
  } else {
    Serial.println("comando invalido digite! Insira um valor valido");
    aguardeComando();
  }
}

void comandosDedao(){
  if(servoDedao.read() == 180){
      servoDedao.write(0);
      Serial.println("Dedao levantando!");
        }else if (servoDedao.read() == 0){
          servoDedao.write(180);
          Serial.println("Dedao abaixando!");
        }
}

void comandosIndicador(){
  if(servoIndicador.read() == 180){
      servoIndicador.write(0);
      Serial.println("Indicador levantando!");
        }else if (servoIndicador.read() == 0){
          servoIndicador.write(180);
          Serial.println("Indicador abaixando!");
        }
}

void comandosMedio(){
  if(servoMedio.read() == 180){
      servoMedio.write(0);
      Serial.println("Medio levantando!");
        }else if (servoMedio.read() == 0){
          servoMedio.write(180);
          Serial.println("Medio abaixando!");
        }
}

void comandosAnelar(){
  if(servoAnelar.read() == 180){
      servoAnelar.write(0);
      Serial.println("Anelar levantando!");
        }else if (servoAnelar.read() == 0){
          servoAnelar.write(180);
          Serial.println("Anelar abaixando!");
        }
}

void comandosMinimo(){
  if(servoMinimo.read() == 180){
      servoMinimo.write(0);
      Serial.println("Minimo levantando!");
        }else if (servoMinimo.read() == 0){
          servoMinimo.write(180);
          Serial.println("Minimo abaixando!");
        }
}



void posicaoInicial() {
  servoDedao.write(posMax);
  servoIndicador.write(posMax);
  servoMedio.write(posMax);
  servoAnelar.write(posMax);
  servoMinimo.write(posMax);
  Serial.println("Servos em posição inicial");
}

void aguardeComando() {
  Serial.println("1 - Dedao");
  Serial.println("2 - Indicador");
  Serial.println("3 - Medio");
  Serial.println("4 - Anelar");
  Serial.println("5 - Minimo");
  Serial.println("Insira a posicao de um dedo para movimenta-lo: ");
  while (Serial.available() == 0) {
  }
  dedo = Serial.readString();
}