#include <LPC21xx.H>
#include "led.h"


#define LED0_bm (1<<16)
#define LED1_bm (1<<17)
#define LED2_bm (1<<18)
#define LED3_bm (1<<19)



void Delay1(int iMilisekundy){
        int iDelayCounter;
        for(iDelayCounter = 0; iDelayCounter < (5455*iMilisekundy) ; iDelayCounter++);
}



void LedInit(void){

	IO1DIR = IO1DIR | (LED0_bm | LED1_bm | LED2_bm | LED3_bm);
	IO1SET = LED0_bm;
}

void LedOn(unsigned char ucLedIndeks){
		IO1CLR = (LED0_bm | LED1_bm | LED2_bm | LED3_bm);	
		switch(ucLedIndeks){
			case 0:
				IO1SET = LED0_bm;
				break;
			case 1:
				IO1SET = LED1_bm;
				break;
			case 2:
				IO1SET = LED2_bm;
				break;
			case 3:
				IO1SET = LED3_bm;
				break;
			}
}


enum eDirection {LEFT, RIGHT};
void LedStep(eDirection){
		
	static unsigned int uiLedMove;
	
	switch(eDirection){
		
		case LEFT:
				uiLedMove = (uiLedMove+1) %4;
				break;		
		case RIGHT:
				uiLedMove = (uiLedMove-1) %4;
				break;
	}
		LedOn(uiLedMove);
}
	




void LedStepLeft(void){
	LedStep(LEFT);
	Delay1(250);
}

void LedStepRight(void){
	LedStep(RIGHT);
	Delay1(250);
}



