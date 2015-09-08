#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

//#include "demo.h"
//#include "buttons.h"
//#include "display.h"
//#include "pwm_test.h"
//#include "io_test.h"
//#include "kbi_test.h"
#include "timer_test.h"

void main(void)
{
	EnableInterrupts

	test_timer_wait_init();
	
	for (;;)
	{		
		test_timer_wait_run(5);//500ms
		__RESET_WATCHDOG()
		; /* feeds the dog */
	} /* loop forever */
	/* please make sure that you never leave main */
}
