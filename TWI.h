#ifndef TWI_H_
#define TWI_H_

#include "main.h"

#define F_I2C 100000LL




/* ПРОТОТИПЫ ФУНКЦИЙ ============================================*/
void I2C_Init(void);
void I2C_StartCondition(void);
void I2C_StopCondition(void);
void I2C_SendByte(unsigned char c);

#endif /* TWI_H_ */

/*
variable status values значения переменной статус:

status:
15 - ошибка, отсутствует отклик slave; бит TWINT в регистре TWCR не выставится в 1 в течении установленного значения CONTROL_I2C 

*/
