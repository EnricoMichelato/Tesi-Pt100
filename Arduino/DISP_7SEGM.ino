int collegamenti[]={11,10,9,8},j=0;
float temp;
bool numeri[10][8]={{1,1,1,1,1,1,0,0},{0,1,1,0,0,0,0,0},{1,1,0,1,1,0,1,0},{1,1,1,1,0,0,1,0},{0,1,1,0,0,1,1,0},{1,0,1,1,0,1,1,0},{1,0,1,1,1,1,1,0},{1,1,1,0,0,0,0,0},{1,1,1,1,1,1,1,0},{1,1,1,1,0,1,1,0}};


void setup() {
  byte digitPins[] = {11,10,9,8,7,6,5,4,3,2,13,12};
  byte AnalogPins[]={A0};
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(A0,INPUT);
  //Serial.begin(9600);
}


void mostra_display(bool numero[]){
  int ii;
  ii=0;
  
  if(numero[ii]==true)
      digitalWrite(12,HIGH);
  else
      digitalWrite(12,LOW);
      
  ii=1;
  
  if(numero[ii]==true)
      digitalWrite(13,HIGH);
    else
      digitalWrite(13,LOW);

  ii=2;
  
  do{
    if(numero[ii]==true)
      digitalWrite(ii,HIGH);
    else
      digitalWrite(ii,LOW);
    ii++;
  }while(ii<=7);
}


void accendi(int digit){
  int ii;
  for(ii=3;ii>=0;ii--){
    if(ii!=digit)
      digitalWrite(collegamenti[ii],HIGH);
    else
      digitalWrite(collegamenti[ii],LOW);
  }
}


void mostra_numero(float num,int attesa){
  int numint=num*10;
  accendi(5);
  
  accendi(3);
  mostra_display(numeri[numint%10]);
  delay(attesa);
  accendi(2);
  mostra_display(numeri[(numint/10)%10]);
  digitalWrite(7,HIGH);
  delay(attesa);
  accendi(1);
  mostra_display(numeri[(numint/100)%10]);
  delay(attesa);
  accendi(0);
  mostra_display(numeri[(numint/1000)%10]);
  delay(attesa); 

  accendi(5);
}


void loop() {
  temp=-9.97377*(-27.3868 - (analogRead(A0)*5.000/1023.000))-273.15+3;
  //Serial.println(-9.97377*(-27.3868 - (analogRead(A0)*5.0/1023.0))-273.15);
  while(j<100){
    mostra_numero(temp,5);
    j++;
  }
  j=0;
   
}
