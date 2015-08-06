/*
 * pwm.cpp
 *
 *  Created on: Jul 10, 2015
 *      Author: z0037ysj
 */

#include "pwm.h"
#include <derivative.h>

static Bool bIsrClbckInstalled = FALSE;
static pInterruptCallback_t pIsrClbck;

void configurePwm(const pwmConfig_t cfg)
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
	TPMC0SC = TPMC0SC | (cfg.chnnl.mode << TPMC0SC_ELS0x_BITNUM);
//	TPMC0SC_CH0IE = cfg.chnnl0.bChannelInterruptEnable;
}

Word readPwmTimer()
{
	return TPMCNT;
}

void writePwmModulo(const Word modulo)
{
	TPMMOD = modulo;
}

void writePwmChannel(const Word value)
{
	TPMC0V = value;
}

void installPwmTimerIsr(pInterruptCallback_t pcIsrClbck)
{
	if (0 != pcIsrClbck)
	{
		pIsrClbck = pcIsrClbck;
		bIsrClbckInstalled = TRUE;
	}
}

void __interrupt VectorNumber_Vtpmovf isr_timerOverflow(void)
{
	if (bIsrClbckInstalled)
	{
		(*pIsrClbck)();
	}
	
	(void)(TPMSC == 0x00); // Overflow int. flag clearing (first part) 
	TPMSC_TOF=0;// Overflow int. flag clearing (second part) 
}
