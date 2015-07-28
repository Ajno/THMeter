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
	outputCfg.bOutput = TRUE;
	pinVal = FALSE;
	
	configurePin(cPin, outputCfg);

	this->pinIdx = cPin;
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
		writePin(this->pinIdx,this->pinVal);
		this->cntr = 0;
	}
}

IoTest_inputOutput::IoTest_inputOutput(const pin_t cInPin, const pin_t cOutPin)
{
	pinConfig_t inputCfg;
	inputCfg.bOutput = FALSE;
	inputCfg.bPullup = TRUE;
	pinConfig_t outputCfg;
	outputCfg.bOutput = TRUE;
	
	this->input = cInPin;
	this->output = cOutPin;
	
	configurePin(this->input, inputCfg);
	configurePin(this->output, outputCfg);
}

IoTest_inputOutput::~IoTest_inputOutput()
{
}

void IoTest_inputOutput::run()
{
	Bool value = FALSE;
	readPin(this->input,value);
	writePin(this->output,value);
}
