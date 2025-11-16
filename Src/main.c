#include <stdio.h>
#include <stdint.h>
#include <stm32f4xx.h>
#include "adcm.h"
#include "uart.h"
#define SR_EOC (1U<<1)
uint32_t sens_val;
int main(){
	uart2_rxtx_init();
	pa1_adc_intr();
	start_conv();

	while(1){

	}
}
static void adc_callback(void){

	sens_val = 	ADC1->DR ;
	printf("sensor value is %ld",sens_val);
}
void ADC_IRQHandler(void){
	if((ADC1->SR&SR_EOC)!=0){
		/*clear eoc after conversion*/
		ADC1->SR &=~ SR_EOC;
		adc_callback();

	}


}
/*interrupt occurs when conversion is complete
 * rather than converting inside a while loop waiting for conv*/

