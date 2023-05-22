#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <LittleFS.h>

/* Название сети и пароль */
const char* ssid = "Снегоуборщик";       // SSID
const char* password = "12345678";  // пароль

/* Настройки IP адреса */
IPAddress local_ip(10,68,1,1);
IPAddress gateway(10,68,1,1);
IPAddress subnet(255,255,255,0);

ESP8266WebServer server(80); //Cоздаём сервер

void handleRoot() //Клиент делает запрос на сервер
{
    File html = LittleFS.open("/index.html", "r"); //Получаем html файл из файловой системы
    server.streamFile(html, "text/html");  //Отправляем html файл клиенту
}

void handleCss()  //Клиент запрашивает style.css
{
    File css = LittleFS.open("/style.css", "r");  //Получаем css файл из файловой системы
    server.streamFile(css, "text/css");  //Отправляем css файл клиенту
}

void setup() {
    Serial.begin(115200);
    /* Создаём точку доступа */
    WiFi.softAP(ssid, password);
    WiFi.softAPConfig(local_ip, gateway, subnet);
    delay(100);

    /* Подключаем файловую систему */
    LittleFS.begin();

    /* Настраиваем ответы сервера на запросы */
    server.on("/", handleRoot);
    server.on("/style.css", handleCss);
    
    server.on("/forward", []() {
        Serial.write('f');
      });
    server.on("/left", []() {
        Serial.write('l');
      });
    server.on("/right", []() {
        Serial.write('r');
      });
    server.on("/back", []() {
        Serial.write('b');
      });
    server.on("/brake", []() {
        Serial.write('s');
      });

    server.begin(); //Запускаем сервер
}

void loop() {
  server.handleClient();
}
