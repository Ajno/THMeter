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
	pin_t 	pin;
	Word 	cntr;
};

class IoTest_input
{
public:
	IoTest_input(const pin_t pin);
	virtual ~IoTest_input();
	void run();
private:
//	Bool 	pinVal;
//	pin_t 	pin;
//	Word 	cntr;
};

#endif /* IO_TEST_H_ */
