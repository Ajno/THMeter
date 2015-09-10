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

enum displayBus_t
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

static const Byte cMask_Backligh = 0x10;

static Bool bDataBusConfiguredAsOutput = FALSE;

void displayInit()
{
    pinConfig_t pinCfg;
    pwmChannelConfig_t chnlCfg;
    const Word cChannelValue = (readPwmModulo() / 100) * 16;

    pinCfg.bOutput = TRUE;
    configurePortB(pinCfg);
    bDataBusConfiguredAsOutput = TRUE;

    chnlCfg.mode = cPwmMode_edgeAligned_clear;
    configurePwmChannel(chnlCfg);
    writePwmChannel(cChannelValue);
}

void displayBackLightOn(const Bool bBackLightOn)
{
    writePin(cDisplayBus_backLight, bBackLightOn);
}

void displayPrepareBusForWrite()
{
    Byte portB = 0;
    pinConfig_t pinCfg;
    
    if (!bDataBusConfiguredAsOutput)
    {
        pinCfg.bOutput = TRUE;
        configurePin(cDisplayBus_DB4,pinCfg);
        configurePin(cDisplayBus_DB5,pinCfg);
        configurePin(cDisplayBus_DB6,pinCfg);
        configurePin(cDisplayBus_DB7,pinCfg);
        bDataBusConfiguredAsOutput = pinCfg.bOutput;
    }
    // clear port B except backlight
    readPortB(&portB);
    portB = portB & cMask_Backligh;
    writePortB(portB);
}

void displayToggleEnable()
{
    // set enable
    writePin(cDisplayBus_E,TRUE);
    // wait
    wait500ns();
    // clear enable
    writePin(cDisplayBus_E,FALSE);
    // wait
    wait500ns();
}

void displayClear()
{
    displayPrepareBusForWrite();
    displayToggleEnable();
    
    // set bit 0
    writePin(cDisplayBus_DB4, TRUE);
    displayToggleEnable();
}

void displayReturnHome()
{
    displayPrepareBusForWrite();
    displayToggleEnable();
    
    // set bit 1
    writePin(cDisplayBus_DB5, TRUE);
    displayToggleEnable();
}

void displayOnOffControl(const displayOnOffControl_t cControl)
{
    displayPrepareBusForWrite();
    displayToggleEnable();
    
    /* 
     * write lower 4 bits
     * set bit 3 in X
     * set bit D in X
     * set bit C in X
     * set bit B in X
     * */
    writePin(cDisplayBus_DB7,TRUE);
    writePin(cDisplayBus_DB6,cControl.bDisplayOn);
    writePin(cDisplayBus_DB5,cControl.bCursorOn);
    writePin(cDisplayBus_DB4,cControl.bBlinkingCursorOn);
    displayToggleEnable();
}

void displayOrCursorShift(const displayMovingDirection_t cSetting)
{
    displayPrepareBusForWrite();
    writePin(cDisplayBus_DB4, TRUE);
    displayToggleEnable();
    
    // write lower 4 bits, set S/C, set R/L
    writePin(cDisplayBus_DB7, cSetting.bShiftScreenInsteadOfCursor);
    writePin(cDisplayBus_DB6, cSetting.bShiftRightInsteadOfLeft);
    displayToggleEnable();
}

void displayFunctionSet()
{
    displayPrepareBusForWrite();
    // set bit 1 of higher byte
    writePin(cDisplayBus_DB5,TRUE);
    displayToggleEnable();
    
    // write lower 4 bits, set bit N in X,  bit F has no meaning when N is set
    writePin(cDisplayBus_DB7,TRUE);
    displayToggleEnable();
}

void displayEntryModeSet(const displayMovingDirection_t cSetting)
{
    displayPrepareBusForWrite();
    // set bit 2 in higher byte
    writePin(cDisplayBus_DB6,TRUE);
    displayToggleEnable();
    
    // write lower 4 bits, set bit ID, set bit S
    writePin(cDisplayBus_DB5, cSetting.bShiftRightInsteadOfLeft);
    writePin(cDisplayBus_DB4,cSetting.bShiftScreenInsteadOfCursor);
    displayToggleEnable();
}

void displayWriteDataRam(const Byte cData)
{
    Byte portB = 0;
    
    displayPrepareBusForWrite();
    // set RS
    writePin(cDisplayBus_RS, TRUE);
    // write upper 4 bits
    readPortB(&portB);
    portB = portB | ((cData >> 4) & 0x0F);
    writePortB(portB);
    displayToggleEnable();
    
    // write lower 4 bits
    portB = portB & 0xF0;
    portB = portB | (cData & 0x0F);
    writePortB(portB);
    displayToggleEnable();
}

void displayReadBusyAndAddress(Bool* pBusy, Byte* pAddress)
{
    pinConfig_t pinCfg;
    Byte upperBits = 0;
    Byte lowerBits = 0;
    
    if (bDataBusConfiguredAsOutput)
    {
        // configure data bits as inputs
        pinCfg.bOutput = FALSE;
        pinCfg.bPullUp = TRUE;
        configurePin(cDisplayBus_DB4,pinCfg);
        configurePin(cDisplayBus_DB5,pinCfg);
        configurePin(cDisplayBus_DB6,pinCfg);
        configurePin(cDisplayBus_DB7,pinCfg);
        bDataBusConfiguredAsOutput = pinCfg.bOutput;
    }
    // clear RS
    writePin(cDisplayBus_RS,FALSE);
    // set RW
    writePin(cDisplayBus_RW,TRUE);
    displayToggleEnable();
    // read upper 4 bits
    readPin(cDisplayBus_DB7, pBusy);
    readPortB(&upperBits);
    upperBits = ((upperBits << 4) & 0x70);
    
    displayToggleEnable();
    // read lower 4 bits
    readPortB(&lowerBits); 
    *pAddress = (lowerBits & 0x0F) | (upperBits & 0xF0);
}

void displayFirstStart()
{
    displayOnOffControl_t onOffSetting;
    displayMovingDirection_t dirSetting;
    
    // wait 45 ms
    waitX100us(450);
        
    // write DB5 DB4
    displayPrepareBusForWrite();
    writePin(cDisplayBus_DB5, TRUE);
    writePin(cDisplayBus_DB4, TRUE);
    displayToggleEnable();
    
    // wait 5 ms
    waitX100us(50);
    
    // write DB5 DB4
    displayToggleEnable();
    
    // wait 0,5 ms
    waitX100us(5);
    
    // write DB5 DB4
    displayToggleEnable();
    
    //Function set (Set interface to be 4 bits long.)
    //Interface is 8 bits in length.
    // write upper 4 bits
    writePin(cDisplayBus_DB4, FALSE);
    displayToggleEnable();
    
    //Function set (Interface is 4 bits long. Specify the
    //number of display lines and character font.)
    //The number of display lines and character font
    //cannot be changed after this point.
    displayFunctionSet();
    
    //Display off
    onOffSetting.bDisplayOn = FALSE;
    onOffSetting.bCursorOn = FALSE;
    onOffSetting.bBlinkingCursorOn = FALSE;
    displayOnOffControl(onOffSetting);
    
    //Display clear
    displayClear();
    
    //Entry mode set
    dirSetting.bShiftRightInsteadOfLeft = TRUE;
    dirSetting.bShiftScreenInsteadOfCursor = FALSE;
    displayEntryModeSet(dirSetting);
}
