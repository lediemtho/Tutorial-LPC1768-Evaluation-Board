/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "cmsis_os.h"
#include "Board_Joystick.h"
#include "Board_GLCD.h"
#include "GLCD_Config.h"

extern GLCD_FONT GLCD_Font_6x8;
extern GLCD_FONT GLCD_Font_16x24;

/* Private variables ---------------------------------------------------------*/
unsigned int JoystickStatus;

/* Private function prototypes -----------------------------------------------*/

int main (void)
{
	/* Initialize all configured peripherals */
	GLCD_Initialize();
	Joystick_Initialize();
	
	GLCD_ClearScreen();
  GLCD_SetBackgroundColor(GLCD_COLOR_LIGHT_GREY);
  GLCD_SetForegroundColor(GLCD_COLOR_WHITE);
  GLCD_SetFont(&GLCD_Font_16x24);
  GLCD_DrawString(0, 0*24, "     HCMIU - EE     ");
  GLCD_DrawString(0, 1*24, "    Embedded Lab    ");
  GLCD_SetBackgroundColor(GLCD_COLOR_WHITE);
  GLCD_SetForegroundColor(GLCD_COLOR_BLUE);
  GLCD_DrawString(0, 2*24, "                    ");
	GLCD_DrawString(0, 3*24, "                    ");
  GLCD_DrawString(0, 4*24, "                    ");
  GLCD_DrawString(0, 5*24, "Joystick:           ");
  GLCD_DrawString(0, 6*24, "                    ");
  GLCD_DrawString(0, 7*24, "                    ");
  GLCD_DrawString(0, 8*24, "                    ");
  GLCD_DrawString(0, 9*24, "                    ");
	
  while (1)
	{	
			JoystickStatus = Joystick_GetState();
		
			switch(JoystickStatus)
			{
				case JOYSTICK_UP:     GLCD_DrawString(10*16, 5*24, "UP    "); break;
				case JOYSTICK_DOWN:   GLCD_DrawString(10*16, 5*24, "DOWN  "); break;
				case JOYSTICK_LEFT:   GLCD_DrawString(10*16, 5*24, "LEFT  "); break;
				case JOYSTICK_RIGHT:  GLCD_DrawString(10*16, 5*24, "RIGHT "); break;
				case JOYSTICK_CENTER: GLCD_DrawString(10*16, 5*24, "CENTER"); break;
				default:              GLCD_DrawString(10*16, 5*24, "NONE  "); break;
			}
			
		}
	}
