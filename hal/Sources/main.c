#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

//#include "demo.h"
#include "buttons.h"
#include "display.h"
#include "pwm_test.h"
#include "io_test.h"
#include "kbi_test.h"
#include "timer_test.h"
#include "display_test.h"
#include "pwr_mgmt_test.h"

void main(void)
{
	EnableInterrupts

	test_pwrMgmt_recentReset_init();
	
	for (;;)
	{		
	    test_pwrMgmt_recentReset_run();
		__RESET_WATCHDOG()
		; /* feeds the dog */
	} /* loop forever */
	/* please make sure that you never leave main */
}
