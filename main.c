#include "../../MRE_lib/F_cpu_lib.h"
#include <avr/io.h>
#include "../../MRE_lib/Serial_lib2.h"

int main(void)
{
	MCUCR |= (1 << JTD);
	MCUCR |= (1 << JTD);

	DDRC |= (1 << PINC7);

	PORTC |= (1 << PINC7);
	_delay_ms(1000);
	PORTC &= ~(1 << PINC7);

	USART_vInit();

	while (1)
	{
		char decision = USART_vReceiveByte();

		if (decision == '1')
		{
			PORTC |= (1 << PINC7);
		}
		else if (decision == '0')
		{
			PORTC &= ~(1 << PINC7);
		}
	}
}