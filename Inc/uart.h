/*
 * uart.h
 *
 *  Created on: Nov 9, 2023
 *      Author: PRAJWAL HEGDE
 */

#ifndef UART_H_
#define UART_H_
#include<stdint.h>
#include <stm32f4xx.h>
#define GPIOAEN (1U<<0)
#define USART2EN (1U<<17)
#define SYS_CLK 16000000
#define BAUD_RATE 115200
#define PIN2 (1U<<2)
#define CR1_TE (1U<<3)
#define CR1_RE (1U<<2)
#define CR1_UE (1U<<13)
#define SR_TXE (1U<<7)
#define SR_RXNE (1U<<5)
static uint16_t compute_uart(uint32_t periphclk,uint32_t baudrate);
static void uart_set_baud(USART_TypeDef*USARTx,uint32_t periphclk,uint32_t baudrate);
char uart2_read(void);
void uart2_write(int charecter);
void uart2_tx_init(void);
void uart2_rxtx_init(void);

#endif /* UART_H_ */
