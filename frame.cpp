#include <string.h>
#include <ESPAsyncWebServer.h>
#include "frame.h"
#include "bmp.h"

#define FRAME_WIDTH 320
#define FRAME_HEIGHT 240

#define WIDTH 128
#define HEIGHT 64

#define COLOR_BG 0xFC00
#define COLOR_FG 0x0000

#define COLOR_RED 0xF800
#define COLOR_GREEN 0x07E0
#define COLOR_BLUE 0x001F

bool orientation_enable = false;

uint16_t color_bg = COLOR_BG;
uint16_t color_fg = COLOR_FG;

typedef struct {
    frame_t frame;
    uint8_t orientation;
} frame_data_t;

static frame_data_t current = {0};
static frame_data_t next = {0};

SemaphoreHandle_t data_mutex;

extern AsyncWebServer server;

// 16bpp

unsigned char bmpBuffer[BMP_SIZE(WIDTH, HEIGHT)];


void drawPixel(void* bmp, int x, int y, unsigned long color) {
    bmp_set(bmp, x, y, color);
}


void handleStreamRequest(AsyncWebServerRequest *request) {

    if (xSemaphoreTake(data_mutex, pdMS_TO_TICKS(200)) == pdTRUE) {
        memcpy(&current, &next, sizeof(frame_data_t));
        current.orientation = next.orientation;
        // Libera el mutex después de copiar los datos
        xSemaphoreGive(data_mutex);
    }


    
    bmp_init(bmpBuffer, WIDTH, HEIGHT);

    // Fill the background with orange
    unsigned long orange = bmp_encode(0xFF8201);
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            drawPixel(bmpBuffer, x, y, orange);
        }
    }

    // Draw the pixels
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            int i = (y / 8) * WIDTH + x;
            int z = y & 7;
            unsigned long color;
            if (current.frame.data[i] & (1 << z)) {
                color = bmp_encode(0x000000);
            } else {
                color = orange;
            }
            drawPixel(bmpBuffer, x, y, color);
        }
    }


    AsyncWebServerResponse *response = request->beginResponse_P(200, "image/bmp", (uint8_t*)bmpBuffer, sizeof(bmpBuffer));

    response->addHeader("Content-Type", "image/bmp");
    response->addHeader("Content-Disposition", "inline; filename=frame.bmp");
    response->addHeader("Connection", "close");
    
    request->send(response);
}

void frame_init() {
    server.on("/stream", HTTP_GET, handleStreamRequest);

    //  TODO:
    data_mutex = xSemaphoreCreateMutex();
    
}

void frame_parse_data(uint8_t orientation, const frame_t* frame, uint32_t timeout_ms) {
    if (xSemaphoreTake(data_mutex, pdMS_TO_TICKS(timeout_ms)) == pdTRUE) {
        memcpy(&next.frame, frame, sizeof(frame_t));
        next.orientation = orientation;
        xSemaphoreGive(data_mutex);
    }
}