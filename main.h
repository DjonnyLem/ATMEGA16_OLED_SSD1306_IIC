
#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>

#include "TIMER.h"
#include "TWI.h"
//#include "main.c"
//#include ".h"
//#include ".h"


#define i2c_PORT    PORTC
#define i2c_DDR		DDRC
#define i2c_SCL		PC0
#define i2c_SDA		PC1
#define COUNT_TIMER 125    // значение счетчика таймера для прерывания; COUNT_TIMER 125 ~ каждые 1mc
#define VALUE_CONTROL_I2C 5	//значение переменной CONTROL_I2C, что равно 5 * 1mc = 5mc

/* БИТОВЫЕ ОПЕРАЦИИ ============================================*/
#define   SetBit(reg, bit)           reg = reg | (1<<bit)		// УСТАНОВИТЬ БИТ            
#define   ClearBit(reg, bit)         reg = reg & (~(1<<bit))	// ОЧИСТИТЬ БИТА
#define   InvBit(reg, bit)           reg ^= (1<<bit)			// ИНВЕРТИРОВАТЬ БИТ
#define   BitIsSet(reg, bit)       ((reg &  (1<<bit)) != 0)		// ПРОВЕРКА: УСТАНОВЛЕН ЛИ БИТ
#define   BitIsClear(reg, bit)     ((reg &  (1<<bit)) == 0)		// ПРОВЕРКА: ОЧИСТЕН ЛИ БИТ

/* ПРОТОТИПЫ ФУНКЦИЙ ============================================*/
void Init_Port(void);

/* ПЕРЕМЕННЫЕ, ОПРЕДЕЛЕННЫЕ В ДРУГОМ ФАЙЛЕ ============================================*/
extern uint8_t CONTROL_I2C; 
extern uint8_t status;


#endif /* MAIN_H_ */
