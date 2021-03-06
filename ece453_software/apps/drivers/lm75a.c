#include "../include/lm75a.h"

// File handle for I2C /dev entry
static int i2c_fh;

//*****************************************************************************
//*****************************************************************************
static void lm75a_set_slave_address(void)
{
	if (ioctl(i2c_fh, I2C_SLAVE, LM75A_SLAVE_ADDR) < 0) {
		perror("Error setting slave address");
		exit(1);
	}
}


//*****************************************************************************
//*****************************************************************************
void lm75a_open(void)
{
	i2c_fh = open(I2C_DEV, O_RDWR);
	if (i2c_fh < 0) {
		perror("i2c_open failed");
		exit(1);
	}

  // Set the slave address for the lm75a
  lm75a_set_slave_address();
}


//*****************************************************************************
//*****************************************************************************
void lm75a_close(void)
{
  close(i2c_fh);
}

//*****************************************************************************
// Reads the Temp Register
//*****************************************************************************
int16_t lm75a_read_temp(void)
{
  uint8_t reg0 = LM75A_REG_SELECT_TEMP;
  int8_t data;
  int16_t return_value;
  
  // ADD CODE
  lm75a_open();
  if (write(i2c_fh, &reg0, 1) != 1) {
	perror("Failed to set address register");
  }
  if (read(i2c_fh, &data, 1) != 1) {
	perror("Failed to read data");
  }
  //set upper bits
  return_value = data << 1;// >> 7;
/*
  if (write(i2c_fh, &reg1, 1) != 1) {
	perror("Failed to set address register");
  }
  if (read(i2c_fh, &data, 1) != 1) {
	perror("Failed to read data");
  }
  //set lower bits
  return_value += data;
*/
  lm75a_close();
  
  return return_value;  
}

//*****************************************************************************
// Reads the Product ID
//*****************************************************************************
uint8_t lm75a_read_product_id(void)
{
  uint8_t reg = LM75A_REG_SELECT_PRODUCT_ID;
  uint8_t data;
	
  if (write(i2c_fh, &reg, 1) != 1) {
	perror("Failed to set address registerr");
  }
  if (read(i2c_fh, &data, 1) != 1) {
	perror("Failed to read data");
  }
	
  return data;  
}

