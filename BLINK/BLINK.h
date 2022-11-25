
#ifndef BLINK_H_
#define BLINK_H_

#define F_CPU 1000000UL

#include <avr/io.h>
#include <avr/interrupt.h>

#include "TIMER.h"

/* БИТОВЫЕ ОПЕРАЦИИ ============================================*/
#define   SetBit(reg, bit)           reg = reg | (1<<bit)		// УСТАНОВИТЬ БИТ            
#define   ClearBit(reg, bit)         reg = reg & (~(1<<bit))	// ОЧИСТИТЬ БИТА
#define   InvBit(reg, bit)           reg ^= (1<<bit)			// ИНВЕРТИРОВАТЬ БИТ
#define   BitIsSet(reg, bit)       ((reg &  (1<<bit)) != 0)		// ПРОВЕРКА: УСТАНОВЛЕН ЛИ БИТ
#define   BitIsClear(reg, bit)     ((reg &  (1<<bit)) == 0)		// ПРОВЕРКА: ОЧИСТЕН ЛИ БИТ

/* ПРОТОТИПЫ ФУНКЦИЙ ============================================*/
void Init_Port(void);


#endif /* BLINK_H_ */

/*
unsigned char - хранит числа от 0 до 255 (байт)
unsigned int - хранит числа от 0 до 65535 (слово == 2 байта)
unsigned long int - хранит от 0 до 4294967295   (двойное слово == 4 байта)


*/
