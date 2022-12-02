
#include "TWI.h"


//TWBR = значение регистра скорости передачи данных TWI.
//TWBR = ((F_CPU/F_SCL)-16) / (2*4^TWRS)


void I2C_Init(void)
{
 

    TWSR &= ~((1 << TWPS1) | (1 << TWPS0)); // Prescaler Value 00 -1 
    TWBR = 0x08; // baud rate factor (коэффициент скорости передачи) -8

}


void I2C_StartCondition(void)
{
	uint8_t CNT_STATUS = VALUE_CNT_STATUS;

	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
//				|			|			|----TWINT — статусный бит прерываний. Oн устанавливается аппаратно в тот момент,
//				|			|			|	когда определённое задание на шине завершится и будет ожидаться реакция программы. 	
//				|			|			|	Cбрасывается флаг не аппаратно, а программно записью в него логической (1).				
//				|			|---------------TWSTA — бит установки или генерирования условия "Старт".
//				|---------------------------TWEN — бит, активирующий шину I2C. Если мы его устанавливаем, то шина I2C начинает пытаться выполнять задание в зависимости от условий.
	CONTROL_I2C = VALUE_CONTROL_I2C; //защита от зависания при while. Если в течении 5ms не будет выставлен в 1 бит TWCR
				
	while((!(TWCR&(1<<TWINT))) || CNT_STATUS != 0) //подождем пока установится TWINT или CONTROL_I2C станет равен 0
	{
		if (CONTROL_I2C == 1)
		{
			CNT_STATUS --;
			CONTROL_I2C = 0;
		}
	}
	//CONTROL_I2C = 0; 
	status = 1;	 	  
}

void I2C_StopCondition(void)
{
  	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}


void I2C_SendByte(unsigned char c)
{

  TWDR = c;//запишем байт в регистр данных

  TWCR = (1<<TWINT)|(1<<TWEN);//включим передачу байта

  while (!(TWCR & (1<<TWINT)));//подождем пока установится TWIN

}


