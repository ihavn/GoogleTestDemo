#include "production.h"
#include "hal.h"
#include "my_utils.h"

#define HAL_PORT_NO 10

static uint16_t _last_voltage = 0;
/* ----------------------------------------------------------- */
void production_create(void) {
	hal_create(HAL_PORT_NO);
	foo(10);
	bar(4, 5);
}

/* ----------------------------------------------------------- */
void production_meassureTemperature(uint8_t sensorNo) {
	_last_voltage = hal_getVoltage(sensorNo);
}

/* ----------------------------------------------------------- */
int8_t production_getTemperature(uint8_t sensorNo) {
	return (int8_t)_last_voltage*2;
}