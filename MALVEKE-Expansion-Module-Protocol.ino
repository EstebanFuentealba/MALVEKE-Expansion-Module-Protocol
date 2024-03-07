#include <Arduino.h>
#include "frame.h"
#include "uart.h"
#include "bitmaps.h"

#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>
#include <DNSServer.h>


AsyncWebServer server(80);
IPAddress _IP;

void show_defaul_screen() {
    uint8_t* frame_buffer = (uint8_t*)calloc(FLIPPER_BITMAP_SIZE, sizeof(uint8_t));
    bitmap_xbm_to_screen_frame(
        frame_buffer, bitmap_default_screen, FLIPPER_SCREEN_WIDTH, FLIPPER_SCREEN_HEIGHT);
    frame_parse_data(OrientationHorizontal, (const frame_t*)frame_buffer, pdMS_TO_TICKS(1000));
    free(frame_buffer);
}

void handleRoot(AsyncWebServerRequest *request) {
  request->send(200, "text/plain", "Hello from ESP32!");
}
void start_server() {
    WiFi.softAP("malveke_flpr", "12345678");
    _IP = WiFi.softAPIP();
    // default ip: 192.168.0.1
    // Configure route for streaming frames
    server.on("/", HTTP_GET, handleRoot);
    // Start the web server
    server.begin();
}
void init_module(void) {
    frame_init();
    uart_protocol_init();
}

void setup() {
    disableCore0WDT();  
    start_server();
    init_module();
    show_defaul_screen();
}
void loop() {
    uart_on_rx();
}