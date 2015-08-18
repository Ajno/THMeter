#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

//#include "demo.h"
#include "button.h"
//#include "display.h"
//#include "pwm_test.h"
//#include "io_test.h"
#include "kbi_test.h"

void main(void)
{
	EnableInterrupts
	
	test_kbi_init(BUTTON_LOW);
	test_kbi_init(BUTTON_UPP);
	
	for (;;)
	{
		__RESET_WATCHDOG()
		; /* feeds the dog */
	} /* loop forever */
	/* please make sure that you never leave main */
}
