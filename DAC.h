#ifndef DAC_H_
#define DAC_H_

#define CPU_FREQ 6000000
#define __delay_us(t_us) (__delay_cycles((((uint64_t)t_us)*CPU_FREQ) / 1000000))

#define MAX_VOLTAGE 330

#define SPI_CS BIT7
#define SPI_SCLK BIT5
#define SPI_COPI BIT6
#define SPI_PORT P1

void DAC_init(void);
void DAC_write(uint16_t spi_data);

#endif /* DAC_H_ */