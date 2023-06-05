#include <LPC213X.H>
#include "led.h"
#include "keyboard.h"

void Delay(int iMilisekundy){
        int iDelayCounter;
        for(iDelayCounter = 0; iDelayCounter < (5455*iMilisekundy) ; iDelayCounter++);
}

int main(){
	enum LedState{LED_STOP, LED_RIGHT, LED_LEFT};
	enum LedState eLedState = LED_STOP;
	//int iCounter;

	LedInit();
	KeyboardInit();
	while(1){
						
		switch(eLedState){
			
			case LED_STOP:
				if(KeyboardRead()== BUTTON_0){
					eLedState=LED_LEFT;
				}
				else if(KeyboardRead()==BUTTON_2){
					eLedState=LED_RIGHT;
				}
				else{	
					eLedState = LED_STOP;
				}
				break;
								
			case LED_RIGHT:
				if(KeyboardRead()== BUTTON_1){
					eLedState=LED_STOP;}
				else{	
					LedStepRight();
				}
				break;
							
			case LED_LEFT:
				if(KeyboardRead()==BUTTON_1){
					eLedState=LED_STOP;}
				else{
					LedStepLeft();
				}
				break;
				
			default:
				break;
			}
		Delay(100);
	}
}




		
		
		
		
		
		
		
		
		

