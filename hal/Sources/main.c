#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

//#include "demo.h"
#include "button.h"
#include "display.h"
#include "pwm_test.h"
#include "io_test.h"

void main(void)
{
	EnableInterrupts
	
	test_io_inputOutput_init(BUTTON_LOW,LED_LCD);
	test_pwm_chnl_init(0);
	
	for (;;)
	{
		test_io_inputOutput_run();
//		test_pwm_chnl_run();
		
		__RESET_WATCHDOG()
		; /* feeds the dog */
	} /* loop forever */
	/* please make sure that you never leave main */
}
