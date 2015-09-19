/*
 * pwr_mgmt.h
 *
 *  Created on: Sep 19, 2015
 *      Author: Jano
 */

#ifndef PWR_MGMT_H_
#define PWR_MGMT_H_

#include <stdtypes.h>

void pwrMgmtInit();
void pwrMgmtGoToSleep(const Bool bDeepSleep);

#endif /* PWR_MGMT_H_ */
