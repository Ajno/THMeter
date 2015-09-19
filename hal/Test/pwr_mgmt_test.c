/*
 * pwr_mgmt_test.c
 *
 *  Created on: Sep 19, 2015
 *      Author: Jano
 */

#include "pwr_mgmt_test.h"
#include "pwr_mgmt.h"
#include "kbi.h"
#include "display.h"
#include "timer.h"
#include "buttons.h"

static kbiConfig_t kbiCfg;
static Bool bAwake = FALSE;

static test_pwrMgmt_isrCallback()
{
    displayBackLightOn(TRUE);
}

void test_pwrMgmt_init()
{
    displayOnOffControl_t setting;
    
    pwrMgmtInit();
    
    buttonsInit();
    
    kbiCfg.bPullUp = TRUE;
    kbiCfg.bRisingEdge = FALSE;
    kbiConfigure(cKbiIn_P2,kbiCfg);
    kbiInstallIsrCallback(&test_pwrMgmt_isrCallback);
    
    timerInit();
    
    displayInit();
    displayClear();
    setting.bBlinkingCursorOn = FALSE;
    setting.bCursorOn = FALSE;
    setting.bDisplayOn = TRUE;
    displayOnOffControl(setting);
    displayWrite("cierna - uspi");
    displayMoveCursor(cDisplayAddressMax/2);
    displayWrite("cervena - zobud");
    displayBackLightOn(TRUE);
}

void test_pwrMgmt_run()
{
    Bool bButtonState;
    
    buttonStateDetection(cButton_Upper, &bButtonState);
    if (cButtonState_JustPressed == bButtonState)
    {        
        displayBackLightOn(FALSE);
        systemStop();
    }
}
