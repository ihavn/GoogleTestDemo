#pragma once
#include <stdint.h>
void hal_create(uint8_t portNo);
int16_t hal_getVoltage(uint8_t channel);
uint8_t foo(uint8_t x);