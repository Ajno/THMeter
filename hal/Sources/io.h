/*
 * io_pins.h
 *
 *  Created on: Jul 1, 2015
 *      Author: z0037ysj
 */

#ifndef IO_PINS_H_
#define IO_PINS_H_

#include <stdtypes.h>

typedef enum
{
	cPin_A2,
	cPin_A3,
	cPin_B4,
	cPin_B6,
	cPin_B7
} pin_t;

typedef struct
{
	Bool b_output; // output or input?
} pinConfig_t;

void configurePin(const pin_t idx, const pinConfig_t& config);
void writePin(const pin_t idx, const Bool value);

#endif /* IO_PINS_H_ */
