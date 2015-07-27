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

void clbck_PwmTest_timer();

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
 * 50 duty cycle output on pin TPMCH0
 */
class PwmTest_pwm
{
public:
	PwmTest_pwm();
	virtual ~PwmTest_pwm();
};

#endif /* PWM_TEST_H_ */
