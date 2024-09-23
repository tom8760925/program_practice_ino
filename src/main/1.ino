const byte p = 18;
volatile bool state = LOW;
portMUX_TYPE mux = portMUX_INITIALIZER_UNLOCKED;
void IRAM_ATTR test()
{
    // state = !state;
    Serial.begin(115200); // 設定波長
    Serial.print("p1:");
    Serial.print(touchRead(p)); // 檢測類比訊號
    Serial.print(":");
    Serial.print(analogRead(p)); // 檢測類比訊號
    Serial.print(":");
    Serial.println(digitalRead(p)); // 檢測類比訊號
    /*
    portENTER_CRITICAL(&mux);

    Serial.begin(115200);//設定波長
    Serial.println(".");//檢測類比訊號
    portEXIT_CRITICAL(&mux); */
}
void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(p, OUTPUT);
    digitalWrite(p, LOW);
    attachInterrupt(p, test, RISING);
}
void loop()
{
    Serial.begin(115200); // 設定波長
    Serial.print("p:");
    Serial.print(touchRead(p)); // 檢測類比訊號
    Serial.print(":");
    Serial.print(analogRead(p)); // 檢測類比訊號
    Serial.print(":");
    Serial.println(digitalRead(p)); // 檢測類比訊號

    delay(1000);
}