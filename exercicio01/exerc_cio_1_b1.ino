/*
b) Então adicione um sensor de temperatura conectado a um pino analógico, como
na imagem a seguir. O pino analógico conectado irá ler “20” quando a temperatura
for a menor possível, e “358” quando for a maior. Faça o LED azul acender quando
a temperatura for menor que 10, o verde quando a temperatura for maior ou igual a
10 e menor que 30, e o vermelho quando a temperatura for maior ou igual a 30.
*/

#define LED_AZUL 3
#define LED_VERDE 4
#define LED_VERM 5

#define SENSOR_TEMP A5

int leituraTemp = 0;
float voltagem = 0;
float temperatura = 0;

void setup() {
  pinMode(LED_AZUL, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_VERM, OUTPUT);

  pinMode(SENSOR_TEMP, INPUT);

  Serial.begin(9600);
}

void loop()
{
  leituraTemp = analogRead(SENSOR_TEMP);
  
  conversaoVoltagemTemperatura();
  
      if (temperatura < 10) {
        digitalWrite(LED_AZUL, HIGH);
        delay(1000);
        digitalWrite(LED_AZUL, LOW);
        
      	} else if (temperatura >= 10 && temperatura < 30){
            digitalWrite(LED_VERDE, HIGH);
        	delay(1000);
       		digitalWrite(LED_VERDE, LOW);

       		} else if (temperatura >= 30) {          
              	digitalWrite(LED_VERM, HIGH);
        		delay(1000);
        		digitalWrite(LED_VERM, LOW);
      }else{
        Serial.println("Erro (valor impossivel)"); 
      }
}

  void conversaoVoltagemTemperatura(){
    voltagem = leituraTemp * (5000 / 1024.0);
    temperatura = (voltagem - 500) / 10;
  }