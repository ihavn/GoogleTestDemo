#include <stdio.h>

#include "myTask.h"
#include "FreeRTOS.h"
#include "task.h"

// --------------------------------------------------------------------------------------
void taskMyTask(void* pvParameters)
{
	// Remove compiler warnings.
	(void)pvParameters;

	// Initialisation code can be placed here

	for (;;)
	{
		vTaskDelay(pdMS_TO_TICKS(200));
		// Do something meaningful here
	}
}