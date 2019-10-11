/* Includes ------------------------------------------------------------------*/
#include "cmsis_os.h"
#include <stdio.h>
#include "Board_GLCD.h"
#include "Board_ADC.h"
#include "GLCD_Config.h"

extern GLCD_FONT GLCD_Font_6x8;
extern GLCD_FONT GLCD_Font_16x24;

/* Private variables ---------------------------------------------------------*/
int adcValue;
int adcPercentage;
char adcString[5];

/* Private function prototypes -----------------------------------------------*/
void adcToString(int value);

int main (void)
{
	/* Initialize all configured peripherals */
	GLCD_Initialize();
	ADC_Initialize();
	
	/* Reset & Setup Screen */
	GLCD_ClearScreen();
  GLCD_SetBackgroundColor(GLCD_COLOR_LIGHT_GREY);
  GLCD_SetForegroundColor(GLCD_COLOR_WHITE);
  GLCD_SetFont(&GLCD_Font_16x24);
  GLCD_DrawString(0, 0*24, "     HCMIU - EE     ");
  GLCD_DrawString(0, 1*24, "    Embedded Lab    ");
  GLCD_SetBackgroundColor(GLCD_COLOR_WHITE);
  GLCD_SetForegroundColor(GLCD_COLOR_BLUE);
  GLCD_DrawString         (0, 2*24, "                    ");
	GLCD_DrawString         (0, 3*24, "                    ");
  GLCD_DrawString         (0, 4*24, " ADC value:         ");
  GLCD_DrawString         (0, 5*24, "                    ");
  GLCD_DrawString         (0, 6*24, "                    ");
  GLCD_DrawString         (0, 7*24, "                    ");
  GLCD_DrawString         (0, 8*24, "                    ");
  GLCD_DrawString         (0, 9*24, "                    ");
	GLCD_SetForegroundColor (GLCD_COLOR_RED);
	GLCD_DrawRectangle (2*16, 6*24, 16*16, 24);
  
	while (1)
	{
		/* Get values from ADC */
			ADC_StartConversion();
			adcValue = ADC_GetValue();
		
		/* Get values from ADC */
			if(adcValue != -1)
			{
				GLCD_SetForegroundColor (GLCD_COLOR_RED);
				adcToString(adcValue);
				/* Display ADC values */
				GLCD_DrawString(12*16, 4*24, adcString);
				adcPercentage = (adcValue * 100) / ((1 << ADC_GetResolution()) - 1);
				GLCD_DrawBargraph(2*16, 6*24,16*16,24, adcPercentage);
			}
			}
		}
	
		
void adcToString(int value)
{
	int i;
	for(i=0; i<4; i++)
	{
		adcString[3-i] = value % 10 + 48;
		value = value/10;
	}
	adcString[4] = 0;
}
