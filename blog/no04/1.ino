const byte p = 18;

void IRAM_ATTR ISRF(){
  Serial.begin(115200);//設定波長
  Serial.print("p:");
  Serial.print(digitalRead(p));//檢測訊號
  Serial.println(":FALLING");
}
void IRAM_ATTR ISRR(){
  Serial.begin(115200);//設定波長
  Serial.print("p:");
  Serial.print(digitalRead(p));//檢測訊號
  Serial.println(":RISING");
}
void IRAM_ATTR ISRC(){
  Serial.begin(115200);//設定波長
  Serial.print("p:");
  Serial.print(digitalRead(p));//檢測訊號
  Serial.println(":CHANGE");
}
void IRAM_ATTR ISRL(){
  Serial.begin(115200);//設定波長
  Serial.print("p:");
  Serial.print(digitalRead(p));//檢測訊號
  Serial.println(":LOW");
}
void IRAM_ATTR ISRH(){
  Serial.begin(115200);//設定波長
  Serial.print("p:");
  Serial.print(digitalRead(p));//檢測訊號
  Serial.println(":HIGH");
}
void setup()
{
  pinMode(p, OUTPUT);
  //attachInterrupt(p,ISRF,FALLING);//測下降
  //attachInterrupt(p,ISRR,RISING);//測上降
  //attachInterrupt(p,ISRC,CHANGE);//測下降上降
  //attachInterrupt(p,ISRL,LOW);//測低
  attachInterrupt(p,ISRH,HIGH);//測高
}
void loop()
{
  Serial.begin(115200);//設定波長
  Serial.print("p:");
  Serial.println(digitalRead(p));//檢測訊號
  delay(1000);
}