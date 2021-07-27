#include <Wire.h>  //biblioteca inclusa a partir de sketch/incluit biblioteca/wire

#include <MAX30100.h> // //biblioteca inclusa a partir de sketch/incluit biblioteca/Max30100

#include <SHCSR04.h> //biblioteca inclusa a partir de sketch/incluit biblioteca/SHCSR04

#define LDR 6
#define reflet 13
#define infra 12
#define incl 9
#define LED1 30
#define LED2 31
#define LED3 32
#define LED4 33

MAX30100 pulsacao;
void setup()
{
  // put your setup code here, to run once:
pinMode(LDR, INPUT);
pinMode(reflet,INPUT);
pinMode(infra,INPUT);
pinMode(incl,INPUT);
pinMode(LED1,OUTPUT);
pinMode(LED2,OUTPUT);
pinMode(LED3,OUTPUT);
pinMode(LED4,OUTPUT);
Serial.begin(9600);
Wire.begin(); //abre comunicação com o wire
pulsacao.begin(pw1600,i50,sr100);

}
//variáveis globais
bool sensor1,sensor2,sensor3,sensor4;
bool saida1,saida2,saida3,saida4;
int analogico1;  //variável inteira para o A0 do sensor LDR
float tensao1,percentual1; //para converter o sinal analogico
int analogico2;  //variável inteira para o A1 do sensor microfone
float tensao2,percentual2;
SHCSR04 sensor5;
float ultrassonico;
void loop() 
{
  analogico1=analogRead(A0); //lê o valor analógico da entrada A0 do sensor LDR
 // Serial.println(analogico1);
    // put your main code here, to run repeatedly:
  analogico2=analogRead(A1);  //lê o valor analógico da entrada A1 do microfone
  sensor1=digitalRead(LDR); //sensor1 recebe a leitura do pino ao qual esta conectgado o LDR
  ultrassonico=sensor5.read(4,5); //read(trigger,echo) do sensor ultrassonico HCSR04
  //Serial.println(ultrassonico);
  pulsacao.readSensor();
  Serial.println(pulsacao.IR);
    
  //teste individual dos sensores:
  // Serial.println(sensor1); //print o conteúdo do sensor1 (s1=0 não há luz; s1=1 há luz)
  
  sensor2=digitalRead(reflet);
  //Serial.println(sensor2); //s2=1 escuro; s2=0 claro
  
  sensor3=digitalRead(infra);
  //Serial.println(sensor3); //s3=1 com papel, s3=0 sem papel
  
  sensor4=digitalRead(incl);
  //Serial.println(sensor4); // s4=1 sem contdato, s4=0 com contato

  //procesamento do sinal analogico vindo de A0
  //tensão1=5*analogico1/1023; ou
  tensao1=0.00488*analogico1; //converte o sinal analog1 em nível de tensão
  tensao2=0.00488*analogico2;  //converte o sinal analog2 em nível de tensão
 // Serial.print("Nível de tensão1: ");
 // Serial.println(tensao1);
 // Serial.print("Nível de tensão2: ");
 // Serial.println(tensao2);
  percentual1=(1-analogico1/1023.0)*100;
  percentual2=(1-analogico2/1023.0)*100;
  //Serial.print("Luminosidade em %: ");
 // Serial.println(percentual1);
  //Serial.print("som: ");
 // Serial.println(analogico2);
  
  if((sensor1||sensor2)&&(sensor3||sensor4))
      {
        saida1=1;
      }
      else
      {
        saida1=0;
      }
          if(sensor1||sensor2||sensor3||sensor4)
          {
            saida2=1;
          }
          else
          {
            saida2=0;
          }
              if(!(sensor1||sensor2)||(sensor3||sensor4))
              {
                saida3=1;
              }
              else
              {
                saida3=0;
              }
                  if(sensor1&&sensor2&&sensor3&&sensor4)
              {
                    saida4=1;
              }
                      else
                      {
                        saida4=0;
                      }
                 
  digitalWrite(LED1,saida1);
  digitalWrite(LED2,saida2);
  digitalWrite(LED3,saida3);
  digitalWrite(LED4,saida4);
  
  //Serial.println(saida1);
}
