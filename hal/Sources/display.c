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

static const Byte cMaskBacklighAndEnable = 0x30;

enum displayBus
{
    cDisplayBus_DB4         = cPin_B0,
    cDisplayBus_DB5         = cPin_B1,
    cDisplayBus_DB6         = cPin_B2,
    cDisplayBus_DB7         = cPin_B3,
    cDisplayBus_backLight   = cPin_B4,
    cDisplayBus_E           = cPin_B5,
    cDisplayBus_RW          = cPin_B6,
    cDisplayBus_RS          = cPin_B7
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
    Byte portB = 0;
    
    // set enable
    writePin(cDisplayBus_E,TRUE);
    /*
     *  @write upper byte
     * read port B to X
     * clear X with masked backlight and enable
     * write X to port B 
     * */
    readPortB(&portB);
    portB = portB & cMaskBacklighAndEnable;
    writePortB(portB);
    // wait
    wait500ns();
    // clear enable
    writePin(cDisplayBus_E,FALSE);
    // wait
    wait500ns();
    
    // set enable
    writePin(cDisplayBus_E,TRUE);
    /*
     * @write lower byte
     * set bit 0 port B 
     * */
    writePin(cDisplayBus_DB4, TRUE);
    // wait
    wait500ns();
    // clear enable
    writePin(cDisplayBus_E,FALSE);
    // wait
    wait500ns();
}

void displayOnOffControl()
{
    Byte portB = 0;
    
    // set enable
    writePin(cDisplayBus_E,TRUE);
    /*
     *  @write upper byte
     * read port B to X
     * clear X with masked backlight and enable
     * write X to port B 
     * */
    readPortB(&portB);
    portB = portB & cMaskBacklighAndEnable;
    writePortB(portB);
    // wait
    wait500ns();
    // clear enable
    writePin(cDisplayBus_E,FALSE);
    // wait
    wait500ns();
    
    // set enable
    writePin(cDisplayBus_E,TRUE);
    // write lower byte
    /*
     * set bit 3 in X
     * set bit D in X
     * set bit C in X
     * set bit B in X
     * */
    writePin(cDisplayBus_DB7,TRUE);
    writePin(cDisplayBus_DB6,FALSE);
    writePin(cDisplayBus_DB5,FALSE);
    writePin(cDisplayBus_DB4,FALSE);
    // wait
    wait500ns();
    // clear enable
    writePin(cDisplayBus_E,FALSE);
    // wait
    wait500ns();
}

void displayFunctionSet(const Bool bDots5x10)
{
    Byte portB = 0;
    
    // set enable
    writePin(cDisplayBus_E,TRUE);
    /*
     * @write upper byte
     * read port B to X
     * clear X with masked backlight and enable
     * set bit 1 in X
     * write X to port B 
     * */
    readPortB(&portB);
    portB = portB & cMaskBacklighAndEnable;
    writePortB(portB);
    writePin(cDisplayBus_DB5,TRUE);
    // wait
    wait500ns();
    // clear enable
    writePin(cDisplayBus_E,FALSE);
    // wait
    wait500ns();
    
    // set enable
    writePin(cDisplayBus_E,TRUE);
    /*
     * @write lower byte
     * set bit N in X
     * set bit F in X
     * */
    writePin(cDisplayBus_DB7,TRUE);
    writePin(cDisplayBus_DB6,bDots5x10);
    // wait
    wait500ns();
    // clear enable
    writePin(cDisplayBus_E,FALSE);
    // wait
    wait500ns();
}

void displayEntryModeSet()
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
