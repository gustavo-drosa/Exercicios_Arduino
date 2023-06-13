// C++ code
//Exercício 3
/*3) Crie um circuito apenas com o servo motor e faça um código para controlar o
servo motor de acordo com a palavra recebida pelo Monitor Serial (no
Tinkercad o Monitor Serial fica na parte inferior de onde é escrito o código). A
tabela 1 apresenta cada palavra com o seu respectivo movimento.
Palavra Movimento

“hor” - O servo deverá realizar um
movimento de 180º suave no sentido
horário

“ant” - O servo deverá realizar um
movimento de 180º suave no sentido
anti-horário

Qualquer outra palavra Escolha um valor fixo para o servo

Obs.: Para esse exercício é necessário esperar ser recebido algum valor no
Monitor Serial e somente depois realizar o respectivo movimento.
*/

#include <Servo.h>

Servo servoMotor;

String comandoUsuario;

int posSM = 0;

void setup()
{
  	Serial.begin(9600);
	servoMotor.attach(9);
  
	comandoInicial();
}

void loop()
{  
  
  Serial.println(comandoUsuario);
  servoMotor.write(posSM);
  
    if(comandoUsuario.equals("hor")){
      for(posSM = 180;posSM>=0; posSM--){
      servoMotor.write(posSM);
        delay(25);
      }
      Serial.println("for HOR finalizado!");
      comandoInicial();
      
    }else if(comandoUsuario == "ant"){
        for(posSM = 0; posSM<=180; posSM++){
        servoMotor.write(posSM);
          Serial.println(posSM);
          delay(25);
        }
        Serial.println("for ANT finalizado!");
        comandoInicial();
      
    }else{
        posSM = 90;
        servoMotor.write(posSM);
        Serial.println("Posicao original do Servo Motor retomada.");
        comandoInicial();
      }
}

void comandoInicial(){
  Serial.println("Determine um comando para o servo: ");
  
  while (Serial.available() == 0) {
  }
  comandoUsuario = Serial.readString();
}