/*
 * timer.c
 *
 *  Created on: Aug 24, 2015
 *      Author: z0037ysj
 */

#include "pwm.h"
#include "timer.h"

static const Word cModuloPwmTimer = 800;
static const Word c100us = 400;
static Word ovrflwCount = 0;

void timerInit()
{
	configPwmTimer_t cfg;
	
	cfg.clock = cPwmClk_bus;
	cfg.prescaler = cPwmPrsclr_1;// 4MHz clock
	
	writePwmModulo(cModuloPwmTimer);// 5kHz period
	configurePwmTimer(cfg);
}

void wait500ns()
{
    // delay two bus cycles = 500 ns
    asm
    {
        NOP
        NOP
    }
}

void waitX100us(const Word cDelay)
{
	volatile Word t1 = 0;
	volatile Word t2 = 0;
	
	t1 = readPwmTimer();
	ovrflwCount = cDelay;

	do
	{
		do
		{
			t2 = readPwmTimer();
			if (t2 < t1)
			{
				t2 = cModuloPwmTimer - t1;
			}
		} while ((t2 - t1) < c100us);
		t1 = t2;
		ovrflwCount--;
	} while (0 != ovrflwCount);
}
