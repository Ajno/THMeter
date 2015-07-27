/*
 * io_pins.cpp
 *
 *  Created on: Jul 1, 2015
 *      Author: z0037ysj
 */

#include "io.h"
#include <derivative.h>

byte boolToByte(const Bool cBool)
{
	if (TRUE == cBool)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void configurePin(const pin_t idx, const pinConfig_t& cfg)
{
	if (cPin_B4 == idx)
	{
		PTBDD_PTBDD4 = boolToByte(cfg.b_output);
	}
	else if (cPin_B6 == idx)
	{
		PTBDD_PTBDD6 = boolToByte(cfg.b_output);
	}
	else if (cPin_B7 == idx)
	{
		PTBDD_PTBDD7 = boolToByte(cfg.b_output);
	}
}

void writePin(const pin_t idx, const Bool value)
{
	if (cPin_B4 == idx)
	{
		PTBD_PTBD4 = boolToByte(value);
	}
	else if (cPin_B6 == idx)
	{
		PTBD_PTBD6 = boolToByte(value);
	}
	else if (cPin_B7 == idx)
	{
		PTBD_PTBD7 = boolToByte(value);
	}
}
