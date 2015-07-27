#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

#include "demo.h"
#include "pwm_test.h"
#include "io_test.h"

void main(void)
{
	EnableInterrupts
	
	IoTest_output testOutput1(LED_1);
//	PwmTest_timer testPwmTimer(LED_2);
	PwmTest_pwm testPwmPwm;
	
	for (;;)
	{
		testOutput1.run();		
		__RESET_WATCHDOG()
		; /* feeds the dog */
	} /* loop forever */
	/* please make sure that you never leave main */
}
