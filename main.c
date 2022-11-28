//v.1 
//��������� ����������� ������� OLED ������� SSD1306, 0.96 �����, 128X64 �� ��������� IIC � ���������������� Atmega16
// ����: ��������� ������� ������������� �������, ��������� ���������� �� �������, ������ �� ��������� I2C
#include "main.h"





#define i2c_PORT    PORTC
#define i2c_DDR		DDRC
#define i2c_SCL		PC0
#define i2c_SDA		PC1

int main(void) {


    Init_Port();
    I2C_Init();
    I2C_StartCondition();
    unsigned char temp_TWSR = TWSR;
     temp_TWSR &= (~(1<<2)|(1<<1)|(1<<0));
	
    if (temp_TWSR == 0x08)
    {
    SetBit(DDRD,6);
    SetBit(PORTD,6);
    }
    else
    {
     SetBit(DDRD,5);
     SetBit(PORTD,5);
    }
	  
    //OLED_Init();  //initialize the OLED
    //OLED_Clear(); //clear the display (for good measure)
    
    while (1) {
        
        //OLED_SetCursor(0, 0);        //set the cursor position to (0, 0)
        //OLED_Printf("Hi, Artem Lem!"); //Print out some text

    }
    
    return 0; // never reached
}


/********************************************************************
* 	������������� ������
*********************************************************************/


void Init_Port(void)
{
    i2c_PORT |= (1<<i2c_SCL)|(1<<i2c_SDA);	// ������� �������� �� ����, ����� ���� �� ��������� ����������
    i2c_DDR &=~(1<<i2c_SCL|1<<i2c_SDA);
}	



