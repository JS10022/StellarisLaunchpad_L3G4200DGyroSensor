//Priyan R http://www.priyan.in 15-mar-1014
#include "inc/hw_gpio.h"
#include "inttypes.h"
#include "driverlib/rom.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "utils/uartstdio.h"
#include "common.h"
#include "L3G4200D.h"
#include "I2C.h"
#include "driverlib/i2c.h"
int main(void)
{
	  //
	// Enable lazy stacking for interrupt handlers.  This allows floating-point
	// instructions to be used within interrupt handlers, but at the expense of
	// extra stack usage.
	//
	ROM_FPULazyStackingEnable();
    //
    // Setup the system clock to run at 50 Mhz from PLL with crystal reference
    //
    SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|
                    SYSCTL_OSC_MAIN);
    //
    SetupUART();
    SetupI2C();
    //
    UARTprintf("Starting....\n");
    if(!L3G4200D_CheckDevice())
    {
    	UARTprintf("L3G4200D not detected\n");
    	while(1);
    }
    SetupL3G4200D();
    while(1)
    {
    	short x,y,z;
    	char buff[20];
    	L3G4200D_ReadRaw(&x,&y,&z);
    	ftoa(x,buff);
    	UARTprintf("X: %s,",buff);
    	ftoa(y,buff);
    	UARTprintf("Y: %s,",buff);
    	ftoa(z,buff);
    	UARTprintf("Z: %s\n",buff);
    	DELAY_MS(20);
    }
}

