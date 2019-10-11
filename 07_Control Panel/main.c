/* Includes ------------------------------------------------------------------*/
#include "cmsis_os.h"
#include <stdio.h>
#include "Board_Joystick.h"
#include "Board_GLCD.h"
#include "GLCD_Config.h"

/* Private function prototypes -----------------------------------------------*/
extern void DisplayMenu(void);
extern void DisplayMenu01(void);
extern void DisplayMenu02(void);
extern void DisplayMenu03(void);
extern void DisplayMenu04(void);

/* Private variables ---------------------------------------------------------*/
int programIndex;

int main (void)
{
	/* Initialize all configured peripherals */
	GLCD_Initialize();
	Joystick_Initialize();
	programIndex = 0;
	while(1)
	{
		switch(programIndex)
		{
			case 0: DisplayMenu(); break;
			case 1: DisplayMenu01(); break;
			case 2: DisplayMenu02(); break;
			case 3: DisplayMenu03(); break;
			case 4: DisplayMenu04(); break;
			default: break;
		}
	}
}
