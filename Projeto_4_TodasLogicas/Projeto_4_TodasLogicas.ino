#define chave1 10
#define chave2 11
#define LED 30

void setup() 
{
pinMode(chave1,INPUT);
pinMode(chave2, INPUT);
pinMode(LED,OUTPUT);
Serial.begin(9600); 

}
bool e(bool i1,bool i2); //cabeçalho da função
bool ou(bool i1,bool i2); //cabeçalho da função
bool naoe(bool i1,bool i2); //cabeçalho da função
bool naoou(bool i1,bool i2);//cabeçalho da função

void loop()
{
bool e1,e2,s1; 
 
e1=digitalRead(chave1);
e2=digitalRead(chave2);
s1=e(e1,e2);
 digitalWrite(LED,s1); 
}

bool e(bool i1,bool i2)  //execução da função
{
  bool o1;
  //logica AND
  if(i1 && i2 ==1)
  o1=1;
else
  o1=0;
return o1;
}

bool ou(bool i1,bool i2)  //execução da função
{
  bool o1;
  //logica OR
  if(i1 || i2 ==1)
  o1=1;
else
  o1=0;
return o1;
}

bool naoe(bool i1,bool i2)  //execução da função
{
  bool o1;
  //logica NAND
  if(!(i1 && i2) ==1)
  o1=1;
else
  o1=0;
return o1;
}

bool naoou(bool i1,bool i2)  //execução da função
{
  bool o1;
  //logica NOR
  if(!(i1 || i2) ==1)
  o1=1;
else
  o1=0;
return o1;
}
