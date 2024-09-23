RTC_DATA_ATTR int wakes = 0;//使用RTC記憶體
void tai(){

}
void setup(){
  Serial.begin(115200);
  Serial.printf("p:%d\n",wakes);
  wakes++;
  delay(1000);
  Serial.println("ZZZ");
  delay(1000);
  touchAttachInterrupt(15,tai,40);//執行接觸中斷
  esp_sleep_enable_touchpad_wakeup();//執行接觸喚醒
  //esp_sleep_enable_timer_wakeup(5*1000000);//啟動定時喚醒
  //esp_light_sleep_start();//輕度睡眠
  esp_deep_sleep_start();//進入深度睡眠
}
void loop(){
}