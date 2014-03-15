#include "common.h"
#include "L3G4200D.h"
#include "I2C.h"
#include "inc/hw_gpio.h"
#include "inttypes.h"
#include "driverlib/rom.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
/* This code is based on   Stellaris IMU (FREEIMU PORT) https://code.google.com/p/stellaris-lp-imu/
 */
short L3G4200D_CheckDevice()
{
	if(i2c_RcvByte(L3G4200D_I2C_ID, L3G4200D_WHO_AM_I) == 0xD3)
		return 1;
	return 0;
}
void SetupL3G4200D()
{
	i2c_XmtByte(L3G4200D_I2C_ID, L3G4200D_CTRL_REG1, 0x3e); // "00011111"- Data rate 100Hz, BW 25Hz, power up, enable all axes
	i2c_XmtByte(L3G4200D_I2C_ID, L3G4200D_CTRL_REG4, 0x90); // "10010000"  500dps, disable selftest
}

void L3G4200D_ReadRaw(short *pxraw, short *pyraw, short* pzraw) {

	uint8_t buf[6];
	int16_t x, y, z;
	i2c_RcvBuf(L3G4200D_I2C_ID, L3G4200D_OUT_X_L | (1 << 7), 6, buf); //read the acceleration data from the L3G4200D
	// each axis reading comes in 13 bit 2's complement format. lsb first, msb has sign bits extended
	x = (int16_t) ((((uint16_t) buf[1]) << 8) | (uint16_t) buf[0]);
	*pxraw = (int) x;
	y = (int16_t) ((((uint16_t) buf[3]) << 8) | (uint16_t) buf[2]);
	*pyraw = (int) y;
	z = (int16_t) ((((uint16_t) buf[5]) << 8) | (uint16_t) buf[4]);
	*pzraw = (int) z;

}


