#include <stdint.h>
#include "adcm.h"
#include "stm32f4xx.h"
#define GPIOAEN (1U<<0)
#define ADCEN (1U<<8)
#define PIN1 (1U<<1)
#define ADC_CHAN (1U<<0)
#define SEQ_ADC 0x00;
#define ADC_ON (1U<<0)
#define SOFT_START (1U<<30)
#define SR_EOC (1U<<1)
#define CR1_EOCIE (1U<<5)
void pa1_adc_init(void){
	RCC->AHB1ENR |= GPIOAEN;
	GPIOA->MODER|= (1U<<2);
	GPIOA->MODER|= (1U<<3);

	RCC->APB2ENR |= ADCEN;
	ADC1->SQR3= ADC_CHAN;
	ADC1->SQR1=SEQ_ADC;
	ADC1->CR2 |= ADC_ON;


}

void pa1_adc_intr(void){
	RCC->AHB1ENR |= GPIOAEN;
	GPIOA->MODER|= (1U<<2);
	GPIOA->MODER|= (1U<<3);

	RCC->APB2ENR |= ADCEN;
	ADC1->SQR3= ADC_CHAN;
	ADC1->SQR1=SEQ_ADC;
	ADC1->CR2 |= ADC_ON;
	ADC1->CR1 |= CR1_EOCIE;
	NVIC_EnableIRQ(ADC_IRQn);

}

void start_conv(void){
	ADC1->CR2 |= SOFT_START;
}
uint32_t adc_read(void){
	while(!(ADC1->SR&SR_EOC)){}
	return(ADC1->DR);
}
