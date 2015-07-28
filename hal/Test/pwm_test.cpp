/*
 * pwm_test.cpp
 *
 *  Created on: Jul 15, 2015
 *      Author: z0037ysj
 */

#include "pwm_test.h"

static pin_t pwmTestTimerLedPin;
static Bool bPwmTestTimerLedOn = FALSE;

/*
 * PWM timer
 */
PwmTest_timer::PwmTest_timer(const pin_t cPin)
{
	pwmTestTimerLedPin = cPin;
	bPwmTestTimerLedOn = FALSE;

	pinConfig_t outputCfg;
	outputCfg.bOutput = TRUE;

	configurePin(pwmTestTimerLedPin, outputCfg);

	pwmConfig_t pwmCfg;
	pwmCfg.bOverflowInterruptEnable = TRUE;
	pwmCfg.clock = cPwmClk_bus;	// 4MHz
	pwmCfg.prescaler = cPwmPrsclr_32; // 4M/32=125k

	configurePwm(pwmCfg);
	installPwmTimerIsr(isr_PwmTest_timer);
}

PwmTest_timer::~PwmTest_timer()
{
}

void isr_PwmTest_timer()
{
	writePin(pwmTestTimerLedPin, bPwmTestTimerLedOn);
	bPwmTestTimerLedOn = !bPwmTestTimerLedOn;
}

/*
 * edge aligned PWM
 */
PwmTest_pwm::PwmTest_pwm(const Word cSpeed)
{
	this->speed = cSpeed;
	this->channelValue = 0;
	this->bDirectionUp = TRUE;

	pwmConfig_t pwmCfg;
	pwmCfg.bOverflowInterruptEnable = FALSE;
	pwmCfg.clock = cPwmClk_bus;	// 4MHz
	pwmCfg.prescaler = cPwmPrsclr_1; // 4M
	pwmCfg.chnnl.mode = cPwmMode_edgeAligned_clear;

	configurePwm(pwmCfg);
	writePwmChannel(0x7fff);
}

PwmTest_pwm::~PwmTest_pwm()
{
}

void PwmTest_pwm::run()
{
	if (this->bDirectionUp)
	{
		this->channelValue += this->speed;
		if ((0xffff - this->speed) <= this->channelValue)
		{
			this->bDirectionUp = !this->bDirectionUp;
		}
	}
	else
	{
		this->channelValue -= this->speed;
		if ((0x0000 + this->speed) >= this->channelValue)
		{
			this->bDirectionUp = !this->bDirectionUp;
		}
	}
	
	writePwmChannel(this->channelValue);
}
