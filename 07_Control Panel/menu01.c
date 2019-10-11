/* Includes ------------------------------------------------------------------*/
#include "Board_Joystick.h"
#include "Board_GLCD.h"
#include "GLCD_Config.h"

/* Private variables ---------------------------------------------------------*/
extern GLCD_FONT GLCD_Font_16x24;
extern int programIndex;

/* Private function prototypes -----------------------------------------------*/
void DisplayMenu01(void)
{
	int menu01Index = 0;
	int oldMenu01Index = -1;
	int isRunning01 = 1;
	int joystickStatus;
	char* menu11String=" Espresso           ";
	char* menu12String=" Latte              ";
	char* menu13String=" Cold Brew          ";
	
	GLCD_ClearScreen();
  GLCD_SetBackgroundColor(GLCD_COLOR_WHITE);
  GLCD_SetForegroundColor(GLCD_COLOR_PURPLE);
  GLCD_SetFont(&GLCD_Font_16x24);
	GLCD_DrawString(0, 0*24, "  ** EE Coffee **   ");
  GLCD_DrawString(0, 1*24, "  ***************   ");
	GLCD_DrawString(0, 2*24, "                    ");
	GLCD_SetBackgroundColor(GLCD_COLOR_WHITE);
	GLCD_SetForegroundColor(GLCD_COLOR_PURPLE);
	GLCD_DrawString(0, 3*24, "Menu 01: COFFEE     ");
	GLCD_DrawString(0, 4*24, "                    ");
	GLCD_SetBackgroundColor(GLCD_COLOR_WHITE);
	GLCD_SetForegroundColor(GLCD_COLOR_DARK_GREEN);
	GLCD_DrawString(0, 5*24, menu11String);
	GLCD_DrawString(0, 6*24, "                    ");
	GLCD_DrawString(0, 7*24, menu12String);
	GLCD_DrawString(0, 8*24, "                    ");
	GLCD_DrawString(0, 9*24, menu13String);

	
	while(isRunning01)
	{
		joystickStatus = Joystick_GetState();
		switch(joystickStatus)
		{
			case JOYSTICK_DOWN:
				if(menu01Index < 3)
				{
					menu01Index++;
				}
				break;
			case JOYSTICK_UP:
				if(menu01Index > 0)
				{
					menu01Index--;
				}
				break;
			case JOYSTICK_LEFT:
			  programIndex = 0;
			  isRunning01 = 0;
			  break;

		}
		if(Joystick_GetState()==JOYSTICK_CENTER)
			{
				GLCD_SetForegroundColor(GLCD_COLOR_RED);
			  GLCD_DrawString(0, 8*24, "              ORDER ");

			}
		
		if(menu01Index != oldMenu01Index)
		{
			if(oldMenu01Index>=0)
			{
				GLCD_SetBackgroundColor(GLCD_COLOR_WHITE);
	      GLCD_SetForegroundColor(GLCD_COLOR_DARK_GREEN);
				switch(oldMenu01Index)
				{
					case 0: GLCD_DrawString(0, 5*24, menu11String); break;
					case 1: GLCD_DrawString(0, 7*24, menu12String); break;
					case 2: GLCD_DrawString(0, 9*24, menu13String); break;

				}
			}
			oldMenu01Index = menu01Index;
		
			GLCD_SetBackgroundColor(GLCD_COLOR_WHITE);
			GLCD_SetForegroundColor(GLCD_COLOR_RED);
			switch(menu01Index)
			{
					case 0: GLCD_DrawString(0, 5*24, menu11String); break;
					case 1: GLCD_DrawString(0, 7*24, menu12String); break;
					case 2: GLCD_DrawString(0, 9*24, menu13String); break;
			}
		}
	}
	}
