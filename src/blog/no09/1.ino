void A(void *n){
  while(true){
    Serial.println("A");
    vTaskDelay(1000/portTICK_PERIOD_MS);//跟delay一樣，但使用Freertos時要使用vTaskDelay
  }
}
void B(void *n){
  while(true){
    Serial.println("B");
  }
}
void setup() {
  Serial.begin(115200);
  xTaskCreate(A/*函數*/,"A"/*描述*/,1000/*記憶體大小*/,NULL,1/*優先度*/,NULL);//建立任務
  xTaskCreate(B,"B",1000,NULL,2,NULL);
}
void loop() {
}