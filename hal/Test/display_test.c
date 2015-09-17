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

    timerInit();
    displayInit();

    displayBackLightOn(TRUE);

    // Display on
    onOffSetting.bDisplayOn = TRUE;
    onOffSetting.bCursorOn = TRUE;
    onOffSetting.bBlinkingCursorOn = TRUE;
    displayOnOffControl(onOffSetting);
    // check busy flag
    displayWaitTillNotBusy();

    //Display clear
    displayClear();
    displayWaitTillNotBusy();

    displayWrite("Display test, pohodlne sa usad a cum nato jak blb!");
}

void test_display_hello_run()
{
    displayMovingDirection_t dir;
    static Word cntr = 0;
    
    waitX100us(500); // wait 50 ms
    cntr++;
    if (cntr >= 20)
    {        
        dir.bShiftRightInsteadOfLeft = FALSE;
        dir.bShiftScreenInsteadOfCursor = TRUE;
        displayOrCursorShift(dir);
        displayWaitTillNotBusy();
        cntr = 0;
    }
}
