volatile unsigned int* PCLKSEL0 = (unsigned int*)0x400FC1A8;
	volatile unsigned int* PWM1CTCR = (unsigned int*)0x40018070;
	volatile unsigned int* PWM1TCR = (unsigned int*)0x40018004;
	volatile unsigned int* PWM1PR = (unsigned int*)0x4001800C;
	volatile unsigned int* PWM1MR0 = (unsigned int*)0x40018018;
	volatile unsigned int* PWM1MR1 = (unsigned int*)0x4001801C;
	volatile unsigned int* PWM1LER = (unsigned int*)0x40018050;
	volatile unsigned int* PWM1PCR = (unsigned int*)0x4001804C;
	
	volatile unsigned int* AD0CR = (unsigned int*) 0x40034000;
	volatile unsigned int* AD0DR2 = (unsigned int*) 0x40034018;
	volatile unsigned int* AD0DR1 = (unsigned int*) 0x40034014;
		
	volatile unsigned int* PINSEL4 = (unsigned int*)0x4002C010;

	volatile unsigned int* PWM1MCR = (unsigned int*) 0x40018014;
	
	volatile unsigned int* FIO0DIR = (unsigned int*) 0x2009C000;
	volatile unsigned int* PWM1IR = (unsigned int*) 0x40018000;
	volatile unsigned int* PCONP = (unsigned int*)0x400FC0C4;
	
	volatile unsigned int* PINSEL7 = (unsigned int*) 0x4002C01C;
	volatile unsigned int* FIO3DIR = (unsigned int*) 0x2009C060;
	volatile unsigned int* FIO3CLR = (unsigned int*) 0x2009C07C;


	volatile unsigned int* PINSEL1 = (unsigned int*)0x4002C004;
	
	volatile unsigned int* T0IR = (unsigned int*) 0x40004000;
	volatile unsigned int* T1IR = (unsigned int*) 0x40008000;

	volatile unsigned int* T0TCR = (unsigned int*) 0x40004004;
	volatile unsigned int* T1ICR = (unsigned int*) 0x40008004;
	volatile unsigned int* T0PR = (unsigned int*) 0x4000400C;
	volatile unsigned int* T0TC = (unsigned int*) 0x40004008;
	volatile unsigned int* T1TC = (unsigned int*) 0x40008008;
	
	volatile unsigned int* T0EMR = (unsigned int*) 0x4000403C;
	volatile unsigned int* T0MCR = (unsigned int*) 0x40004014;
	volatile unsigned int* T0MR0 = (unsigned int*) 0x40004018;
		volatile unsigned int* ISER0 = (unsigned int*) 0xE000E100;
		volatile unsigned int* ADGDR = (unsigned int*) 0x40034004;