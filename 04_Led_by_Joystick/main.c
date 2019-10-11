/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "cmsis_os.h"
#include "Board_Joystick.h"
#include "GPIO_LPC17xx.h"
#include "Board_LED.h"
/* Private variables ---------------------------------------------------------*/
unsigned int joystickStatus;

/* Private function prototypes -----------------------------------------------*/

int main (void)
{
	/* Initialize all configured peripherals */
	Joystick_Initialize();
	LED_Initialize();
	
  while (1)
	{
			joystickStatus = Joystick_GetState();
			switch(joystickStatus)
			{
				case JOYSTICK_UP: GPIO_PinWrite (1, 28, 1);
					break;
				case JOYSTICK_DOWN: GPIO_PinWrite (1, 29, 1);
					break;
				case JOYSTICK_LEFT: GPIO_PinWrite (1, 31, 1);
				break;
				case JOYSTICK_RIGHT: GPIO_PinWrite (2, 2, 1);
				break;
				case JOYSTICK_CENTER: GPIO_PinWrite (2, 3, 1);
				break;

			}
			
		}
	}
