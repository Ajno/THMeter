/*
 * display_test.cpp
 *
 *  Created on: Sep 11, 2015
 *      Author: z0037ysj
 */

#include "display_test.h"
#include "display.h"
#include "timer.h"

void test_display_hello_init()
{
    displayOnOffControl_t onOffSetting;
    Bool bBusy = TRUE;
    Byte address = 0;

    timerInit();
    displayInit();

    displayBackLightOn(TRUE);
    displayFirstStart();

    // Display on
    onOffSetting.bDisplayOn = TRUE;
    onOffSetting.bCursorOn = TRUE;
    onOffSetting.bBlinkingCursorOn = TRUE;
    displayOnOffControl(onOffSetting);
    // check busy flag
    do
    {
        displayReadBusyAndAddress(&bBusy, &address);
    } while (bBusy);

    //Display clear
    displayClear();
    waitX100us(20);

    displayWriteDataRam('A');
    waitX100us(1);
    displayWriteDataRam('h');
    waitX100us(1);
    displayWriteDataRam('o');
    waitX100us(1);
    displayWriteDataRam('j');
    waitX100us(1);

    displayWriteDataRam(' ');
    waitX100us(1);

    displayWriteDataRam('P');
    waitX100us(1);
    displayWriteDataRam('e');
    waitX100us(1);
    displayWriteDataRam('r');
    waitX100us(1);
    displayWriteDataRam('n');
    waitX100us(1);
    displayWriteDataRam('i');
    waitX100us(1);
    displayWriteDataRam('c');
    waitX100us(1);
    displayWriteDataRam('k');
    waitX100us(1);
    displayWriteDataRam('u');
    waitX100us(1);
    displayWriteDataRam('!');
    waitX100us(1);
}
