/*
 * timer.c
 *
 *  Created on: Aug 24, 2015
 *      Author: z0037ysj
 */

#include "pwm.h"
#include "timer.h"

static const Word cModuloPwmTimer = 800;

void initTimer()
{
	configPwmTimer_t cfg;
	
	cfg.clock = cPwmClk_bus;
	cfg.prescaler = cPwmPrsclr_1;
	
	writePwmModulo(cModuloPwmTimer);
	configurePwmTimer(cfg);
}
