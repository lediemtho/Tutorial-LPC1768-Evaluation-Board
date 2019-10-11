/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "LPC17xx.h"
#include "cmsis_os.h"
#include "Board_LED.h"
#include "Board_Buttons.h"
#include "GPIO_LPC17xx.h"

/* Private variables ---------------------------------------------------------*/
unsigned int ButtonStatus;

/* Private function prototypes -----------------------------------------------*/

int main(void)
{
	/* Initialize all configured peripherals */
	Buttons_Initialize();
	LED_Initialize();
	osKernelInitialize ();
	
	while(1)
		{
			ButtonStatus= Buttons_GetState();
			if(ButtonStatus==1)
				{
					GPIO_PinWrite (1, 28, 1);
					GPIO_PinWrite (1, 29, 1);
					GPIO_PinWrite (1, 31, 1);
					GPIO_PinWrite (2, 2, 1);
					GPIO_PinWrite (2, 3, 1);
					GPIO_PinWrite (2, 4, 1);
					GPIO_PinWrite (2, 5, 1);
					GPIO_PinWrite (2, 6, 1);
				}
				else
					{
					GPIO_PinWrite (1, 28, 0);
					GPIO_PinWrite (1, 29, 0);
					GPIO_PinWrite (1, 31, 0);
					GPIO_PinWrite (2, 2, 0);
					GPIO_PinWrite (2, 3, 0);
					GPIO_PinWrite (2, 4, 0);
					GPIO_PinWrite (2, 5, 0);
					GPIO_PinWrite (2, 6, 0);
					}
			
			
		}
}
