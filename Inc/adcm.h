#include<stdint.h>

#define GPIOAEN (1U<<0)
#define ADCEN (1U<<8)
#define PIN1 (1U<<1)
#define ADC_CHAN (1U<<0)
#define SEQ_ADC 0x00;
#define ADC_ON (1U<<0)
#define SOFT_START (1U<<30)
#define SR_EOC (1U<<1)
#define CR1_EOCIE (1U<<5)
void pa1_adc_init(void);
void start_conv(void);
uint32_t adc_read(void);
void pa1_adc_intr(void);
