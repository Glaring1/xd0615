#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5
#define LT 6
#define BT 7
String read = "";
int flag = 0;
int i = 0;
int k = 0;
int S[]={11,10,9,8};

void write(int a,byte b);
void setup()
{
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(S[0], OUTPUT);
  pinMode(S[1], OUTPUT);
  pinMode(S[2], OUTPUT);
  pinMode(S[3], OUTPUT);
  pinMode(LT,OUTPUT);
  pinMode(BT,OUTPUT);
  digitalWrite(LT,HIGH);
  digitalWrite(BT,HIGH);
  digitalWrite(S[0],HIGH);
  digitalWrite(S[1],HIGH);
  digitalWrite(S[2],HIGH);
  digitalWrite(S[3],HIGH);
}
void loop()
{
  if(Serial.available() > 0)
  {
    read = "";
  	while (Serial.available() > 0)  
    {
        read += char(Serial.read());
        delay(2);
    }
  }
  byte r[read.length()];
  for(i=0;i<read.length();i++)
  {
    r[i]=byte(read.charAt(i)-'0');
  }
  if(read.length()>4)
    if(k+3<read.length())
    {
      for(i=0;i<4;i++)
      	write(i,r[i+k]);
      k++;
      delay(500);
    }
    else
      k = 0;
  else
  {
    for(i=read.length();i>0;i--)
      write(read.length()-i,r[i-1]);
    delay(100);
  }
  
}
void write(int a,byte input)
{
  digitalWrite(S[a],LOW);
  digitalWrite(IN1,input&0x1);
  digitalWrite(IN2,(input>>1)&0x1);
  digitalWrite(IN3,(input>>2)&0x1);
  digitalWrite(IN4,(input>>3)&0x1);
  digitalWrite(S[a],HIGH);
}
