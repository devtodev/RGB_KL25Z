
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/

/* Begin of <includes> initialization, DO NOT MODIFY LINES BELOW */

#include "TSK1.h"
#include "FRTOS1.h"
#include "frtos_tasks.h"

/* End <includes> initialization, DO NOT MODIFY LINES ABOVE */

#include "HMI.h"

static portTASK_FUNCTION(HMITask, pvParameters) {

  int i;
  for(;;) {
    for (i = 0; i < 8; i++)
    {
    	setLed(i);
	    vTaskDelay(1000/portTICK_RATE_MS);
    }
  }

  /* Destroy the task */
  vTaskDelete(HMITask);
}

void CreateTasks(void) {
  if (FRTOS1_xTaskCreate(
     HMITask,  /* pointer to the task */
      "HMI", /* task name for kernel awareness debugging */
      configMINIMAL_STACK_SIZE + 1024, /* task stack size */
      (void*)NULL, /* optional task startup argument */
      tskIDLE_PRIORITY + 0,  /* initial priority */
      (xTaskHandle*)NULL /* optional task handle to create */
    ) != pdPASS) {
      /*lint -e527 */
      for(;;){}; /* error! probably out of memory */
      /*lint +e527 */
  }
}

