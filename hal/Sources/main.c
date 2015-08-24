#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

//#include "demo.h"
//#include "buttons.h"
//#include "display.h"
//#include "pwm_test.h"
//#include "io_test.h"
//#include "kbi_test.h"
#include "timer.h"
#include "display.h"

void main(void)
{
	EnableInterrupts

	initTimer();
	initDisplay();

	for (;;)
	{
		setBackLight(TRUE);
		__RESET_WATCHDOG()
		; /* feeds the dog */
	} /* loop forever */
	/* please make sure that you never leave main */
}
