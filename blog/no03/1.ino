void setup()
{
}
void loop()
{
    Serial.begin(115200); // 設定波長
    Serial.print("p:");
    Serial.println(analogRead(A0)); // 檢測類比訊號
    delay(1000);
}