#include <string.h>
#include "frame.h"

typedef struct {
    frame_t frame;
    uint8_t orientation;
} frame_data_t;

static frame_data_t current = {0};
static frame_data_t next = {0};

SemaphoreHandle_t data_mutex;

void frame_init() {
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