#define chave 2
#define LED 3


void setup() 
{
  // configuração do microcontrolador
  // será executado uma única vez
   // configuração dos pinos de I/O digitais
  //pinMode(2,1);
  //pinMode(chave,1);
 pinMode(chave, INPUT);
 pinMode(LED, OUTPUT);
 Serial.begin(9600);
 }

bool entrada;
bool saida;
//variavel global

void loop()
{
entrada=digitalRead(chave);
//saida=entrada;
if(entrada==1)
{
  saida=1;
  Serial.println("Entrada acionada");
}
else
{
  saida=0;
  Serial.println("Entrada desacionada");
}
  digitalWrite(LED,saida);
  Serial.print("Estado do LED:");
  Serial.println(saida);
  }
