#include "uart.h"
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
int uart_print(int charecter)
{
	uart2_write(charecter);
	return charecter;
}
void uart2_rxtx_init(void){
	RCC-> AHB1ENR |= GPIOAEN;
	GPIOA-> MODER &=~ (1U<<4);
	GPIOA-> MODER |=(1U<<5);
	GPIOA->MODER&=~(1U<<6);
	GPIOA->MODER|=(1U<<7);
	GPIOA-> AFR[0]|= (1U<<8);
	GPIOA-> AFR[0]|= (1U<<9);
	GPIOA-> AFR[0]|= (1U<<10);
	GPIOA-> AFR[0]&=~ (1U<<11);
	GPIOA-> AFR[0]|= (1U<<12);
	GPIOA-> AFR[0]|= (1U<<13);
	GPIOA-> AFR[0]|= (1U<<14);
	GPIOA-> AFR[0]&=~ (1U<<15);



	RCC-> APB1ENR |= USART2EN;
	uart_set_baud(USART2,SYS_CLK,BAUD_RATE);
	USART2->CR1 = (CR1_TE|CR1_RE);
	USART2->CR1 |= CR1_UE;

}

static uint16_t compute_uart(uint32_t periphclk,uint32_t baudrate)
{
	return((periphclk + (baudrate/2U))/baudrate);
}
static void uart_set_baud(USART_TypeDef*USARTx,uint32_t periphclk,uint32_t baudrate)
{
	USARTx->BRR = compute_uart(periphclk,baudrate);
}


void uart2_write(int charecter){
	while(!(USART2->SR & SR_TXE)){}
	USART2-> DR = (charecter & 0xFF);
}
char uart2_read(void){
	while(!(USART2->SR & SR_RXNE)){}
	return USART2-> DR;

}
