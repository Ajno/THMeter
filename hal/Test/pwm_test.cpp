/*
 * pwm_test.cpp
 *
 *  Created on: Jul 15, 2015
 *      Author: z0037ysj
 */

#include "pwm_test.h"

static pin_t pwmTestTimerLedPin;
static Bool bPwmTestTimerLedOn = FALSE;

PwmTest_timer::PwmTest_timer(const pin_t cPin)
{
	pwmTestTimerLedPin = cPin;
	bPwmTestTimerLedOn = FALSE;
	
	pinConfig_t outputCfg;
	outputCfg.b_output = TRUE;
	
	configurePin(pwmTestTimerLedPin, outputCfg);
	
	pwmConfig_t pwmCfg;	
	pwmCfg.bOverflowInterruptEnable = TRUE;
	pwmCfg.clock = cPwmClk_bus;	// 4MHz
	pwmCfg.prescaler = cPwmPrsclr_32; // 4M/32=125k
	
	configurePwm(pwmCfg);
	installCallbackPwmTimerInterrupt(clbck_PwmTest_timer);
}

PwmTest_timer::~PwmTest_timer()
{	
}

void clbck_PwmTest_timer()
{
	writePin(pwmTestTimerLedPin, bPwmTestTimerLedOn);
	bPwmTestTimerLedOn = ! bPwmTestTimerLedOn;
}

PwmTest_pwm::PwmTest_pwm()
{
	pwmConfig_t pwmCfg;	
	pwmCfg.bOverflowInterruptEnable = FALSE;
	pwmCfg.clock = cPwmClk_bus;	// 4MHz
	pwmCfg.prescaler = cPwmPrsclr_32; // 4M/32=125k
	pwmCfg.chnnl0.mode = cPwmMode_edgeAligned_clear;
	
	configurePwm(pwmCfg);
	writePwmChannel0(0x7fff);
}

PwmTest_pwm::~PwmTest_pwm()
{	
}
