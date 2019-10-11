/* Includes ------------------------------------------------------------------*/
#include "cmsis_os.h"                       // ARM::CMSIS:RTOS:Keil RTX
#include "LPC17xx.h"  
#include "GPIO_LPC17xx.h"
#include "Board_LED.h"
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

int main(void)
{
	/* Initialize all configured peripherals */
	LED_Initialize();
	
	while(1)
		{
			/* Turn ON Leds */
			GPIO_PinWrite (1, 28, 1);
			osDelay(500);
			GPIO_PinWrite (1, 29, 1);
			osDelay(500);
			GPIO_PinWrite (1, 31, 1);
			osDelay(500);
			GPIO_PinWrite (2, 2, 1);
			osDelay(500);
			GPIO_PinWrite (2, 3, 1);
			osDelay(500);
			GPIO_PinWrite (2, 4, 1);
			osDelay(500);
			GPIO_PinWrite (2, 5, 1);
			osDelay(500);
			GPIO_PinWrite (2, 6, 1);
			osDelay(500);
			
			/* Turn ON Leds */
			GPIO_PinWrite (1, 28, 0);
			osDelay(500);
			GPIO_PinWrite (1, 29, 0);
			osDelay(500);
			GPIO_PinWrite (1, 31, 0);
			osDelay(500);
			GPIO_PinWrite (2, 2, 0);
			osDelay(500);
			GPIO_PinWrite (2, 3, 0);
			osDelay(500);
			GPIO_PinWrite (2, 4, 0);
			osDelay(500);
			GPIO_PinWrite (2, 5, 0);
			osDelay(500);
			GPIO_PinWrite (2, 6, 0);
			osDelay(500);	
			
		}
}
