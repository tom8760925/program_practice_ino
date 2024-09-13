#include <esp_task_wdt.h>

void A(void *n){
  while(true){
    Serial.println("A");
  }
}
void B(void *n){
  while(true){
    Serial.println("B");
    yield();//退讓優先權，結果會大多都是B
    //taskYIELD();//重新確認優先權，結果大多都是Ｂ
    //vTaskDelay(1);//延遲，結果會大多都是Ａ
    //esp_task_wdt_reset();//重置wdt
  }
}
void setup() {
  Serial.begin(115200);
  //disableCore0WDT();//關閉wdt
  xTaskCreate(A/*函數*/,"A"/*描述*/,1000/*記憶體大小*/,NULL,1/*優先度*/,NULL);//建立任務
  xTaskCreate(B,"B",1000,NULL,2,NULL);
}
void loop() {
}