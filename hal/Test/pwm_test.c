/*
 * pwm_test.cpp
 *
 *  Created on: Jul 15, 2015
 *      Author: z0037ysj
 */

#include "pwm_test.h"

static struct
{
	pin_t pwmTestTimerLedPin;
	Bool bPwmTestTimerLedOn;
} test_timer =
{ 
		cPin_B7, 
		FALSE, 
};

void isr_PwmTest_timer()
{
	writePin(test_timer.pwmTestTimerLedPin, test_timer.bPwmTestTimerLedOn);
	test_timer.bPwmTestTimerLedOn = !test_timer.bPwmTestTimerLedOn;
}

/*
 * PWM timer
 */
void PwmTest_timer_init(const pin_t cPin)
{
	pinConfig_t outputCfg;
	pwmConfig_t pwmCfg;

	test_timer.pwmTestTimerLedPin = cPin;
	test_timer.bPwmTestTimerLedOn = FALSE;

	outputCfg.bOutput = TRUE;
	pwmCfg.bOverflowInterruptEnable = TRUE;
	pwmCfg.clock = cPwmClk_bus;	// 4MHz
	pwmCfg.prescaler = cPwmPrsclr_32; // 4M/32=125k

	configurePin(test_timer.pwmTestTimerLedPin, outputCfg);
	configurePwm(pwmCfg);
	installPwmTimerIsr(isr_PwmTest_timer);
}

/*
 * edge aligned PWM
 */

static struct
{
	Word speed;
	Word channelValue;
	Bool bDirectionUp;
} test_pwm =
{ 
		1, // default speed
		0, 
		0 
};

void PwmTest_pwm_init(const Word cSpeed)
{
	pwmConfig_t pwmCfg;

	test_pwm.speed = cSpeed;
	test_pwm.channelValue = 0;
	test_pwm.bDirectionUp = TRUE;

	pwmCfg.bOverflowInterruptEnable = FALSE;
	pwmCfg.clock = cPwmClk_bus;	// 4MHz
	pwmCfg.prescaler = cPwmPrsclr_1; // 4M
	pwmCfg.chnnl.mode = cPwmMode_edgeAligned_clear;

	configurePwm(pwmCfg);
	writePwmChannel(0x7fff);
}

void PwmTest_pwm_run()
{
	if (test_pwm.bDirectionUp)
	{
		test_pwm.channelValue += test_pwm.speed;
		if ((0xffff - test_pwm.speed) <= test_pwm.channelValue)
		{
			test_pwm.bDirectionUp = !test_pwm.bDirectionUp;
		}
	}
	else
	{
		test_pwm.channelValue -= test_pwm.speed;
		if ((0x0000 + test_pwm.speed) >= test_pwm.channelValue)
		{
			test_pwm.bDirectionUp = !test_pwm.bDirectionUp;
		}
	}

	writePwmChannel(test_pwm.channelValue);
}
