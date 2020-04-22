#pragma once
#include <stdint.h>

void production_create(void);
void production_meassureTemperature(uint8_t sensorNo);
int8_t production_getTemperature(uint8_t sensorNo);