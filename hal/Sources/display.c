/*
 * display.c
 *
 *  Created on: Aug 6, 2015
 *      Author: z0037ysj
 */

#include "display.h"
#include "pwm.h"
#include "io.h"
#include "timer.h"

enum displayBus
{
    cDisplayBus_RS          = cPin_B7,
    cDisplayBus_RW          = cPin_B6,
    cDisplayBus_E           = cPin_B5,
    cDisplayBus_backLight   = cPin_B4,
};

void displayInit()
{
    pinConfig_t pinCfg;
    pwmChannelConfig_t chnlCfg;
    const Word cChannelValue = (readPwmModulo() / 100) * 16;

    pinCfg.bOutput = TRUE;
    configurePortB(pinCfg);

    chnlCfg.mode = cPwmMode_edgeAligned_clear;
    configurePwmChannel(chnlCfg);
    writePwmChannel(cChannelValue);
}

void displayBackLightOn(const Bool bBackLightOn)
{
    writePin(cDisplayBus_backLight, bBackLightOn);
}

void displayClear()
{
    // set enable
    writePin(cDisplayBus_E,TRUE);
    // write upper byte
    writePortB(0);
    // wait
    wait500ns();
    // clear enable
    writePin(cDisplayBus_E,FALSE);
    // wait
    wait500ns();
    
    // set enable
    writePin(cDisplayBus_E,TRUE);
    // write lower byte
    writePortB(1);
    // wait
    wait500ns();
    // clear enable
    writePin(cDisplayBus_E,FALSE);
    // wait
    wait500ns();
}

void displayFunctionSet()
{
    // todo
}

void displayFirstStart()
{
    const Word cSet_DB5     = 2;
    const Word cSet_DB4_DB5 = 3;
    
    // wait 40 ms
    waitX100us(400);
    
    // set enable
    writePin(cDisplayBus_E,TRUE);
    // write upper byte
    writePortB(cSet_DB4_DB5);
    // wait
    wait500ns();
    // clear enable
    writePin(cDisplayBus_E,FALSE);
    // wait
    wait500ns();
    
    // wait 5 ms
    waitX100us(50);
    
    // set enable
    writePin(cDisplayBus_E,TRUE);
    // write upper byte
    writePortB(cSet_DB4_DB5);
    // wait
    wait500ns();
    // clear enable
    writePin(cDisplayBus_E,FALSE);
    // wait
    wait500ns();
    
    // wait 0,5 ms
    waitX100us(5);
    
    // set enable
    writePin(cDisplayBus_E,TRUE);
    // write upper byte
    writePortB(cSet_DB4_DB5);
    // wait
    wait500ns();
    // clear enable
    writePin(cDisplayBus_E,FALSE);
    // wait
    wait500ns();
    
    //Function set (Set interface to be 4 bits long.)
    //Interface is 8 bits in length.
    // set enable
    writePin(cDisplayBus_E,TRUE);
    // write upper byte
    writePortB(cSet_DB5);
    // wait
    wait500ns();
    // clear enable
    writePin(cDisplayBus_E,FALSE);
    // wait
    wait500ns();
    
    //Function set (Interface is 4 bits long. Specify the
    //number of display lines and character font.)
    //The number of display lines and character font
    //cannot be changed after this point.
    // todo
    
    //Display off
    // todo
    
    //Display clear
    // todo
    
    //Entry mode set
    // todo    
}
