//***************************************************************************
//
//  Author(s)...: Pashgan    http://ChipEnable.Ru   
//
//  Target(s)...: mega16
//
//  Compiler....: iar 5.11
//
//  Description.: ������ � TWI �������  �� �����������
//
//  Data........: 19.11.13 
//
//***************************************************************************
#include "config.h"
#include <ioavr.h>
#include <intrinsics.h>
#include <stdint.h>
#include "twim.h"
#include "lcd_lib.h"

#define ASCII_NUL     '0'
#define DS1307_ADR    104
#define SIZE_UINT8    3

uint8_t buf[8];
uint8_t sec, min, hour;

int main( void )
{
   LCD_Init();
   TWI_MasterInit(100);
   
   LCD_Goto(0, 0);
   LCD_SendString("iar time:");
   
   __enable_interrupt();

   /*�������������� ���������*/
  buf[0] = (DS1307_ADR<<1)|0;  //�������� �����
  buf[1] = 0;                  //����� ��������
  buf[2] = (5<<4)|5;           //�������� ������ 
  buf[3] = (5<<4)|9;           //�������� ����� 
  buf[4] = 0;                  //�������� �����
   
   /*���������� ���*/
   TWI_SendData(buf, 5);
   
   while(1){
    
       /*������������� ��������� DS1307 
       �� ������� �����*/
      buf[0] = (DS1307_ADR<<1)|0; //�������� �����
      buf[1] = 0;                 //����� ��������   

      TWI_SendData(buf, 2);
   
      /*��������� ����� � DS1307*/
      buf[0] = (DS1307_ADR<<1)|1;
      TWI_SendData(buf, 5);
      
      /*������������ ������ ������ 
      �������� � ���� �����*/
      TWI_GetData(buf, 5);
      
      sec  = buf[1];
      min  = buf[2];
      hour = buf[3];
       
      /*������� ����� �� LCD*/
      LCD_Goto(0, 1);
      LCD_WriteData((hour>>4)  + ASCII_NUL);
      LCD_WriteData((hour&0xf) + ASCII_NUL);    
      LCD_WriteData(':');
      LCD_WriteData((min>>4)  + ASCII_NUL);
      LCD_WriteData((min&0xf) + ASCII_NUL);    
      LCD_WriteData(':');    
      LCD_WriteData((sec>>4)  + ASCII_NUL);
      LCD_WriteData((sec&0xf) + ASCII_NUL);    
   
      /*����� �� ��������� �����, ������ �������*/
    
      __delay_cycles(4000000); 
    
  }
  return 0;
}

/*����� ����� �� LCD*/
void LCD_Uint8(uint8_t value)
{
  char buf[SIZE_UINT8];
  uint8_t i;
  
  for (i = 0; i < SIZE_UINT8; i++){
       buf[i] = (char)((value % 10) + '0');
       value = value/10;
  }

  LCD_WriteData(buf[2]);
  LCD_WriteData(buf[1]);
  LCD_WriteData(buf[0]); 
}