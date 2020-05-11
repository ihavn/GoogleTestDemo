#include <stdio.h>

#include "myTask.h"
#include "FreeRTOS.h"
#include "task.h"

inline void myTaskFunction(void) {
	vTaskDelay(pdMS_TO_TICKS(200));
	puts("Hi from My Task");
}
// --------------------------------------------------------------------------------------
void taskMyTask(void* pvParameters)
{
	// Remove compiler warnings.
	(void)pvParameters;

	for (;;)
	{
		myTaskFunction();
	}
}