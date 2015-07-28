/*
 * io_test.h
 *
 *  Created on: Jul 15, 2015
 *      Author: z0037ysj
 */

#ifndef IO_TEST_H_
#define IO_TEST_H_

#include "io.h"

class IoTest_output
{
public:
	IoTest_output(const pin_t pin);
	virtual ~IoTest_output();
	void run();
private:
	Bool 	pinVal;
	pin_t 	pinIdx;
	Word 	cntr;
};

class IoTest_inputOutput
{
public:
	IoTest_inputOutput(const pin_t cInPin, const pin_t cOutPin);
	virtual ~IoTest_inputOutput();
	void run();
private:
	pin_t	input;
	pin_t	output;
};

#endif /* IO_TEST_H_ */
