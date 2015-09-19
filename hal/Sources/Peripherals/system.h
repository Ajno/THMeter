/*
 * system.h
 *
 *  Created on: Sep 19, 2015
 *      Author: Jano
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <stdtypes.h>

typedef struct
{
    Bool bStopModeEn;
    Bool bLowVoltageDetectionEn;
    Bool bLowVoltageDetectionInStopModeEn;
    Bool bLowVoltageResetEn;
    Bool bLowVoltageTripPointHigh;
    Bool bLowVoltageWarningPointHigh;
}systemConfig_t;

void systemConfigure(const systemConfig_t cCfg);
void systemWait();
void systemStop();
Bool systemLowVoltageWarningDeteced();
void systemClearLowVoltageWarning();
void systemStatusRead(Byte* pStatus);

#endif /* SYSTEM_H_ */
