//
//  i2c.h
//  



#include <avr/io.h>
#include "i2c.h"
#include "main.h"
static bool masterMode;


//TWBR = значение регистра скорости передачи данных TWI.
//TWBR = ((F_CPU/F_SCL)-16) / (2*4^TWRS)


void I2C_Init(void)
{
    TWSR &= ~((1 << TWPS1) | (1 << TWPS0)); // Prescaler Value 00 = 1 
    TWBR = 0x08; // коэффициент скорости передачи)  = 8
}


uint8_t i2c_tx_start(bool mode)
{
    int8_t status = 0;
    masterMode = mode; // установливаем глобальное состояние бита R/W

    /* clear interrupt flag, issue start command (gain control of bus as
       master), enable I2C (SCL and SDA are automatically reconfigured) */
	/*сбросить флаг прерывания, подать команду запуска (получить контроль над шиной как
        master), включить I2C (SCL и SDA автоматически перенастраиваются)*/
    TWCR |=  (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
//				|				|				|___ TWEN — бит, активирующий шину I2C. Если мы его устанавливаем, то шина I2C начинает пытаться выполнять задание в зависимости от условий.				
//				|				|___________________ TWSTA — бит установки или генерирования условия "Старт".
//				|___________________________________ TWINT — статусный бит прерываний. Oн устанавливается аппаратно в тот момент, когда определённое задание на шине завершится и будет ожидаться реакция программы. Cбрасывается флаг не аппаратно, а программно записью в него логической (1). 	

    /* wait until start transmitted */
	/* дождаться начала передачи */
    while (!(TWCR & (1 << TWINT))); //подождем пока установится бит флага TWINT равный 0. Это указывает на то, что условие СТАРТ было передано

    switch (TWSR & 0xF8) //маскируем TWSR & 0xF8 (0b11111000) для получения  байтов 7..3. Биты TWS7.. TWS3 содержат статусный код
	{
        /* start condition sent from master */
		/* условие запуска, отправленное мастером */
        case 0x08:  
            status = TRANSMISSION_SUCCESS;
            break;

        /* repeat start condition sent from master */
		/* повторить условие запуска, отправленное от мастера */
        case 0x10:
            status = TRANSMISSION_SUCCESS;
            break;

        default:
            status = TRANSMISSION_ERROR;
            break;
    }

    return status;
}


uint8_t i2c_tx_address(uint8_t address)
{
    int8_t status = 0;

    TWDR = (address << 1) | masterMode; // записываем в регистр TWDR адрес устройства (биты 7..1) и статусный бит (бит 0)
    /* clear start command to release bus as master */
	/* чёткая каманда запуска что бы освободить шину как ведущую */
    TWCR &= ~(1 << TWSTA); 
//				|_____________ TWSTA (TWI START Condition Bit) - флаг состояния СТАРТ. Когда этот бит устанавливается в 1, TWI модуль проверяет не занята ли шина и формирует состояние СТАРТ. Если шина занята, он будет ожидать появления на ней состояния СТОП и после этого выдаст состояние СТАРТ. Бит TWSTA должен быть очищен программно, когда состояние СТАРТ передано.
    /* clear interrupt flag */
    TWCR |=  (1 << TWINT);
//				|_____________ TWINT(TWI Interrupt Flag) - флаг прерывания TWI модуля. Этот бит устанавливается аппаратно, когда TWI модуль завершает текущую операцию (формирование состояния СТАРТ, передачи адресного пакета и так далее). При этом если установлен бит глобального разрешения прерываний (бит I регистра SREG) и разрешены прерывания TWI модуля, то вызывается соответствующий обработчик.
    /* wait until address transmitted */
	/* ждем пока передачи адреса */
    while (!(TWCR & (1 << TWINT)));

    if (masterMode == MASTER_TRANSMITTER) {
        switch (TWSR & 0xF8) {
            /* address|write sent and ACK returned */
            case 0x18:
                status = TRANSMISSION_SUCCESS;
                break;

           /* address|write sent and NACK returned slave */
			/* был передан адресный пакет SLA-W (адресный пакет, после которого ведущий передает данные ведомому)без подтверждения ведомого */
           case 0x20:
                status = TRANSMISSION_ERROR;
                break;

            /* address|write sent and bus failure detected */
			/* 0x38 - адрес | запись отправлена и обнаружен сбой шины. Потеря приоритета (это когда один или несколько ведущих начали передачу данных одновременно с нами и кто-то из них в итоге занял шину) */
            case 0x38:
                status = TRANSMISSION_ERROR;
                break;

            default:
                status = TRANSMISSION_ERROR;
                break;
        }
    } else if (masterMode == MASTER_RECEIVER) {
        switch (TWSR & 0xF8) {
            /* address|read sent and ACK returned */
			/* 0x40 - был передан адресный пакет SLA+R и получено подтверждение от ведомого */
            case 0x40:
                status = TRANSMISSION_SUCCESS;
                break;

            /* address|read sent and NACK returned */
			/* 0x48 - был передан адресный пакет SLA+R без подтверждения ведомого */
            case 0x48:
                status = TRANSMISSION_ERROR;
                break;
			/* 0x38 - адрес | запись отправлена и обнаружен сбой шины. Потеря приоритета (это когда один или несколько ведущих начали передачу данных одновременно с нами и кто-то из них в итоге занял шину) */
            case 0x38:
                status = TRANSMISSION_ERROR;
                break;

            default:
                status = TRANSMISSION_ERROR;
                break;
        }
    }

    return status;
}

uint8_t i2c_tx_byte(uint8_t byteData)
{
    int8_t status = 0;
    TWDR  = byteData; // load data buffer with data to be transmitted. загрузить буфер данных с данными для передачи
    TWCR |= (1 << TWINT); // clear interrupt flag
//				|_____________ TWINT(TWI Interrupt Flag) - флаг прерывания TWI модуля. Этот бит устанавливается аппаратно, когда TWI модуль завершает текущую операцию (формирование состояния СТАРТ, передачи адресного пакета и так далее). При этом если установлен бит глобального разрешения прерываний (бит I регистра SREG) и разрешены прерывания TWI модуля, то вызывается соответствующий обработчик.
    /* wait until data transmitted */
    while (!(TWCR & (1 << TWINT)));

    /* retrieve transmission status codes */
    switch (TWSR & 0xF8) {
        /* byte sent and ACK returned */
		/* 0x28 - был передан байт данных и получено подтверждение от ведомого  */
        case 0x28:
            status = TRANSMISSION_SUCCESS;
            break;

        /* byte sent and NACK returned */
		/* 0x30 - был передан байт данных без подтверждения ведомого */
        case 0x30:
            status = TRANSMISSION_ERROR;
            break;

        /* byte sent and bus failure detected */
		/* 0x38 - адрес | запись отправлена и обнаружен сбой шины. Потеря приоритета (это когда один или несколько ведущих начали передачу данных одновременно с нами и кто-то из них в итоге занял шину) */
        case 0x38:
            status = TRANSMISSION_ERROR;
            break;

        default:
            status = TRANSMISSION_ERROR;
            break;
    }

    return status;
}

int8_t i2c_timeout(void)
{
    uint8_t time = TIMEOUT;
    int8_t status = BUS_DISCONNECTED;

    while (time-- > 0) {
        /* check to see if bus is ready */
		/* проверяем, готова ли шина */
        if ((TWCR & (1 << TWINT))) {
            status = BUS_CONNECTED;
            break;
        }
    }

    return status;
}

uint8_t i2c_rx_byte(bool response)
{
    int8_t status;

    if (response == ACK) {
        TWCR |= (1 << TWEA); // generate ACK // ответ ACK
    } else {
        TWCR &= ~(1 << TWEA); // generate NACK // ответ NACK
    }

    /* clear interrupt flag */
    TWCR |= (1 << TWINT);

    /* detect bus time-out */
    if (i2c_timeout() != BUS_DISCONNECTED) {
        /* retrieve transmission status codes or received data */
        switch (TWSR & 0xF8) {
            /* data byte read and ACK returned by master */
            case 0x50:
                status = TWDR;
                break;

            /* data byte read and NACK returned by master */
            case 0x58:
                status = TWDR;
                break;

            /* bus failure detected */
            case 0x38:
                status = TRANSMISSION_ERROR;
                break;

            default:
                status = TRANSMISSION_ERROR;
                break;
        }
    } else {
        status = TRANSMISSION_ERROR;
    }

    return status;
}

void i2c_tx_stop(void)
{
    /* clear interrupt flag, issue stop command (cleared automatically) */
	/* очистить флаг прерывания, выдать команду остановки (сбрасывается автоматически) */
    TWCR |= (1 << TWINT) | (1 << TWSTO);

    while (!(TWCR & (1 << TWSTO))); // wait until stop transmitted
//						|_____________ TWSTO (TWI STOP Condition Bit) - флаг состояния СТОП. Когда этот бит устанавливается в 1 в режиме ведущего, TWI модуль выдает на шину состояние СТОП и сбрасывает этот бит. В режиме ведомого установка этого бита может использоваться для восстановления после ошибки. При этом состояние СТОП не формируется, но TWI модуль возвращается к начальному не адресованному состоянию.

}
