#include "GPIO_LPC17xx.h"
#include "Led_OnOff.h"

void Led_On( int index) 
	{
		switch(index)
			{
			case 1:
				GPIO_PinWrite (1, 28, 1);
  		break;
			case 2:
				GPIO_PinWrite (1, 29, 1);
			break;
			case 3:
				GPIO_PinWrite (1, 31, 1);
			break;
			case 4:
				GPIO_PinWrite (2, 2, 1);
			break;
			case 5:
				GPIO_PinWrite (2, 3, 1);
			break;
			case 6:
				GPIO_PinWrite (2, 4, 1);
			break;
			case 7:
				GPIO_PinWrite (2, 5, 1);
			break;
			case 8:
				GPIO_PinWrite (2, 6, 1);
			break;
			default:
			break;
		}
			
	}

void Led_Off( int index) 
	{
		switch(index){
			case 1:
				GPIO_PinWrite (1, 28, 0);
			break;
			case 2:
				GPIO_PinWrite (1, 29, 0);
			break;
			case 3:
				GPIO_PinWrite (1, 31, 0);
			break;
			case 4:
				GPIO_PinWrite (2, 2, 0);
			break;
			case 5:
				GPIO_PinWrite (2, 3, 0);
			break;
			case 6:
				GPIO_PinWrite (2, 4, 0);
			break;
			case 7:
				GPIO_PinWrite (2, 5, 0);
			break;
			case 8:
				GPIO_PinWrite (2, 6, 0);
			break;
			default:
			break;
		}
}
