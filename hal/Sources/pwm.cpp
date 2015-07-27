/*
 * pwm.cpp
 *
 *  Created on: Jul 10, 2015
 *      Author: z0037ysj
 */

#include "pwm.h"
#include <derivative.h>

static Bool bIsrClbckInstalled = FALSE;
static pInterruptCallback_t p_isrClbck;

void configurePwm(const pwmConfig_t& cfg)
{
	// clear all registers
	TPMSC = 0;
	TPMC0SC = 0;
	TPMC1SC = 0;
	// counter
	TPMSC_CLKSx = cfg.clock;
	TPMSC_PS = cfg.prescaler;
	TPMSC_TOIE = cfg.bOverflowInterruptEnable;
	// channel 0
	TPMC0SC = TPMC0SC | (cfg.chnnl0.mode << TPMC0SC_ELS0x_BITNUM);
//	TPMC0SC_CH0IE = cfg.chnnl0.bChannelInterruptEnable;
}

Word readPwmCounter()
{
	return TPMCNT;
}

void writePwmModulo(const Word modulo)
{
	TPMMOD = modulo;
}

void writePwmChannel0(const Word value)
{
	TPMC0V = value;
}

void installCallbackPwmTimerInterrupt(pInterruptCallback_t pc_isrClbck)
{
	if (0 != pc_isrClbck)
	{
		p_isrClbck = pc_isrClbck;
		bIsrClbckInstalled = TRUE;
	}
}

void __interrupt VectorNumber_Vtpmovf isr_timerOverflow(void)
{
	if (bIsrClbckInstalled)
	{
		(*p_isrClbck)();
	}
	
	(void)(TPMSC == 0x00); // Overflow int. flag clearing (first part) 
	TPMSC_TOF=0;// Overflow int. flag clearing (second part) 
}
