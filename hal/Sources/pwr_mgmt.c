/*
 * pwr_mgmt.c
 *
 *  Created on: Sep 19, 2015
 *      Author: Jano
 */

#include "pwr_mgmt.h"
#include "system.h"

void pwrMgmtInit()
{
    systemConfig_t cfg;
    
    cfg.bStopModeEn = TRUE;
    cfg.bLowVoltageDetectionEn = TRUE;
    cfg.bLowVoltageDetectionInStopModeEn = TRUE;
    cfg.bLowVoltageResetEn = TRUE;
    cfg.bLowVoltageTripPointHigh = TRUE;
    cfg.bLowVoltageWarningPointHigh = TRUE;
    systemConfigure(cfg);
}

void pwrMgmtGoToSleep(const Bool bDeepSleep)
{
    if (bDeepSleep) 
    {        
        systemStop();
    } 
    else 
    {
        // todo disable PWM interrupt, ...
        systemWait();
    }
}
