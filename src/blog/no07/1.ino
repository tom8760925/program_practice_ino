#include <SPIFFS.h> //載入SPIFFS

void wf()
{
    File file = SPIFFS.open("/test.txt", "w"); // 寫入檔案
    if (!file)
    { // 檢測是否打開
        Serial.println("p:w");
        return;
    }
    file.println("11"); // 寫入資料
    file.println("22"); // 寫入資料
    file.close();       // 關掉檔案
}
void rf()
{
    File file = SPIFFS.open("/test.txt", "r"); // 讀取檔案
    if (!file)
    { // 檢測是否打開
        Serial.println("p:r");
        return;
    }
    Serial.printf("size:%d\n", file.size()); // 檔案大小
    Serial.println("p:");
    while (file.available())
    {                              // 讀取檔案內容
        Serial.write(file.read()); // 讀取一行
    }
    file.close(); // 關掉檔案
}
void lf()
{
    File root = SPIFFS.open("/");    // 開啟根目錄
    File file = root.openNextFile(); // 開啟下一個檔案
    while (file)
    {
        Serial.printf("p:%s\n", file.name()); // 檔案名稱
        file = root.openNextFile();           // 開啟下一個檔案
    }
    file.close(); // 關掉檔案
}
void setup()
{
    Serial.begin(115200);
    if (!SPIFFS.begin(true))
    { // 掛載SPIFFS是否成功
        Serial.println("XXX");
    }
    wf();
    rf();
    lf();
    Serial.printf("p:%u\n", SPIFFS.totalBytes()); // 內容總共大小
    Serial.printf("p:%u\n", SPIFFS.usedBytes());  // 以使用內容大小
}
void loop()
{
}
