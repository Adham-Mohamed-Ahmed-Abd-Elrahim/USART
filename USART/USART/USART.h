/*
 * USART.h
 *
 * Created: 22/06/2020 19:37:04
 *  Author: ADHM
 */ 


#ifndef USART_H_
#define USART_H_ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
		
#define BAUD_PRESCALE_NORMAL (((F_CPU)/(baud *16UL))-1)
#define BAUD_PRESCALE_DOUBLE (((F_CPU)/(baud *8UL))-1)
#define BAUD_PRESCALE_SYNC (((F_CPU)/(baud *2UL))-1)
#define SET_BIT(REG,INDX) ((REG) |=  (1<<(INDX)))
#define CLR_BIT(REG,INDX) ((REG) &= ~(1<<(INDX)))
#define READ_BIT(REG,INDX)	((REG>>INDX)&0x01)
typedef enum instruction {
	 ASYNC=1,
	 SYNC=2,
	//Clock polarity for sync default T-RISE R-FALL
	 NO_CLK=0,
	 T_RISE=0,
	 T_FALL=1,
	 R_FALL=0,
	 R_RISE=1,
	//PARITY
NO_PARITY=0,
	EVEN_PARITY=1,
	 ODD_PARITY=2,
	//Baud rate modes SYNC IS ALREADY 2
	 NORMAL=0,
	 DOUBLE=1,
	//baud rate
	 //BAUD=9600,
	//NUMBERS
	ONE=1,
	 TWO=2,
	 THREE=3,
	 FOUR=4,
	 FIVE=5,
	 SIX=6,
	 SEVEN=7,
	 EIGHT=8,
	 NINE=9,

} USART_COMMANDS;

//#define CHECK_FRAME    ((READ_BIT(UCSRA,FE)==1) ?  1: 0)
//#define  CHECK_PARITY  if(READ_BIT(UCSRC,UPM1)) ((READ_BIT(UCSRA,PE)==1) ?  1: 0)
//MODE
/*#define ASYNC  (1)
#define SYNC   2
//Clock polarity for sync default T-RISE R-FALL
#define NO_CLK	0
#define T_RISE   0
#define T_FALL   1
#define R_FALL   0
#define R_RISE   1
//PARITY 
#define NO_PARITY 0
#define EVEN_PARITY 1
#define ODD_PARITY 2
//Baud rate modes SYNC IS ALREADY 2
#define NORMAL 0
#define DOUBLE 1
//baud rate 
#define BAUD 9600
//NUMBERS
#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define SIX 6
#define SEVEN 7
#define EIGHT 8
#define NINE 9*/

//Choosing MOOD
void USART_MOOD( USART_COMMANDS Choice,USART_COMMANDS CLK_POL);
//Enabling rx/tx ,Setting baud rate
void USART_INI( USART_COMMANDS Baud_rate_mode,unsigned long baud );
//Setting number of data bits ,parity,start and stop bits 
void USART_DATA_SETTING( USART_COMMANDS num, USART_COMMANDS parity, USART_COMMANDS stop_bits);
//Check for errors [Parity error]
//inline uint8_t CHECK_PARITY();
//Check for errors [Frame error]
//inline uint8_t CHECK_FRAME();
//Transmitting Data
void USART_TRASMIT(unsigned char data);
//Receiving data
unsigned char USART_RECIVE();
//Causing interrupts 
void USART_INTERRUPT(uint8_t choice);




#endif /* USART_H_ */