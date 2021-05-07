#pragma once
#include "../../fff/fff.h"



extern "C" {
	// The simulated FreeRTOS header files belonging to the test project
#include "FreeRTOS.h" 
#include "task.h"
#include "semphr.h"
#include "queue.h"

	// Header file from the production code project
#include <MySecondTask.h>
}

// --- Declare mocks for FreeRTOS functions ---
// SemaphoreHandle_t xSemaphoreCreateBinary(void);
DECLARE_FAKE_VALUE_FUNC(SemaphoreHandle_t, xSemaphoreCreateBinary);
// void vTaskDelay( const TickType_t xTicksToDelay );
DECLARE_FAKE_VOID_FUNC(vTaskDelay, TickType_t);
//void vTaskDelayUntil(TickType_t* pxPreviousWakeTime, const TickType_t xTimeIncrement);
DECLARE_FAKE_VOID_FUNC(vTaskDelayUntil, TickType_t *, TickType_t);
// BasetType_t xSemaphoreGive( SemaphoreHandle_t xSemaphore );
DECLARE_FAKE_VALUE_FUNC(BaseType_t, xSemaphoreGive, SemaphoreHandle_t);
// QueueHandle_t xQueueCreate( UBaseType_t uxQueueLength, UBaseType_t uxItemSize );
DECLARE_FAKE_VALUE_FUNC(QueueHandle_t, xQueueCreate, UBaseType_t, UBaseType_t);
// BaseType_t xQueueSend(QueueHandle_t xQueue, const void* pvItemToQueue, TickType_t xTicksToWait);
DECLARE_FAKE_VALUE_FUNC(BaseType_t, xQueueSend, QueueHandle_t, const void *, TickType_t);
// BaseType_t xQueueReceive(QueueHandle_t xQueue, void* pvBuffer, TickType_t xTicksToWait);
DECLARE_FAKE_VALUE_FUNC(BaseType_t, xQueueReceive, QueueHandle_t, void *, TickType_t);
// TickType_t xTaskGetTickCount(void);
DECLARE_FAKE_VALUE_FUNC(TickType_t, xTaskGetTickCount);