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
    displayFirstStart();

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

    displayWriteDataRam('a');
    displayWaitTillNotBusy();
    displayWriteDataRam('h');
    displayWaitTillNotBusy();
    displayWriteDataRam('o');
    displayWaitTillNotBusy();
    displayWriteDataRam('j');
    displayWaitTillNotBusy();    
    displayWriteDataRam(' ');
    displayWriteDataRam('t');
    displayWaitTillNotBusy();
    displayWriteDataRam('o');
    displayWaitTillNotBusy();
    displayWriteDataRam('t');
    displayWaitTillNotBusy();
    displayWriteDataRam('o');
    displayWaitTillNotBusy();
    displayWriteDataRam(' ');
    displayWriteDataRam('j');
    displayWaitTillNotBusy();
    displayWriteDataRam('e');
    displayWaitTillNotBusy();
    displayWriteDataRam(' ');
    displayWaitTillNotBusy();
    displayWriteDataRam('t');
    displayWaitTillNotBusy();
    displayWriteDataRam('e');
    displayWaitTillNotBusy();
    displayWriteDataRam('s');
    displayWaitTillNotBusy();    
    displayWriteDataRam('t');
    displayWaitTillNotBusy();
    displayWriteDataRam(' ');
    displayWaitTillNotBusy();
    displayWriteDataRam('1');
    displayWaitTillNotBusy();
    displayWriteDataRam('2');
    displayWaitTillNotBusy();
    displayWriteDataRam('3');
    displayWaitTillNotBusy();
    displayWriteDataRam('4');
    displayWaitTillNotBusy();
    displayWriteDataRam('5');
    displayWaitTillNotBusy();
    displayWriteDataRam('6');
    displayWaitTillNotBusy();
    displayWriteDataRam('7');
    displayWaitTillNotBusy();
    displayWriteDataRam('8');
    displayWaitTillNotBusy();
    displayWriteDataRam('9');
    displayWaitTillNotBusy();
    displayWriteDataRam(' ');
    displayWaitTillNotBusy();
    displayWriteDataRam('*');
    displayWaitTillNotBusy();
    displayWriteDataRam('*');
    displayWaitTillNotBusy();
    displayWriteDataRam('.');
    displayWaitTillNotBusy();
    displayWriteDataRam('.');
    displayWaitTillNotBusy();
    displayWriteDataRam('.');
    displayWaitTillNotBusy();
    displayWriteDataRam('.');
    displayWaitTillNotBusy();
    displayWriteDataRam('.');
    displayWaitTillNotBusy();
    displayWriteDataRam('*');
    displayWaitTillNotBusy();
    displayWriteDataRam('*');
    displayWaitTillNotBusy();
    displayWriteDataRam(' ');
    displayWaitTillNotBusy();
    displayWriteDataRam('~');
    displayWaitTillNotBusy();
    displayWriteDataRam('@');
    displayWaitTillNotBusy();
    displayWriteDataRam('#');
    displayWaitTillNotBusy();
    displayWriteDataRam('$');
    displayWaitTillNotBusy();
    displayWriteDataRam('%');
    displayWaitTillNotBusy();
    displayWriteDataRam('');
    displayWaitTillNotBusy();
    displayWriteDataRam('&');
    displayWaitTillNotBusy();
    displayWriteDataRam(')');
    displayWaitTillNotBusy();
    displayWriteDataRam('(');
    displayWaitTillNotBusy();
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
