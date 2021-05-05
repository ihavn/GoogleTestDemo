#include <stdio.h>
#include "myTask.h"
#include <FreeRTOS.h>
#include <task.h>

// --------------------------------------------------------------------------------------
inline void myTask_init() {
	// Initialisation code can be placed here
}

// --------------------------------------------------------------------------------------
inline void myTask_run(void) {
	vTaskDelay(pdMS_TO_TICKS(200));
	// Do something meaningful here
}

// --------------------------------------------------------------------------------------
void taskMyTask(void* pvParameters)
{
	// Remove compiler warnings.
	(void)pvParameters;

	myTask_init();

	for (;;)
	{
		myTask_run();
	}
}