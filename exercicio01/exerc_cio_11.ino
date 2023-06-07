#define LED_AZUL 3
#define LED_VERDE 4
#define LED_VERM 5

#define SENSOR_TEMP A5

void setup() {


  pinMode(LED_AZUL, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_VERM, OUTPUT);

  pinMode(SENSOR_TEMP, INPUT);

  Serial.begin(9600);
}

void loop() {
  // Exercício A
  /*digitalWrite(LED_AZUL, HIGH);
  delay(1000);
  digitalWrite(LED_AZUL, LOW);
  digitalWrite(LED_VERDE, HIGH);
  delay(1000);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_VERM, HIGH);
  delay(1000);
  digitalWrite(LED_VERM, LOW);
  */

  // Exercício B
  int leituraTemp = 0;
  float voltagem = 0;
  float temperatura = 0;

  // Fórmula para converter o valor para temperatura
  // Temperatura = (Vout - 500) / 10

  leituraTemp = analogRead(SENSOR_TEMP);
  Serial.println(leituraTemp);
  voltagem = leituraTemp * (5000 / 1024.0);
  temperatura = (voltagem - 500) / 10;

  switch (leituraTemp) {
    case 20:
      Serial.print("Temperatura:");
      Serial.println(temperatura);
      Serial.println("Menor valor possivel!");
      delay(2000);

      break;

    case 358:
      Serial.print("Temperatura: ");
      Serial.println(temperatura);
      Serial.println("Maior valor possivel!");
      break;

    default:
      if (temperatura < 10) {
        digitalWrite(LED_AZUL, HIGH);
        Serial.println("Temperatura menor que 10, LED AZUL ACESO!");
        delay(1000);
        digitalWrite(LED_AZUL, LOW);
      } else {
        if (temperatura >= 10 && temperatura < 30) {
          digitalWrite(LED_VERDE, HIGH);
          Serial.println("Temperatura entre 10 e 30, LED VERDE ACESO!");
          delay(1000);
          digitalWrite(LED_VERDE, LOW);

        } else {
          if (temperatura > 30) {
            digitalWrite(LED_VERM, HIGH);
            Serial.println("Temperatura maior 30, LED VERMELHO ACESO!");
            delay(1000);
            digitalWrite(LED_VERM, LOW);
          }
        }
      }
  }
}