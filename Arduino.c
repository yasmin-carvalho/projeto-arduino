// biblioteca para o display LCD
#include <LiquidCrystal.h>

int trig = 9; // pino TRIG do sensor ultrassônico
int echo = 10; // pino ECHO do sensor ultrassônico
float tempo; // para armazenar o tempo de ida e volta do sinal em microssegundos
float distancia_cm; // para armazenar a distância em centímetros
int lampada = 6;
int buzzer = 7;

// inicialização do display LCD
// declare nome e inicialize a biblioteca com os números dos pinos utilizados para cada função//
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void alarme_lig(){
digitalWrite(lampada,1);
tone(buzzer,700);
delay(500);
digitalWrite(lampada,0);
tone(buzzer,900);
delay(500);
}
void alarme_des(){
digitalWrite(lampada,0);
noTone(buzzer);
}
void setup() {
Serial.begin(9600);
lcd.begin(16, 2);
// configura pino TRIG como saída
pinMode(trig,OUTPUT);
// deixa pino em LOW
digitalWrite(trig,LOW);
delayMicroseconds(10);

// configura pino ECHO como entrada
pinMode(echo,INPUT);
pinMode(lampada,OUTPUT);
pinMode(buzzer,OUTPUT);
}
void loop() {
// disparar pulso ultrassônico
digitalWrite(trig, HIGH);
digitalWrite(trig, LOW);
// medir tempo de ida e volta do pulso ultrassônico
tempo = pulseIn(echo, HIGH);// mudar a variável tempo do pulso para poder melhorar a precisão
// calcular as distâncias em centímetros
distancia_cm = tempo/29.4/2;

// apresentar resultados no display LCD
lcd.begin(20, 4);
lcd.setCursor(0,0);
lcd.print("Distancia: ");
lcd.setCursor(0,1);
lcd.print(distancia_cm);
lcd.print("cm");
lcd.setCursor(12,1);

// aguardar um pouquinho antes de começar tudo de novo
delay(200);

if (distancia_cm < 90)
{
alarme_lig();
}
else
{
alarme_des();
}

//teste
}