//
//  i2c.c
//
//
//  Created by NullWolf on 09/07/17.
//  Copyright © 2017 NullWolf. All rights reserved.
//


#ifndef i2c_h
#define i2c_h

#define F_I2C 100000LL
#define TRANSMISSION_SUCCESS -1
#define TRANSMISSION_ERROR -2
#define BUS_CONNECTED -3
#define BUS_DISCONNECTED -4
#define MASTER_TRANSMITTER 0
#define MASTER_RECEIVER 1
#define ACK 0
#define TIMEOUT 50

typedef uint8_t bool;

/*
 * Initialize I2C as bus master
 *
 * I2C frequency should be set at least 16 times less than the slave CPU
 * frequency.
 *
 *     F_I2C = F_CPU / (16 + (2 * TWBR * TWSR_prescalar))
 */

/*
* Частота I2C должна быть установлена как минимум в 16 раз меньше частоты ведомого процессора.
*/
void i2c_init(void);

/*
 * Transmit start condition
 *
 * I2C commands are initiated by the master with a START condition. A START
 * condition is performed by the master actively pulling SDA low while SCL
 * remains high. After the START condition the bus is busy and can only be used
 * by another master only after a STOP condition is detected.
 *
 * Arguments:
 *      mode    The request control state of the master (transmit or receive).
 *              State of mode will control the R/W bit value.
 *
 * Returns:
 *     Transmission status code.
 */
/*
* Команды I2C инициируются мастером с условием START. Условие START выполняется мастером, который активно переводит SDA в низкий уровень, в то время как SCL остается высоким. После состояния СТАРТ шина занята и может использоваться другим мастером только после обнаружения состояния СТОП.
  *
  * Аргументы:
  * mode Состояние управления запросом ведущего устройства (передача или прием).
  * Состояние режима будет управлять значением бита R/W.
  *
  * Возвращает:
  * Код состояния передачи.
*/
uint8_t i2c_tx_start(bool mode);

/*
 * Transmit slave address
 *
 * Following the START condition the 7-bit slave address is transmitted along
 * with master mode/data direction bit (R/W) as the 8th bit. If the R/W bit is
 * 0 (SDA active low) then the master will write to the slave device. If the
 * R/W bit is 1 (SDA passive high) then the master will read from slave device.
 * The address/direction byte is acknowledged by the slave as the 9th bit.
 *
 * Arguments:
 *     address    7-bit address of slave
 *
 * Returns:
 *     Transmission status code
 */
/*
После условия START 7-битный адрес ведомого передается вместе с битом режима ведущего/направления данных (R/W) в качестве 8-го бита. Если бит R/W равен 0 (SDA активен на низком уровне), то мастер будет записывать на ведомое устройство. Если бит R/W равен 1 (пассивный высокий уровень SDA), то ведущее устройство будет считывать данные с ведомого устройства. Байт адреса/направления подтверждается ведомым устройством как 9-й бит.

  * Аргументы:
  * адрес 7-битный адрес ведомого
  *
  * Возвращает:
  * Код состояния передачи
*/
uint8_t i2c_tx_address(uint8_t address);

/*
 * Transmit byte of data
 *
 * Data on the I2C bus is transferred in 8-bit packets. Each byte that is
 * transmitted is acknowledged by the slave in the form of the 9th bit. This
 * bit indicates that the slave device is ready to proceed with the next byte.
 * If the slave device does not acknowledges transfer this  means that there is
 * no more data or the device is not ready for the transfer yet.
 *
 * Arguments:
 *     byteData    Data byte transmitted to slave
 *
 * Returns:
 *     Transmission status code
 */
/*
Данные по шине I2C передаются 8-битными пакетами. Каждый переданный байт подтверждается ведомым устройством в виде 9-го бита. Этот бит указывает, что ведомое устройство готово перейти к следующему байту. Если ведомое устройство не подтверждает передачу, это означает, что данных больше нет или устройство еще не готово к передаче.
  *
  * Аргументы:
  * byteData Байт данных, переданный ведомому
  *
  * Возвращает:
  * Код состояния передачи
*/
uint8_t i2c_tx_byte(uint8_t byteData);

/*
 * I2C Timeout
 *
 * Returns:
 *     Timeout status
 */

int8_t i2c_timeout(void);

/*
 * Receive byte of data
 *
 * Acknowledgement of the data transfer from the slave to master is stored as
 * an ACK (data received) or NACK (data not received). As long as ACK is being
 * reported to the slave after each byte then  the slave will continue sending
 * additional data to the master until NACK is transmitted.
 *
 * Arguments:
 *     acknack    Enable or disable of ACK generation
 *
 * Returns:
 *     One byte of data, or transmission status code
 */
/*
* Получить байт данных
* Подтверждение передачи данных от ведомого к ведущему сохраняется как ACK (данные получены) или NACK (данные не получены). Пока ACK передается ведомому устройству после каждого байта, ведомое устройство будет продолжать отправлять* дополнительные данные ведущему до тех пор, пока не будет передано NACK.
  *
  * Аргументы:
  * acknack Включение или отключение генерации ACK
  *
  * Возвращает:
  * Один байт данных или код состояния передачи
*/
uint8_t i2c_rx_byte(bool acknack);

/*
 * Transmit stop condition
 *
 * Once data frames have been sent the master will issue a STOP condition. Stop
 * conditions are defined by a low to high transition on SDA after a low to
 * high transition on SCL, with SCL remaining high.
 */
/*
* Как только кадры данных будут отправлены, мастер выдаст условие STOP. Условия остановки определяются переходом SDA от низкого уровня к высокому после перехода SCL от низкого к высокому, при этом уровень SCL остается высоким.
*/
void i2c_tx_stop(void);

#endif
