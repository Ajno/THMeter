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
	cPin_A1	= 0,
	cPin_A2	= 1,
	cPin_A3	= 2,
	cPin_B0	= 3,
	cPin_B1	= 4,
	cPin_B2	= 5,
	cPin_B3	= 6,
	cPin_B4	= 7,
	cPin_B5	= 8,
	cPin_B6	= 9,
	cPin_B7	= 10
} pin_t;

typedef struct
{
	Bool bOutput; // output otherwise input?
	Bool bPullup; // internal pull-up enabled?	
} pinConfig_t;

void configurePin(const pin_t idx, const pinConfig_t config);
void writePin(const pin_t idx, const Bool value);
void readPin(const pin_t idx, Bool* pValue);

#endif /* IO_PINS_H_ */
