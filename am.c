#include "am.h"

void ADC_Init();

void PWM1_Init(unsigned int MR0, unsigned int MR1);

void Timer_Init();


int main(){
	*FIO0DIR = (unsigned int) (3 << 29);
	Timer_Init();
	ADC_Init();

	PWM1_Init(1667, 1000); 
	while(1)
	{
		
	}
}

void PWM1_Init(unsigned int MR0, unsigned int MR1){
	
	*PWM1TCR = 0;
	*PINSEL4 |= 1;
	*PINSEL4 &= ~(2);
	
	*PCLKSEL0 |= (1 << 12);
	*PCLKSEL0 &= ~(1 << 13);
	*PWM1PR = 0;
	*PWM1MR0 = MR0;
	*PWM1MR1 = MR1;
	*PWM1LER |= 3;
	
	*ISER0 |= 1 << 9;
	
	*PWM1MCR |= 11;
	
	*PWM1PCR |= (1 << 9);	
	
	
	
	*PWM1TCR |= 9;    
     
   
}



void PWM1_IRQHandler(){

	if(*PWM1IR & 1){
		// MR1
		
		*PWM1MR1 = (unsigned int) ( (float) ( (float) ((*ADGDR >> 4) & 0xFFF)/4095) * (float) *PWM1MR0);	
		if(*PWM1MR1 < 100){
			*PWM1MR1 = 1000;
		}
		*PWM1LER |= 3;		
		*PINSEL7 |= (1 << 19);
		
		*PWM1IR |= 1;

	}
	
	if(*PWM1IR & 2) {
		

		
		*PINSEL7 &= ~(1 << 19);		
		//FIODIR to output
		*FIO3DIR |= (1 << 25);
		//FIOCLR to drive low
		*FIO3CLR |= (1 << 25);
		

		*PWM1IR |= 2;
	}
}
void ADC_Init(){	
	volatile unsigned int* PCONP = (unsigned int*)0x400FC0C4;
volatile unsigned int* PCLKSEL0 = (unsigned int*)0x400FC1A8;
volatile unsigned int* PINSEL1 = (unsigned int*)0x4002C004;
//Power up the ADC by setting the correct bit in PCONP
*PCONP |= (1 << 12);
//Select the proper clock value for ADC (12.5 MHz) (see page 56 & 57).
*PCLKSEL0 |= (3 << 24);
//Select the AD0.2 function using PINSEL1 (see page 108). Bits 19:18 01
*PINSEL1 |= (1 << 18);
*PINSEL1 &= ~(1 << 19);
//Set the correct bits in AD0CR

*AD0CR |= 4;
*AD0CR |= (1 << 21);
*AD0CR |= (1 << 16); //Burst Mode
	
	
}


void Timer_Init()
{	
	//Power On Timer0
	*PCONP |= 2; 	
	//Set Peripheral Clock
	*PCLKSEL0 |= (1 << 2);	
	//Enable MAT0.0 External Register Port 3.25
	*PINSEL7 |= (1 << 19);	
	//Set Prescale
	*T0PR = 	(unsigned int) 1;
	//Set MR0 - Clock = 100 000 000 MhZ 
	// (1/ 800 000) = 125 * (1/100 000 000 )
	*T0MR0 = 40; 	
	//Reset Timer on MR0
	*T0MCR |= 1 << 1;	
	//External Match Toggle on MR0
	*T0EMR |= 3 << 4;
	
	*T0TCR |= 1;
}

