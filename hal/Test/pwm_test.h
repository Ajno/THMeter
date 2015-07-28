/*
 * pwm_test.h
 *
 *  Created on: Jul 15, 2015
 *      Author: z0037ysj
 */

#ifndef PWM_TEST_H_
#define PWM_TEST_H_

#include "pwm.h"
#include "io.h"

void isr_PwmTest_timer();

/*
 * change output on cPin every ~ 0,5s (bus freq = 4MHz)
 */
class PwmTest_timer
{
public:
	PwmTest_timer(const pin_t cPin);
	virtual ~PwmTest_timer();
};

/*
 * changing duty cycle output on pin TPMCH0
 */
class PwmTest_pwm
{
public:
	PwmTest_pwm(const Word cSpeed = 1);
	virtual ~PwmTest_pwm();
	void run();
private:
	Word speed;
	Word channelValue;	
	Bool bDirectionUp;
};

#endif /* PWM_TEST_H_ */
