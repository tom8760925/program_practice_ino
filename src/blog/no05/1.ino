#include <WiFi.h>      //載入WIFI
#include <WebServer.h> //載入webserver

const char *ssid = "xxx";     // 設定ssid
const char *password = "xxx"; // 設定密碼
WebServer server(80);         // 設定port號

void h1()//網站內容
{
  String Html = "<p>11</p>";
  server.send(200, "text/html", Html);
}
void h2()//網站內容
{
  String state = server.arg("data");//get或post的內容
  String Html = "<p>" + state + "</p>";
  server.send(200, "text/html", Html);
}
void setup()
{
  Serial.begin(115200); // 設定波長
  WiFi.begin(ssid,password);     // 連接WIFI，如果沒有密碼就只要WiFi.begin(ssid);
  while (WiFi.status() != WL_CONNECTED)
  { // 測試是否連接
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("IP:");
  Serial.println(WiFi.localIP()); // 顯示IP
  server.on("/", h1);//網址跟網站內容
  server.on("/in", h2);//網址跟網站內容
  server.onNotFound([]()
                    {
      String Html ="<p>404</p>";
      server.send(404,"text/html",Html); });//錯誤網址顯示
  server.begin();//啟動網站
}
void loop()
{
  server.handleClient();//使用者端連線
}