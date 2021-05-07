#include "FreeRTOS_FFF_MocksDeclaration.h"
DEFINE_FFF_GLOBALS

// --- Create mocks for FreeRTOS functions ---
// // BaseType_t xQueueSend(QueueHandle_t xQueue, const void* pvItemToQueue, TickType_t xTicksToWait);
DEFINE_FAKE_VALUE_FUNC(BaseType_t, xQueueSend, QueueHandle_t, const void *, TickType_t);
// BaseType_t xQueueReceive(QueueHandle_t xQueue, void* pvBuffer, TickType_t xTicksToWait);
DEFINE_FAKE_VALUE_FUNC(BaseType_t, xQueueReceive, QueueHandle_t, void *, TickType_t);

// SemaphoreHandle_t xSemaphoreCreateBinary(void);
DEFINE_FAKE_VALUE_FUNC(SemaphoreHandle_t, xSemaphoreCreateBinary);
// void vTaskDelay( const TickType_t xTicksToDelay );
DEFINE_FAKE_VOID_FUNC(vTaskDelay, TickType_t);
//void vTaskDelayUntil(TickType_t* pxPreviousWakeTime, const TickType_t xTimeIncrement);
DEFINE_FAKE_VOID_FUNC(vTaskDelayUntil, TickType_t *, TickType_t);
// BasetType_t xSemaphoreGive( SemaphoreHandle_t xSemaphore );
DEFINE_FAKE_VALUE_FUNC(BaseType_t, xSemaphoreGive, SemaphoreHandle_t);
// QueueHandle_t xQueueCreate( UBaseType_t uxQueueLength, UBaseType_t uxItemSize );
DEFINE_FAKE_VALUE_FUNC(QueueHandle_t, xQueueCreate, UBaseType_t, UBaseType_t);
// TickType_t xTaskGetTickCount(void);
DEFINE_FAKE_VALUE_FUNC(TickType_t, xTaskGetTickCount);
