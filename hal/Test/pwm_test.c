/*
 * pwm_test.cpp
 *
 *  Created on: Jul 15, 2015
 *      Author: z0037ysj
 */

#include "pwm_test.h"

static struct
{
    pin_t ledIdx;
    Bool bLedOn;
} test_timer =
{ cPin_B7, FALSE, };

static void isr_timer()
{
    writePin(test_timer.ledIdx, test_timer.bLedOn);
    test_timer.bLedOn = !test_timer.bLedOn;
}

/*
 * PWM timer
 */
void test_pwm_timer_init(const pin_t cPin)
{
    pinConfig_t outputCfg;
    configPwmTimer_t pwmCfg;

    test_timer.ledIdx = cPin;
    test_timer.bLedOn = FALSE;

    outputCfg.bOutput = TRUE;
    pwmCfg.bOverflowInterruptEnable = TRUE;
    pwmCfg.clock = cPwmClk_bus;	// 4MHz
    pwmCfg.prescaler = cPwmPrsclr_32; // 4M/32=125k

    configurePin(test_timer.ledIdx, outputCfg);
    configurePwmTimer(pwmCfg);
    installPwmTimerIsr(isr_timer);
}

/*
 * edge aligned PWM
 */
const Word MODULO = 2000;
static struct
{
    Word speed;
    Word channelValue;
    Bool bDirectionUp;
} test_chnl =
{ 1, // default speed
        0, TRUE // default direction is UP 
        };
void test_pwm_chnl_init(const Word cSpeed)
{
    configPwmTimer_t cfgTimer =
    { 0 };
    pwmChannelConfig_t cfgChannel =
    { 0 };

    test_chnl.speed = cSpeed;
    test_chnl.channelValue = 0;
    test_chnl.bDirectionUp = TRUE;

    cfgTimer.bOverflowInterruptEnable = FALSE;
    cfgTimer.clock = cPwmClk_bus;	// 4MHz
    cfgTimer.prescaler = cPwmPrsclr_1; // 4M
    cfgChannel.mode = cPwmMode_edgeAligned_clear;

    writePwmModulo(MODULO); //2kHz PWM
    configurePwmTimer(cfgTimer);
    configurePwmChannel(cfgChannel);
    writePwmChannel(MODULO * 0.1625); //0.1625 duty
}

void test_pwm_chnl_run()
{
    if (0 != test_chnl.speed)
    {
        if (test_chnl.bDirectionUp)
        {
            test_chnl.channelValue += test_chnl.speed;
            if ((MODULO - test_chnl.speed) <= test_chnl.channelValue)
            {
                test_chnl.bDirectionUp = !test_chnl.bDirectionUp;
            }
        }
        else
        {
            test_chnl.channelValue -= test_chnl.speed;
            if ((0x0000 + test_chnl.speed) >= test_chnl.channelValue)
            {
                test_chnl.bDirectionUp = !test_chnl.bDirectionUp;
            }
        }

        writePwmChannel(test_chnl.channelValue);
    }
}
