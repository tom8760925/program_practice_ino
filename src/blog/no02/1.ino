#include <ESP8266WiFi.h> //載入WIFI

const char *ssid = "xxx";     // 設定ssid
const char *password = "xxx"; // 設定密碼

void setup()
{
    Serial.begin(115200);       // 設定波長
    WiFi.begin(ssid, password); // 連接WIFI，如果沒有密碼就只要WiFi.begin(ssid);
    while (WiFi.status() != WL_CONNECTED)
    { // 測試是否連接
        delay(500);
        Serial.print(".");
    }
    Serial.println();
    Serial.print("IP:");
    Serial.println(WiFi.localIP()); // 顯示IP
    Serial.print("RSSI:");
    Serial.println(WiFi.RSSI()); // 顯示訊號強度
    Serial.println();
}
void loop()
{
    delay(2000);
    Serial.print("RSSI:");
    Serial.println(WiFi.RSSI());
}