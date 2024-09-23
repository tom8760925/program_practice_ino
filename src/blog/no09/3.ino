TaskHandle_t thb = NULL;//任務參照
void A(void *n){
  while(true){
    Serial.print("A:");
    Serial.println(i);
    i++;
    if(i >= 50){
      vTaskPrioritySet( thb , 3);//設定優先度
    }
    yield();
  }
}
void B(void *n){
  while(true){
    Serial.print("B:");
    Serial.print(i);
    Serial.print(":");
    Serial.println(uxTaskPriorityGet(thb));//取得優先度
    if(i>=60){
      vTaskDelete(thb);//刪除任務
    }
    yield();
  }
}
void setup() {
  Serial.begin(115200);
  Serial.println("............");
  xTaskCreate(A/*函數*/,"A"/*描述*/,1000/*記憶體大小*/,NULL,2/*優先度*/,NULL);//建立任務
  xTaskCreate(B,"B",1000,NULL,1,&thb);
}
void loop() {
}