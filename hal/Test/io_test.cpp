/*
 * io_test.cpp
 *
 *  Created on: Jul 15, 2015
 *      Author: z0037ysj
 */

#include "io_test.h"

IoTest_output::IoTest_output(const pin_t cPin)
{
	pinConfig_t outputCfg;
	outputCfg.b_output = TRUE;
	pinVal = FALSE;
	
	configurePin(cPin, outputCfg);

	this->pin = cPin;
	this->cntr = 0;
}

IoTest_output::~IoTest_output()
{
}

void IoTest_output::run()
{
	const Word toogle = 20000;
	this->cntr++;
	if (toogle < cntr)
	{			
		(FALSE == this->pinVal) ? (this->pinVal = TRUE):(this->pinVal = FALSE);
		writePin(this->pin,this->pinVal);
		this->cntr = 0;
	}
}
