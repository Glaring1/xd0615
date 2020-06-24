void setup() 
{
  Serial.begin(9600);//首先我们设置波特率
  pinMode(2, INPUT_PULLUP);//将2管脚作为输入管脚bin并同时启用内部上拉电阻器。那么上拉电阻器在断路的时候，管脚就会变成高电平。当变成通路的时候，管脚变成低电平。
  pinMode(13, OUTPUT);//将13管脚作为输出管脚，连接13管脚与L灯，输出高电平时灯亮，输出低电平时灯灭
}
void loop() 
{
  int sensorVal = digitalRead(2);//该函数用来读取2管脚的电平状态，并将结果保存在sensorVal中
  Serial.println(sensorVal);//打印2管脚的电平状态  
  //如果2管脚为高电平，设置13管脚为低电平；否则设置13管脚为高电平
  if (sensorVal == HIGH) 
  {
    digitalWrite(13, LOW);
  } 
  else 
  {
    digitalWrite(13, HIGH);
  }
}
//当我们按下按钮时，电路连通，2管脚为低电平，则设置13管脚为高电平，观察到灯L亮
//当我们未按按钮时，电路中断，2管脚为高电平，则设置13管脚为低电平，观察到灯L灭
