/*
 * system.c
 *
 *  Created on: Sep 19, 2015
 *      Author: Jano
 */

#include "system.h"
#include <derivative.h>

void systemConfigure(const systemConfig_t cCfg)
{
    SOPT1_STOPE  = cCfg.bStopModeEn;
    SPMSC1_LVDE  = cCfg.bLowVoltageDetectionEn;
    SPMSC1_LVDSE = cCfg.bLowVoltageDetectionInStopModeEn;
    SPMSC1_LVDRE = cCfg.bLowVoltageResetEn;
    SPMSC3_LVDV  = cCfg.bLowVoltageTripPointHigh;
    SPMSC3_LVWV  = cCfg.bLowVoltageWarningPointHigh;
}

void systemWait()
{
    _Wait;
}

void systemStop()
{
    _Stop;
}

Bool systemLowVoltageWarningDeteced()
{
    return (SPMSC3_LVWF == 1);
}

void systemClearLowVoltageWarning()
{
    SPMSC3_LVWACK = 0;
}

void systemStatusRead(Byte* pStatus)
{
    *pStatus = SRS;
}
