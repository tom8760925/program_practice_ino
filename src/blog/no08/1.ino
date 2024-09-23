#include <BluetoothSerial.h>

BluetoothSerial BT;

void setup() {
  Serial.begin(115200);
  BT.begin("xxx");//開啟藍牙，輸入藍牙名稱
}
void loop() {
  if (Serial.available()) {
    BT.write(Serial.read());
  }
  if (BT.available()) {
    Serial.println(BT.readString());
  }
  delay(50);
}