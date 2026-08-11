/**********     INCLUDES        **********/
#include "error_handler.h"
#include "drivers/drivers.h"
/**********     TYPEDEFS         **********/

/**********		DEFINES		**********/
#define TASK_STACK_DEPTH		1000 / 4
/**********		EXTERNAL VARIABLE DEFINITIONS		**********/

/**********		STATIC VARIABLES		**********/
static char* prv_error_msg = NULL;
static SemaphoreHandle_t prv_new_error_smphr = NULL;	//The semaphore to start the task.
static StaticSemaphore_t prv_new_error_smphr_buf;		//Memory for the static semaphore above.
static StackType_t prv_task_stack[TASK_STACK_DEPTH];	//The static stack for the task.
static StaticTask_t prv_task_tcb;						//The TCB for the task.
static TaskHandle_t prv_task_handle;					//The task handle.

/**********		STATIC FUNCTION DECLRATIONS		**********/
static void error_handler_task();

/**********		STATIC FUNCTION DEFINITIONS		**********/
static void error_handler_task(void* arg)
{
	prv_new_error_smphr = xSemaphoreCreateBinaryStatic(&prv_new_error_smphr_buf);		//Should never fail.

	while(1)
	{
		xSemaphoreTake(prv_new_error_smphr, portMAX_DELAY);
//		/* Delete all other tasks. */
//		static TaskStatus_t tasks_arr[20];
//		const UBaseType_t task_arr_size = 20;
//		uint32_t* total_runtime = NULL;
//		UBaseType_t num_tasks = uxTaskGetSystemState(tasks_arr, task_arr_size, total_runtime);
//		for (uint32_t i = 0; i < num_tasks; i++)
//		{
//			TaskHandle_t this_handle = tasks_arr[i].xHandle;
//			if ((this_handle != prv_task_handle) && (strcmp("IDLE", tasks_arr[i].pcTaskName) != 0))
//			{
//				vTaskDelete(tasks_arr[i].xHandle);
//			}
//		}
//		sys_mem_set_config_data(prv_error_msg);
		rcc_sw_reset();
	}
}
/**********		GLOBAL FUNCTION DEFINITIONS		**********/
void error_handler_run()
{
	prv_task_handle = xTaskCreateStatic(error_handler_task, "ERR_HNDLR", TASK_STACK_DEPTH, NULL, 5, prv_task_stack, &prv_task_tcb);
}
BaseType_t error_handler_log_from_isr(char* log)
{
	BaseType_t higher_pri_task_woken = pdFALSE;
	prv_error_msg = log;
	xSemaphoreGiveFromISR(prv_new_error_smphr, &higher_pri_task_woken);
	return higher_pri_task_woken;
}
