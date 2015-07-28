#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

#include "demo.h"
#include "pwm_test.h"
#include "io_test.h"

void main(void)
{
	EnableInterrupts
	
	IoTest_inputOutput testIo1(SW_1, LED_1);
	IoTest_inputOutput testIo2(SW_2, LED_2);
//	PwmTest_timer testPwmTimer(LED_2);
	PwmTest_pwm testPwmPwm;
	
	for (;;)
	{
		testIo1.run();		
		testIo2.run();	
		__RESET_WATCHDOG()
		; /* feeds the dog */
	} /* loop forever */
	/* please make sure that you never leave main */
}
