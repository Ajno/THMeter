/*
 * buttons.cpp
 *
 *  Created on: Sep 17, 2015
 *      Author: Jano
 */

#include "buttons.h"

void buttonsInit()
{
    ioConfig_t config;
    config.bOutput = FALSE;
    config.bPullUp = TRUE;
    
    ioConfigure(cButton_Lower, config);
    ioConfigure(cButton_Upper, config);
}
