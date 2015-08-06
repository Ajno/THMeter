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

/*
 * change output on cPin every ~ 0,5s (bus freq = 4MHz)
 */
void PwmTest_timer_init(const pin_t cPin);

/*
 * changing duty cycle output on pin TPMCH0
 */
void PwmTest_pwm_init(const Word cSpeed);
void PwmTest_pwm_run();

#endif /* PWM_TEST_H_ */
