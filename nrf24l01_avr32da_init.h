/*
 * @file nrf24l01_avr32da_init.h
 * @brief NRF24L01 Initialization Functions for AVR32DA28
 * @details Helper functions to initialize CE and IRQ GPIO for NRF24L01 module
 */

#ifndef __NRF24L01_AVR32DA_INIT_H_
#define __NRF24L01_AVR32DA_INIT_H_

#include <avr/io.h>
#include <util/delay.h>

/*
 * Initialize CE and IRQ pins for NRF24L01
 * Call this after SPI_Init() and before any NRF24L01 operations
 */
static inline void NRF24L01_GPIO_Init(void)
{
    /* Configure PA0 (CE - Chip Enable) as output */
    PORTA.DIRSET = PIN0_bm;
    PORTA.OUTCLR = PIN0_bm;  /* CE low (inactive) */

    /* Configure PA1 (IRQ) as input (optional, for interrupt mode) */
    PORTA.DIRCLR = PIN1_bm;

    _delay_us(100);
}

/*
 * Set CE (Chip Enable) pin high for RX or low for TX/Standby
 */
static inline void NRF24L01_CE_High(void)
{
    PORTA.OUTSET = PIN0_bm;
}

static inline void NRF24L01_CE_Low(void)
{
    PORTA.OUTCLR = PIN0_bm;
}

/*
 * Check IRQ pin state
 */
static inline uint8_t NRF24L01_IRQ_Read(void)
{
    return (PORTA.IN >> 1) & 1;
}

#endif /* __NRF24L01_AVR32DA_INIT_H_ */
