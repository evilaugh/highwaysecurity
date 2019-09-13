int trigPin1 =2;
int echoPin1 =3;
int trigPin2 =4;
int echoPin2 =5;
int led1 =13;
int led2 =12;
int led3=11;
int led4=10;
int led5=9;
int led6=8;
void setup()
{
  Serial.begin(9600); 
   pinMode(led1, OUTPUT);
   pinMode(led2,OUTPUT);
   pinMode(led3,OUTPUT);
   pinMode(led4,OUTPUT);
   pinMode(led5,OUTPUT);
   pinMode(led6,OUTPUT);
   pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2,OUTPUT);
  pinMode(echoPin2,INPUT);
}
int ca=0;
int da=0;
int cb=0;
int db=0;
long calc(int trigpin,int echopin)
{
    long duration, d;
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigpin, LOW);
  duration=pulseIn(echopin, HIGH);
  d =(duration/2)/29.1;
  return(d);  
}
void loop() 
{
  int d1;
 int d2;
 d1=calc(2,3);

  digitalWrite(led1,HIGH);
if((d1<16.5)&&(d1>0))
{ 
   digitalWrite(led2,HIGH);
  digitalWrite(led1,LOW); 
  ca++;
  }
  if(ca>0)
  digitalWrite(led1,LOW);
  d2=calc(4,5);
   digitalWrite(led6,HIGH); 
  if((d2>=16.5)&&(d2<34))
{
  digitalWrite(led6,LOW);
  digitalWrite(led4,HIGH);
  da++;
  }
  if(da>0)
  digitalWrite(led6,LOW);
  // For SECOND OF BOTH THE TRACKS
  if((d1>=16.5)&&(d1<34))
{
  digitalWrite(led4,LOW);
  digitalWrite(led3,HIGH);
  db++;
}
  
if((d2<16.5)&&(d2>0))
{ 
   digitalWrite(led5,HIGH);
  digitalWrite(led2,LOW);
  cb++; 
}
}
