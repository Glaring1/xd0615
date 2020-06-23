#define IN1 7
#define S1 3
#define S2 4
#define S3 5
#define S4 6
#define LT 9
#define BT 8
int pinInterrupt=2;
int tick = 0;
void myfunc(){
   tick=-1;
   }

void setup()
{
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(S4, OUTPUT);
  pinMode(LT,OUTPUT);
  pinMode(BT,OUTPUT);
  digitalWrite(LT,HIGH);
  digitalWrite(BT,HIGH);
  digitalWrite(S1,HIGH);
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  digitalWrite(S4,HIGH);
  digitalWrite(IN1,LOW);
  attachInterrupt( digitalPinToInterrupt(pinInterrupt), myfunc,CHANGE); 
 
}
 void loop()
{   
    for(tick=0;tick<10; tick++){   
    if(tick==10) tick=0; 
    byte command=(byte)tick;
    digitalWrite(3,command&0x1);
    digitalWrite(4,(command>>1)&0x1);
    digitalWrite(5,(command>>2)&0x1);
    digitalWrite(6,(command>>3)&0x1);
     Serial.print("Number: ");
     Serial.println(tick);
    delay(1000);
  
  }
  
 }
