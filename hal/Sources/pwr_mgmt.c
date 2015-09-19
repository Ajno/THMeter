/*
 * pwr_mgmt.c
 *
 *  Created on: Sep 19, 2015
 *      Author: Jano
 */

#include "pwr_mgmt.h"
#include <stdtypes.h>
#include "system.h"

void pwrMgmtInit()
{
    systemConfig_t cfg;
    
    cfg.bStopModeEn = TRUE;
    systemConfigure(cfg);
}
