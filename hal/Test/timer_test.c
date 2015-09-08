/*
 * timer_test.c
 *
 *  Created on: Sep 8, 2015
 *      Author: z0037ysj
 */

#include "timer_test.h"
#include "timer.h"
#include "display.h"

static struct
{
    Word cntr;
    Bool light;
} test_wait = { 
        0, 
        FALSE };

void test_timer_wait_init()
{    
    timerInit();
    displayInit();
}

void test_timer_wait_run(const Word cDelayToggleX100ms)
{    
    waitX100us(1000);//100ms
    test_wait.cntr++;
    
    if (cDelayToggleX100ms <= test_wait.cntr) 
    {
        test_wait.light = !test_wait.light;
        displayBackLightOn(test_wait.light);
        test_wait.cntr = 0;
    }
}
