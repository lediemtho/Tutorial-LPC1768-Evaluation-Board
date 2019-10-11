/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "LPC17xx.h"
#include "cmsis_os.h"
#include "Led_OnOff.h"  /*--New library--*/
#include "Board_LED.h"
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

int main()
{
	/* Initialize all configured peripherals */
	LED_Initialize();
	
  int i;
	
	// Turn ON
	for(i=1;i<=9;i++)
	{
		Led_On(i);
		osDelay(1000);
	}
	
	// Turn OFF
	for(i=1;i<=9;i++)
	{
		Led_Off(i);
		osDelay(1000);
	}
	
}
