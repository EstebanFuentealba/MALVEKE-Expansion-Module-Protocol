#include <Arduino.h>
#include "frame.h"
#include "uart.h"
#include "bitmaps.h"

// // #define RX_PIN 15  // Serial1 RX
// // #define TX_PIN 14  // Serial1 TX

void show_defaul_screen() {
    uint8_t* frame_buffer = (uint8_t*)calloc(FLIPPER_BITMAP_SIZE, sizeof(uint8_t));
    bitmap_xbm_to_screen_frame(
        frame_buffer, bitmap_default_screen, FLIPPER_SCREEN_WIDTH, FLIPPER_SCREEN_HEIGHT);
    frame_parse_data(OrientationHorizontal, (const frame_t*)frame_buffer, pdMS_TO_TICKS(1000));
    free(frame_buffer);
}

void init_module(void) {
    frame_init();
    // Serial1.begin(115200, SERIAL_8N1, RX_PIN, TX_PIN); // Iniciar el puerto UART (Serial1) para la comunicación con el módulo de expansión
    uart_protocol_init();
}

void setup() {
    init_module();
    show_defaul_screen();
}
void loop() {
    uart_on_rx();
}