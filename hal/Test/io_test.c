/*
 * io_test.cpp
 *
 *  Created on: Jul 15, 2015
 *      Author: z0037ysj
 */

#include "io_test.h"

static struct
{
	Bool 	val;
	pin_t 	idx;
	Word 	cntr;
}test_out;

void test_io_output_init(const pin_t cPin)
{
	pinConfig_t outputCfg;
	outputCfg.bOutput = TRUE;
	test_out.val = FALSE;
	
	configurePin(cPin, outputCfg);

	test_out.idx = cPin;
	test_out.cntr = 0;
}

void test_io_output_run()
{
	const Word toogle = 20000;
	test_out.cntr++;
	if (toogle < test_out.cntr)
	{			
		(FALSE == test_out.val) ? (test_out.val = TRUE):(test_out.val = FALSE);
		writePin(test_out.idx,test_out.val);
		test_out.cntr = 0;
	}
}

static struct 
{
	pin_t	inIdx;
	pin_t	outIdx;
}test_inOut;

void test_io_inputOutput_init(const pin_t cInPin, const pin_t cOutPin)
{
	pinConfig_t inputCfg;
	pinConfig_t outputCfg;
	
	inputCfg.bOutput = FALSE;
	inputCfg.bPullup = TRUE;	
	outputCfg.bOutput = TRUE;
	
	test_inOut.inIdx = cInPin;
	test_inOut.outIdx = cOutPin;
	
	configurePin(test_inOut.inIdx, inputCfg);
	configurePin(test_inOut.outIdx, outputCfg);
}

void test_io_inputOutput_run()
{
	auto Bool value = FALSE;
	readPin(test_inOut.inIdx,&value);
	writePin(test_inOut.outIdx,value);
}
