/*
 * display.c
 *
 *  Created on: Aug 6, 2015
 *      Author: z0037ysj
 */

#include "pwm.h"
#include "io.h"
#include "display.h"

static const pin_t LED_LCD = cPin_B4;

void initDisplay()
{
	configPin_t cfgPin;
	configPwmChannel_t cfgChnl;
	const Word cChannelValue = readPwmModulo()/100*16;

	cfgPin.bOutput = TRUE;
	cfgChnl.mode = cPwmMode_edgeAligned_clear;
	
	configurePin(LED_LCD,cfgPin);
	configurePwmChannel(cfgChnl);
	writePwmChannel(cChannelValue);
}

void setBackLight(const Bool bBackLightOn)
{
	writePin(LED_LCD,bBackLightOn);
}
