//v.1 
//Программа подключения дисплея OLED дисплея SSD1306, 0.96 дюйма, 128X64 по протоколу IIC к микроконтрлллеру Atmega16
// Цель: разобрать принцип инициализации дисплея, отражения информации на дисплее, работа по протоколу I2C
#include "main.h"

//#define i2c_PORT	PORTC
//#define i2c_DDR		DDRC
//#define i2c_SCL		PC0
//#define i2c_SDA		PC1

int main(void) {
	  
    OLED_Init();  //initialize the OLED
    OLED_Clear(); //clear the display (for good measure)
    
    while (1) {
        
        OLED_SetCursor(0, 0);        //set the cursor position to (0, 0)
        OLED_Printf("Hello World!"); //Print out some text

    }
    
    return 0; // never reached
}


/********************************************************************
* 	ИНИЦИАЛИЗАЦИЯ ПОРТОВ
*********************************************************************/

/*
void Init_Port(void)
{
	DDRA = 0b00000000; // БИТ ПОРТА A НА ВХОД канал АЦП
	PORTA |=(1<<PA0); //= 0b00000001; //УСТАНАВЛИВАЕМ В БИТЕ ПОРТА A ПОДТЯЖКУ
//PC1 PC0

//i2c_PORT |= 1<<i2c_SCL|1<<i2c_SDA;	// Включим подтяжку на ноги, вдруг юзер на резисторы пожмотился
//i2c_DDR &=~(1<<i2c_SCL|1<<i2c_SDA);
};	
	*/


