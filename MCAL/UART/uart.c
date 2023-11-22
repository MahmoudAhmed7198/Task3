/*
 * uart.c
 *
 *  Created on: Oct 28, 2023
 *      Author: Lenovo
 */
#include<avr/io.h>
#include"uart.h"
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 8UL))) - 1)


void UART_init(void)
{
	UCSRA = (1 << U2X);
	UCSRB = (1 << RXEN) | (1 << TXEN);
	UCSRC = (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);

	/* First 8 bits from the BAUD_PRESCALE inside UBRRL and last 4 bits in UBRRH*/
	UBRRH = BAUD_PRESCALE >> 8;
	UBRRL = BAUD_PRESCALE;
}

void UART_sendByte(const uint8_t data)
{
	while(BIT_IS_CLEAR(UCSRA,UDRE)){}
	UDR = data;

}

uint8_t UART_recieveByte(void)
{
	while(BIT_IS_CLEAR(UCSRA,RXC)){}
    return UDR;
}

void UART_sendString(const uint8_t *Str)
{
	uint8_t i = 0;
	while(Str[i] != '\0')
	{
		UART_sendByte(Str[i]);
		i++;
	}

}

void UART_receiveString(uint8_t *Str)
{
	uint8_t i = 0;
	Str[i] = UART_recieveByte();
	while(Str[i] != '#')
	{
		i++;
		Str[i] = UART_recieveByte();
	}
	Str[i] = '\0';
}
