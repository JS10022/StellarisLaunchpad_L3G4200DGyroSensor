

#include "inc/hw_gpio.h"
#include "inttypes.h"
#include "driverlib/rom.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "UART.h"


#define DELAY_MS(ms)    {ROM_SysCtlDelay(ms * (ROM_SysCtlClockGet() / 3000));} // multiplier for SysCtlGet() store in global variables
#define DELAY_US(us)    {ROM_SysCtlDelay(us * ((ROM_SysCtlClockGet() / 3000)/1000));} // multiplier for SysCtlGet() store in global variables
#define I2C_PORT I2C1_MASTER_BASE

void ftoa(float f,char *buf);
