
#define L3G4200D_I2C_ID     0x69
#define L3G4200D_WHO_AM_I            0x0F
#define L3G4200D_CTRL_REG1           0x20
#define L3G4200D_CTRL_REG2           0x21
#define L3G4200D_CTRL_REG3           0x22
#define L3G4200D_CTRL_REG4           0x23
#define L3G4200D_CTRL_REG5           0x24
#define L3G4200D_OUT_X_L             0x28
short L3G4200D_CheckDevice();
void L3G4200D_ReadRaw(short *pxraw, short *pyraw, short* pzraw);
void SetupL3G4200D();
