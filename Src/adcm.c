#include <stdint.h>
#include "adcm.h"
#include "stm32f4xx.h"

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
