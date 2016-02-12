#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "FS.h"

// Access point credentials
const char *ssid = "ESPap",
           *password = "123456789";

ESP8266WebServer server(80);

const int LED_PIN = LED_BUILTIN;
int ledStatus = HIGH;

void handleRoot() {
    // Just serve the index page from SPIFFS when asked for
    File index = SPIFFS.open("/index.html", "r");
    server.streamFile(index, "text/html");
    index.close();
}

// A function which sends the LED status back to the client
void sendStatus() {
    if (ledStatus == HIGH) server.send(200, "text/plain", "HIGH");
    else server.send(200, "text/plain", "LOW");
}

// Toggle the LED and back its status
void toggleLED() {
    ledStatus = ledStatus == HIGH ? LOW : HIGH;
    digitalWrite(LED_PIN, ledStatus);
    sendStatus();
}

void setup() {
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, ledStatus);

    SPIFFS.begin();

    // The IP will be 192.168.4.1
    WiFi.softAP(ssid, password);
    // The root handler
    server.on("/", handleRoot);
    // Handlers for various user-triggered events
    server.on("/toggle", toggleLED);
    server.on("/status", sendStatus);

    server.begin();
}

void loop() {
    server.handleClient();
}
