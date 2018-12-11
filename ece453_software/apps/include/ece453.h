/*
 */

#ifndef __ECE453_APP_H__
#define __ECE453_APP_H__

#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>

#include "buttons.h"
#include "electro_mag.h"
#include "leds.h"
#include "num_gen.h"
#include "stepper_control.h"
#include "stepper.h"
#include "stepper_move.h"
#include "lcd.h"
#include "decoder.h"

#define DEVICE_ID_REG 		"/sys/kernel/ece453/device_id"
#define GPIO_IN_REG	 	"/sys/kernel/ece453/gpio_in"
#define GPIO_OUT_REG		"/sys/kernel/ece453/gpio_out"
#define CONTROL_X_REG		"/sys/kernel/ece453/control_x"
#define STEP_COUNT_X_REG	"/sys/kernel/ece453/step_count_x"
#define STEP_PERIOD_X_REG	"/sys/kernel/ece453/step_period_x"
#define IM_REG			"/sys/kernel/ece453/interrupt_mask"
#define IRQ_REG			"/sys/kernel/ece453/irq"
#define PID_REG			"/sys/kernel/ece453/pid"
#define CONTROL_Y_REG		"/sys/kernel/ece453/control_y"
#define STEP_COUNT_Y_REG	"/sys/kernel/ece453/step_count_y"
#define STEP_PERIOD_Y_REG	"/sys/kernel/ece453/step_period_y"
#define ELECTRO_MAG_REG		"/sys/kernel/ece453/electro_mag"
#define LEDS_REG		"/sys/kernel/ece453/leds"
#define BUTTONS_REG		"/sys/kernel/ece453/buttons"
#define SWITCHES_REG		"/sys/kernel/ece453/switches"
#define STATUS_REG		"/sys/kernel/ece453/status"

//*******************************************************************
// Register Addresses
//*******************************************************************
#define ECE453_DEV_ID_OFFSET        0
#define ECE453_GPIO_IN_OFFSET       1
#define ECE453_GPIO_OUT_OFFSET      2
#define ECE453_CONTROL_X_OFFSET     3
#define ECE453_STEP_COUNT_X_OFFSET  4
#define ECE453_STEP_PERIOD_OFFSET   5
#define ECE453_IM_OFFSET            6
#define ECE453_IRQ_OFFSET           7
#define ECE453_CONTROL_Y_OFFSET     8
#define ECE453_STEP_COUNT_Y_OFFSET  9
#define ECE453_STEP_PERIOD_Y_OFFSET 10
#define ECE453_ELECTRO_MAG_OFFSET   11
#define ECE453_LEDS_OFFSET          12
#define ECE453_BUTTONS_OFFSET       13
#define ECE453_SWITCHES_OFFSET	    14
#define ECE453_STATUS_OFFSET	    15

//*******************************************************************
// Register Bit Definitions
//*******************************************************************
#define CONTROL_RESET_N_BIT_NUM	    0
#define CONTROL_DIR_BIT_NUM	    1
#define CONTROL_EN_N_BIT_NUM	    2
#define CONTROL_SLEEP_N_BIT_NUM	    3
#define CONTROL_MODE_BIT_NUM	    4

#define STATUS_X_BIT_NUM	    0
#define STATUS_Y_BIT_NUM	    1

//*******************************************************************
// Register Masks
//*******************************************************************
#define CONTROL_RESET_N_MASK	 (1 << CONTROL_RESET_N_BIT_NUM)
#define CONTROL_DIR_MASK	 (1 << CONTROL_DIR_BIT_NUM)
#define CONTROL_EN_N_MASK	 (1 << CONTROL_EN_N_BIT_NUM)
#define CONTROL_SLEEP_N_MASK	 (1 << CONTROL_SLEEP_N_BIT_NUM)
#define CONTROL_MODE_MASK	 (1 << CONTROL_MODE_BIT_NUM)

#define STATUS_X_MASK		 (1 << STATUS_X_BIT_NUM)
#define STATUS_Y_MASK		 (1 << STATUS_Y_BIT_NUM)

//*****************************************************************************
//*****************************************************************************
int ece453_reg_read(char *reg_name);

//*****************************************************************************
//*****************************************************************************
int ece453_reg_write(char *reg_name, int value);

#endif
