
#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>


#include "TWI.h"
//#include ".h"
//#include ".h"


/* БИТОВЫЕ ОПЕРАЦИИ ============================================*/
#define   SetBit(reg, bit)           reg = reg | (1<<bit)		// УСТАНОВИТЬ БИТ            
#define   ClearBit(reg, bit)         reg = reg & (~(1<<bit))	// ОЧИСТИТЬ БИТА
#define   InvBit(reg, bit)           reg ^= (1<<bit)			// ИНВЕРТИРОВАТЬ БИТ
#define   BitIsSet(reg, bit)       ((reg &  (1<<bit)) != 0)		// ПРОВЕРКА: УСТАНОВЛЕН ЛИ БИТ
#define   BitIsClear(reg, bit)     ((reg &  (1<<bit)) == 0)		// ПРОВЕРКА: ОЧИСТЕН ЛИ БИТ

/* ПРОТОТИПЫ ФУНКЦИЙ ============================================*/
void Init_Port(void);




#endif /* MAIN_H_ */
