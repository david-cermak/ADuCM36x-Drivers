/*
 * i2c_exec.h
 *
 *  Created on: Oct 14, 2018
 *      Author: david
 */

#ifndef SRC_INCLUDE_APPLICATIONS_I2C_EXEC_H_
#define SRC_INCLUDE_APPLICATIONS_I2C_EXEC_H_

enum i2c_state {
 eUNKNOWN,
 eINIT,
 eTXING,
 eRXING,
 eDONE
};

void InitI2C();

void InitTxData(uint32_t len, uint8_t *pData);
void GetRxData(uint32_t len, uint8_t *pData);
void StartTransfer(uint16_t addr, uint16_t tx_bytes, uint16_t rx_bytes);




#endif /* SRC_INCLUDE_APPLICATIONS_I2C_EXEC_H_ */
