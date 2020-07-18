/*
 * USART.c
 *
 * Created: 22/06/2020 19:34:45
 * Author : ADHM
 */ 



#include "USART.h"
char message[6]="adham";

		uint16_t val;
		uint8_t ucsra;
		uint8_t x;
		char c;
int main(void)
{

	USART_INI(  NORMAL,9600);
	USART_MOOD(  ASYNC,   NO_CLK);
	USART_DATA_SETTING(  EIGHT,NO_PARITY,ONE);
	val=UBRRH;
	val=(val<<8);
	val=UBRRL;
	DDRD=0b00000010;
	ucsra=UCSRA;
	
    /* Replace with your application code */
    while (1) 
    {//c=USART_RECIVE();
	//	x=UDR;
	/*for(uint8_t i=0;i<5;i++)
	{USART_TRASMIT(message[i]);}*/
		
		c=USART_RECIVE();
USART_TRASMIT(c);
USART_TRASMIT('\n');
	
	}
	}

