/*
 * i2c_exec.cpp
 *
 *  Created on: Oct 14, 2018
 *      Author: david
 */
#include <adi_processor.h>
#include "i2c_exec.h"



static enum i2c_state tx_state = eUNKNOWN;
static int tx_count = 0;
static int rx_count = 0;
static int tx_i = 0;
static int rx_i = 0;
static uint8_t tx_data[10] = {0};
static uint8_t rx_data[10] = {0};
static uint8_t address = 0;

void InitI2C()
{
	// Setup Clk to Ic2
	pADI_CLKCTL->CLKCON1&= 0xFF0F;
	CLKDIS_DISI2CCLK_BBA = 0;

	// Setup Pins to 0.1 - 0.2
	GP0OEN_OEN1_BBA = true;
	GP0OEN_OEN2_BBA = true;
	pADI_GP0->GPCON = (pADI_GP0->GPCON & ~GP0CON_CON2_MSK) | GP0CON_CON2_I2CSDA;
	pADI_GP0->GPCON = (pADI_GP0->GPCON & ~GP0CON_CON1_MSK) | GP0CON_CON1_I2CSCL;
    NVIC_DisableIRQ(I2CM_IRQn);


	tx_state = eINIT;
}


void InitTxData(uint32_t len, uint8_t *pData)
{
	for (uint32_t i = 0; i< len; i++ ) {
		tx_data[i] = pData[i];
	}

}

void GetRxData(uint32_t len, uint8_t *pData)
{
	for (uint32_t i = 0; i< len; i++ ) {
		pData[i] = rx_data[i];
	}

}

void StartTransfer(uint16_t addr, uint16_t tx_bytes, uint16_t rx_bytes)
{
	// Setup I2C master plus enable Rx and Tx interrupts
	pADI_I2C->I2CMCON = I2CMCON_IENTX | I2CMCON_MAS_EN;
	// Baud rate
	pADI_I2C->I2CDIV = 0x8F | (0x8E<<8);	  // 100kHz clock

    NVIC_DisableIRQ(I2CM_IRQn);
	tx_count = tx_bytes;
	rx_count = rx_bytes;
	rx_i = tx_i = 0;
	address = addr<<1;

    // purge fifos
    pADI_I2C->I2CFSTA |= 0x200;
    pADI_I2C->I2CFSTA &= 0xDFF;

    // Tx first data register data
    pADI_I2C->I2CMTX = tx_data[tx_i++];
    // Set address
    pADI_I2C->I2CADR0 = address;
    pADI_I2C->I2CADR1 = 0x00;
    tx_state = eTXING;
    int status = pADI_I2C->I2CMSTA;
    NVIC_EnableIRQ(I2CM_IRQn);

}


extern "C" void I2C0_Master_Int_Handler(void)
{

   NVIC_DisableIRQ(I2CM_IRQn);
//   for (volatile int j=0; j<10000; j++ ) {}
   int status = pADI_I2C->I2CMSTA;

   if (eTXING == tx_state) {
//	   if ((status &I2CMSTA_TXREQ) == I2CMSTA_TXREQ) {
	   if  ((status & 0x3) == 0x0) {
	 	if (tx_i >= tx_count) {

	 		tx_state = eRXING;
	     	pADI_I2C->I2CMCON =  I2CMCON_IENRX | I2CMCON_MAS_EN;
	         pADI_I2C->I2CMRXCNT = rx_count - 1;
	         pADI_I2C->I2CADR0 = address | 1;
	         pADI_I2C->I2CADR1 = 0x00;

	         NVIC_EnableIRQ(I2CM_IRQn);
	 	} else {
	 		pADI_I2C->I2CMTX = tx_data[tx_i++];
	 	}
	   } else if ((status & 0x3) == 0x2) {
		  // one byte in fifo, still wait
	      NVIC_EnableIRQ(I2CM_IRQn);
	   } else {
			tx_state = eDONE;
	   }
   }
   else if (eRXING == tx_state) {
	  if((status & I2CMSTA_RXREQ) == I2CMSTA_RXREQ) {

		rx_data[rx_i++] =  pADI_I2C->I2CMRX;
		NVIC_EnableIRQ(I2CM_IRQn);
		if (rx_i >= rx_count) {
			tx_state = eDONE;
		}
	  } else {
			tx_state = eDONE;
	  }
   } else {
		tx_state = eDONE;

   }
}
