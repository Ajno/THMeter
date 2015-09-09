/*
 * io_pins.cpp
 *
 *  Created on: Jul 1, 2015
 *      Author: z0037ysj
 */

#include "io.h"
#include <derivative.h>

static const Byte cMaxByte = 0xFF;

Byte boolToByte(const Bool cBool)
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

void configurePin(const pin_t idx, const pinConfig_t config)
{
	if (cPin_A1 == idx)
	{
		PTADD_PTADD1 = boolToByte(config.bOutput);
		PTAPE_PTAPE1 = boolToByte(config.bPullUp);
	}
	else if (cPin_A2 == idx)
	{
		PTADD_PTADD2 = boolToByte(config.bOutput);
		PTAPE_PTAPE2 = boolToByte(config.bPullUp);
	}
	else if (cPin_A3 == idx)
	{
		PTADD_PTADD3 = boolToByte(config.bOutput);
		PTAPE_PTAPE3 = boolToByte(config.bPullUp);
	}
	else if (cPin_B0 == idx)
	{
		PTBDD_PTBDD0 = boolToByte(config.bOutput);
		PTBPE_PTBPE0 = boolToByte(config.bPullUp);
	}
	else if (cPin_B1 == idx)
	{
		PTBDD_PTBDD1 = boolToByte(config.bOutput);
		PTBPE_PTBPE1 = boolToByte(config.bPullUp);
	}
	else if (cPin_B2 == idx)
	{
		PTBDD_PTBDD2 = boolToByte(config.bOutput);
		PTBPE_PTBPE2 = boolToByte(config.bPullUp);
	}
	else if (cPin_B3 == idx)
	{
		PTBDD_PTBDD3 = boolToByte(config.bOutput);
		PTBPE_PTBPE3 = boolToByte(config.bPullUp);
	}
	else if (cPin_B4 == idx)
	{
		PTBDD_PTBDD4 = boolToByte(config.bOutput);
		PTBPE_PTBPE4 = boolToByte(config.bPullUp);
	}
	else if (cPin_B5 == idx)
	{
		PTBDD_PTBDD5 = boolToByte(config.bOutput);
		PTBPE_PTBPE5 = boolToByte(config.bPullUp);
	}
	else if (cPin_B6 == idx)
	{
		PTBDD_PTBDD6 = boolToByte(config.bOutput);
		PTBPE_PTBPE6 = boolToByte(config.bPullUp);
	}
	else if (cPin_B7 == idx)
	{
		PTBDD_PTBDD7 = boolToByte(config.bOutput);
		PTBPE_PTBPE7 = boolToByte(config.bPullUp);
	}
}

void configurePortB(const pinConfig_t config)
{
    if (config.bOutput)
    {
        PTBDD = cMaxByte;        
    }
    else
    {
        PTBDD = 0;        
    }
    
    if (config.bPullUp)
    {
        PTBPE = cMaxByte;
    }
    else
    {
        PTBPE = 0;        
    }
}

void writePin(const pin_t idx, const Bool value)
{
	if (cPin_A1 == idx)
	{
		PTAD_PTAD1 = boolToByte(value);
	}
	else if (cPin_A2 == idx)
	{
		PTAD_PTAD2 = boolToByte(value);
	}
	else if (cPin_A3 == idx)
	{
		PTAD_PTAD3 = boolToByte(value);
	}
	else if (cPin_B0 == idx)
	{
		PTBD_PTBD0 = boolToByte(value);
	}
	else if (cPin_B1 == idx)
	{
		PTBD_PTBD1 = boolToByte(value);
	}
	else if (cPin_B2 == idx)
	{
		PTBD_PTBD2 = boolToByte(value);
	}
	else if (cPin_B3 == idx)
	{
		PTBD_PTBD3 = boolToByte(value);
	}
	else if (cPin_B4 == idx)
	{
		PTBD_PTBD4 = boolToByte(value);
	}
	else if (cPin_B5 == idx)
	{
		PTBD_PTBD5 = boolToByte(value);
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

void writePortB(const Byte cValue)
{
    PTBD = cValue;
}

void readPin(const pin_t idx, Bool* pValue)
{
	if (cPin_A1 == idx)
	{
		*pValue = PTAD_PTAD1;
	}
	else if (cPin_A2 == idx)
	{
		*pValue = PTAD_PTAD2;
	}
	else if (cPin_A3 == idx)
	{
		*pValue = PTAD_PTAD3;
	}
	else if (cPin_B0 == idx)
	{
		*pValue = PTBD_PTBD0;
	}
	else if (cPin_B1 == idx)
	{
		*pValue = PTBD_PTBD1;
	}
	else if (cPin_B2 == idx)
	{
		*pValue = PTBD_PTBD2;
	}
	else if (cPin_B3 == idx)
	{
		*pValue = PTBD_PTBD3;
	}
	else if (cPin_B4 == idx)
	{
		*pValue = PTBD_PTBD4;
	}
	else if (cPin_B5 == idx)
	{
		*pValue = PTBD_PTBD5;
	}
	else if (cPin_B6 == idx)
	{
		*pValue = PTBD_PTBD6;
	}
	else if (cPin_B7 == idx)
	{
		*pValue = PTBD_PTBD7;
	}
}

void readPortB(Byte* pValue)
{
    *pValue = PTBD;
}
