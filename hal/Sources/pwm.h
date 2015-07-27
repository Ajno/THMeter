/*
 * pwm.h
 *
 *  Created on: Jul 10, 2015
 *      Author: z0037ysj
 */

#ifndef PWM_H_
#define PWM_H_

#include <stdtypes.h>

typedef enum
{
	cPwmClk_disabled	= 0, 
	cPwmClk_bus			= 1
} pwmClock_t;

typedef enum
{
	cPwmPrsclr_1	= 0, 
	cPwmPrsclr_2	= 1,
	cPwmPrsclr_4	= 2,
	cPwmPrsclr_8	= 3,
	cPwmPrsclr_16	= 4,
	cPwmPrsclr_32	= 5,
	cPwmPrsclr_64	= 6,
	cPwmPrsclr_128	= 7
} pwmPrescaler_t;

typedef enum
{
	cPwmMode_channelDisabled			= 0,
	cPwmMode_inputCapture_rising		= 1,
	cPwmMode_inputCapture_falling		= 2,
	cPwmMode_inputCapture_risingFalling	= 3,
	cPwmMode_outputCompare_software		= 4,
	cPwmMode_outputCompare_toggle		= 5,
	cPwmMode_outputCompare_set			= 6,
	cPwmMode_outputCompare_clear		= 7,
	cPwmMode_edgeAligned_set			= 9,
	cPwmMode_edgeAligned_clear			= 10
} pwmMode_t;

typedef struct
{
	pwmMode_t	mode;
//	Bool 		bChannelInterruptEnable;
} pwmChannel_t;

typedef struct
{
	pwmClock_t 		clock;
	pwmPrescaler_t	prescaler;
	Bool			bOverflowInterruptEnable;
	pwmChannel_t	chnnl0;
} pwmConfig_t;

typedef void (*pInterruptCallback_t)(void);

void configurePwm(const pwmConfig_t& cfg);
Word readPwmCounter();
void writePwmModulo(const Word modulo);
void writePwmChannel0(const Word value);
void installCallbackPwmTimerInterrupt(pInterruptCallback_t pc_isrClbck);

#endif /* PWM_H_ */
