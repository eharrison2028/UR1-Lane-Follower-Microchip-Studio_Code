/*
 * Final_Project_UR1.c
 *
 * Created: 4/25/2026 12:50:55 PM
 * Author : eharriso1
 */ 


#include "../../MRE_lib/F_cpu_lib.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>
#include "../../MRE_lib/LCD_lib.h"
#include "../../MRE_lib/A2D_lib.h"
#include "../../MRE_lib/Serial_lib2.h"
#include "../../MRE_lib/Motor_PWM_lib.h"


int main(void)
{
	MCUCR |= (1 << JTD);
	MCUCR |= (1 << JTD);
	LCD_init();
	LCDGoToPosition(1,1);
	char array[20];
	char decision;
	sprintf(array, "Hello World!!");
	LCDSendString(array);
	_delay_ms(2000);
	LCDClearScreen();
	//uint8_t serial_char_in;
	//char serial_char_array_out[20];
	DDRC |= 1 << PINC2;
	//sprintf(array, "Emma Harrison");
	//LCDSendString(array);
	//_delay_ms(2000);
	AD_init();
	USART_vInit();
	sei();
	HBridgeInit(); // define ports and set up 16 bit timer TCNT1
	//LCDClearScreen();
	DDRA &= ~((1<<DDA0)|(1<<DDA1));
	DDRB |= (1<<PINB7) | (1<<PINB6) | (1<<PINB5) | (1<<PINB4);
	uint8_t left = 0;
	uint8_t right = 1;
	uint8_t lspeed;
	uint8_t rspeed; 
	uint8_t forward = 0;
	uint8_t reverse = 1;
    /* Replace with your application code */
    while (1) 
    {
		decision = USART_vReceiveByte();
		
		sprintf(array, "Emma Harrison");
		LCDSendString(array);
		
		if (!decision)
		{
			decision = 0;
		}
		
		 //0 -> STOP
		 //1 -> FORWARD
		 //2 -> TURN RIGHT
		 //3 -> TURN LEFT
		 
		 //HBridgeCommand(uint8_t side, uint8_t speed, uint8_t direction);
		 // where side 0 = left motor, 1 = right
		 // speed = 0-100
		 // direction 0 = forward, 1 = reverse
		if(decision == '0') //STOP
		{
			lspeed = 0;
			rspeed = 0;
			
			HBridgeCommand(left,lspeed,forward);
			//_delay_ms(1000);
			HBridgeCommand(right,rspeed,forward);
			_delay_ms(10);
		}
		else if(decision == '1') //FORWARD
		{
			lspeed = 40;
			rspeed = 40;
			
			HBridgeCommand(left,lspeed,forward);
			//_delay_ms(1000);
			HBridgeCommand(right,rspeed,forward);
			_delay_ms(10);
		}
		else if(decision == '3') //TURN RIGHT
		{
			lspeed = 45;//65;
			rspeed = 0;//30;
			
			HBridgeCommand(left,lspeed,forward);
			//_delay_ms(1000);
			HBridgeCommand(right,rspeed,forward);
			_delay_ms(10);
		}
		else if(decision == '2') //TURN LEFT
		{
			lspeed = 0;//30;
			rspeed = 45;//65;
			
			HBridgeCommand(left,lspeed,forward);
			//_delay_ms(1000);
			HBridgeCommand(right,rspeed,forward);
			_delay_ms(10);			
		}
		else if(decision == '5') //more left
		{
			lspeed = 5;//20;
			rspeed = 65;
			
			HBridgeCommand(left,lspeed,forward);
			//_delay_ms(1000);
			HBridgeCommand(right,rspeed,forward);
			_delay_ms(10);
			
		}
		else if(decision == '4') //more right
		{
			lspeed = 65;
			rspeed = 5;//20;
			
			HBridgeCommand(left,lspeed,forward);
			//_delay_ms(1000);
			HBridgeCommand(right,rspeed,forward);
			_delay_ms(10);
			
		}
		
    }
}

