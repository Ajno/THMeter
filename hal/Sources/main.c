#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

#include "demo.h"
#include "pwm_test.h"
#include "io_test.h"

void main(void)
{
	EnableInterrupts
	
	IoTest_inputOutput_init(SW_1,LED_1);
	PwmTest_pwm_init(5);
	
	for (;;)
	{
		IoTest_inputOutput_run();		
		PwmTest_pwm_run();
		
		__RESET_WATCHDOG()
		; /* feeds the dog */
	} /* loop forever */
	/* please make sure that you never leave main */
}
