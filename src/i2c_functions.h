/*
 * i2c_functions.h
 *
 *  Created on: 23 Jul 2016
 *      Author: menadue
 */

#ifndef I2C_FUNCTIONS_H_
#define I2C_FUNCTIONS_H_

typedef unsigned char BYTE;

//--------------------------------------------------------------------------------

// I2C Port descriptor
typedef struct _I2C_PORT_DESC
{
  unsigned char sdaport;
  unsigned char sdabit;
  unsigned char sclport;
  unsigned char sclbit;
} I2C_PORT_DESC;

// Slave device descriptor
typedef struct _I2C_SLAVE_DESC
{
  I2C_PORT_DESC *port;             // Port the device is on
  unsigned char slave_7bit_addr;        // SLave address
} I2C_SLAVE_DESC;

// I2C functions
void i2c_release(I2C_PORT_DESC *port);
void i2c_delay(I2C_PORT_DESC *port);
void i2c_sda_low(I2C_PORT_DESC *port);
void i2c_sda_high(I2C_PORT_DESC *port);
void i2c_scl_low(I2C_PORT_DESC *port);
void i2c_scl_high(I2C_PORT_DESC *port);
void i2c_start(I2C_PORT_DESC *port);
void i2c_stop(I2C_PORT_DESC *port);
int i2c_send_byte(I2C_PORT_DESC *port, BYTE b);
int i2c_read_bytes(I2C_SLAVE_DESC *slave, int n, BYTE *data);
void i2c_send_bytes(I2C_SLAVE_DESC *slave, int n, BYTE *data);
#

#endif /* I2C_FUNCTIONS_H_ */
