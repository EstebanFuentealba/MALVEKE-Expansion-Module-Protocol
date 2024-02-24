#pragma once
#include <Arduino.h>

typedef struct {
    const uint8_t data[1024];
} frame_t;

void frame_init();

typedef enum {
    OrientationHorizontal = 0,
    OrientationHorizontalFlip = 1,
    OrientationVertical = 2,
    OrientationVerticalFlip = 3,
} Orientation;

void frame_parse_data(uint8_t orientation, const frame_t* frame, uint32_t timeout_ms);
