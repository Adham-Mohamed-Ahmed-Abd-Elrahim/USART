/*
 * USART.c
 *
 * Created: 22/06/2020 20:04:53
 *  Author: ADHM
 */ 
#include "USART.h"

void USART_MOOD(USART_COMMANDS Choice,USART_COMMANDS CLK_POL)
{switch(Choice)
	{//Choose USCRC TO WRITE IN IT INSTEAD OF UBRRH
		SET_BIT(UCSRC,URSEL);
		//ASYNC
		case ASYNC:
		//choosing async mode
		CLR_BIT(UCSRC,UMSEL);
		//Turn_off clock polarity*
		CLR_BIT(UCSRC,UCPOL);break;
		//SYNC
        case SYNC:
		//turn off double speed as it's only for async
		CLR_BIT(UCSRC,U2X);
		//choose sync mode
		SET_BIT(UCSRC,UMSEL);
		//T-RISE R-FALL
		if(CLK_POL==0){CLR_BIT(UCSRC,UCPOL);}
				//T-FALL R-RISE
		else{CLR_BIT(UCSRC,UCPOL);}
			break;
			default://choosing async mode
			CLR_BIT(UCSRC,UMSEL);
			//Turn_off clock polarity*
			CLR_BIT(UCSRC,UCPOL);break;
		
		}
		}
		//******************************************************************************************************************
	void USART_INI( USART_COMMANDS Baud_rate_mode,unsigned long baud)
	{//ENABLING RECIVING AND TRANSMITTING
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);
	//UCSRA=0b00000000;
	
	switch( Baud_rate_mode)
	{ case NORMAL ://USART_BAUDRATE*=16;  REG_VAL=BAUD_PRESCALE;break;
		UBRRL =BAUD_PRESCALE_NORMAL;CLR_BIT(UCSRC,URSEL);UBRRH = (BAUD_PRESCALE_NORMAL >> 8);		break;
	  case DOUBLE: UBRRL =BAUD_PRESCALE_DOUBLE;CLR_BIT(UCSRC,URSEL);UBRRH = (BAUD_PRESCALE_DOUBLE >> 8);break;
	  case SYNC: UBRRL =BAUD_PRESCALE_SYNC;CLR_BIT(UCSRC,URSEL);UBRRH = (BAUD_PRESCALE_SYNC>> 8);break;
		default:UBRRL =BAUD_PRESCALE_NORMAL;CLR_BIT(UCSRC,URSEL);UBRRH = (BAUD_PRESCALE_NORMAL >> 8);break;
	}
	//Writing REG_VAL to the UBRRL
	
	/*UBRRL =REG_VAL;CLR_BIT(UCSRC,URSEL);
		//Load lower 8-bits of the baud rate value 
	//choose ubrrh to write in instead of ucsrc
	CLR_BIT(UCSRC,URSEL);
	UBRRH = (REG_VAL >> 8);	// Load upper 8-bits
	*/

	}
	//*******************************************************************************************************
	void USART_TRASMIT(unsigned char data)
	{
		while (! (UCSRA & (1<<UDRE))); 
		//while(!(READ_BIT(UCSRA,UDRE)));
		UDR=data;
	}
	//*******************************************************************************************************
	unsigned char USART_RECIVE()
	{while ((UCSRA & (1 << RXC)) == 0);
		//while(!(READ_BIT(UCSRA,RXC)));
		return (UDR);
	}
	//*******************************************************************************************************
	void USART_DATA_SETTING( USART_COMMANDS num, USART_COMMANDS parity, USART_COMMANDS stop_bits)
	{//Choose USCRC TO WRITE IN IT INSTEAD OF UBRRH
		SET_BIT(UCSRC,URSEL);
		switch(num)
		{
			case FIVE :CLR_BIT(UCSRC,UCSZ0);CLR_BIT(UCSRC,UCSZ1);CLR_BIT(UCSRB,UCSZ2);break;
		    case SIX :SET_BIT(UCSRC,UCSZ0);CLR_BIT(UCSRC,UCSZ1);CLR_BIT(UCSRB,UCSZ2);break;
			case SEVEN :CLR_BIT(UCSRC,UCSZ0);SET_BIT(UCSRC,UCSZ1);CLR_BIT(UCSRB,UCSZ2);break;
			case EIGHT :SET_BIT(UCSRC,UCSZ0);SET_BIT(UCSRC,UCSZ1);CLR_BIT(UCSRB,UCSZ2);break;
			case NINE :SET_BIT(UCSRC,UCSZ0);SET_BIT(UCSRC,UCSZ1);SET_BIT(UCSRB,UCSZ2);break;
			default:SET_BIT(UCSRC,UCSZ0);SET_BIT(UCSRC,UCSZ1);SET_BIT(UCSRB,UCSZ2);break;
			
		}
		switch(parity)
		{//parity disable
			case NO_PARITY :CLR_BIT(UCSRC,UPM0);CLR_BIT(UCSRC,UPM1);break;
			//EVEN PARITY
			case EVEN_PARITY :CLR_BIT(UCSRC,UPM0); SET_BIT(UCSRC,UPM1);break;
			//ODD PARITY
			case ODD_PARITY :SET_BIT(UCSRC,UPM0);SET_BIT(UCSRC,UPM1);break;
			//default no parity 
			default:CLR_BIT(UCSRC,UPM0);CLR_BIT(UCSRC,UPM1);break;
		}
		switch(stop_bits)
		{case ONE:CLR_BIT(UCSRC,USBS);break;
		case TWO:SET_BIT(UCSRC,USBS);break;
		default:CLR_BIT(UCSRC,USBS);break;
			
		}
		
	}
//*******************************************************************************************************
/*inline uint8_t CHECK_PARITY()
{if(READ_BIT(UCSRC,UPM1))
{return((READ_BIT(UCSRA,PE)==1) ?  1: 0);
}
}
  
inline uint8_t CHECK_FRAME()
{return ((READ_BIT(UCSRA,FE)==1) ?  1: 0);
	
}
*/	


