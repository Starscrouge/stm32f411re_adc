#include<stdint.h>
void pa1_adc_init(void);
void start_conv(void);
uint32_t adc_read(void);
void pa1_adc_intr(void);
