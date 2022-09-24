#include "msp.h"
#include "DAC.h"
#include <math.h>

void DAC_init(void) {
    EUSCI_B0->CTLW0 |= EUSCI_B_CTLW0_SWRST;         // put the eUSCI into sowftware reset
    EUSCI_B0->CTLW0 = (EUSCI_B_CTLW0_MSB            // configure SPI
                    | EUSCI_B_CTLW0_MST
                    | EUSCI_B_CTLW0_MODE_0
                    | EUSCI_B_CTLW0_SYNC
                    | EUSCI_B_CTLW0_SSEL__SMCLK
                    | EUSCI_B_CTLW0_SWRST);
    EUSCI_B0->BRW = 0x01;                           // clock divider at 1

    SPI_PORT->SEL0 |= (SPI_SCLK | SPI_COPI);        // configure SPI pins
    SPI_PORT->SEL1 &= ~(SPI_SCLK | SPI_COPI);
    SPI_PORT->SEL0 &= ~(SPI_CS);                    // configure CS as GPIO
    SPI_PORT->SEL1 &= ~(SPI_CS);

    SPI_PORT->DIR |= (SPI_CS);
    SPI_PORT->OUT |= (SPI_CS);                      // active low, so initialize high

    EUSCI_B0->CTLW0 &= ~(EUSCI_B_CTLW0_SWRST);      // clear software reset
}

void DAC_write(uint16_t spi_data) {
    uint8_t loByte, hiByte;

    loByte = spi_data & 0xFF;                       // mask lower byte
    hiByte = (spi_data >> 8) & 0xFF;                // mask upper byte

    SPI_PORT->OUT &= ~(SPI_CS);                     // set CS low
    while(!(EUSCI_B0->IFG & EUSCI_B_IFG_TXIFG));    // wait for TXIFG to be set (TXBUF is empty)
        EUSCI_B0->TXBUF = hiByte;
    while(!(EUSCI_B0->IFG & EUSCI_B_IFG_TXIFG));    // wait for TXIFG to be set (TXBUF is empty)
        EUSCI_B0->TXBUF = loByte;
    while(!(EUSCI_B0->IFG & EUSCI_B_IFG_RXIFG));    // wait for RXIFG at end of transmission
        SPI_PORT->OUT |= (SPI_CS);                  // set CS high after transmission

    __delay_cycles(20);                             // delay after transmission
}