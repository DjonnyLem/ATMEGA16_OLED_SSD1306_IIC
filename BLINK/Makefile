MCU=atmega16
F_CPU=8000000 
CC=avr-gcc
OBJCOPY=avr-objcopy
CFLAGS=-Wall -g -Os -mmcu=${MCU} 
#CFLAGS=-Wall -g -Os -mmcu=${MCU} -DF_CPU=${F_CPU} -I.
TARGET=BLINK

SOURCE_FILES= BLINK.c TIMER.c
all:
	${CC} ${CFLAGS} -o ${TARGET}.o ${SOURCE_FILES}
	${OBJCOPY} -j .text -j .data -O ihex ${TARGET}.o ${TARGET}.hex 
#avr-gcc -Wall -g -Os -mmcu=atmega16 -o main.o main.c lcd_hd44780.c
#avr-objcopy -j .text -j .data -O ihex main.o main.hex
#${CC} ${CFLAGS} -o ${TARGET}.bin ${SRCS}

#${CC} ${CFLAGS} -o ${TARGET}.o ${SOURCE_FILES}
#${OBJCOPY} -j .text -j .data -O ihex ${TARGET}.bin ${TARGET}.hex
flash:
	sudo avrdude -p m16 -c avr911 -P /dev/ttyUSB0 -B 19200 -U flash:w:${TARGET}.hex:a

#avrdude -p ${MCU} -c usbasp -U flash:w:${TARGET}.hex:i -F -P usb
clean:
	rm -f *.bin *.o *.elf *.hex
#Если вы запустите в терминале простую команду make , будет выполнена только метка «all». При запуске (sudo) make flash будет выполнена метка «flash» и так далее.
#sudo avrdude -p m16 -c avr911 -P /dev/ttyUSB0 -B 19200 -U flash:w:$main.hex:a


#MCU=attiny13
#F_CPU=1200000
#CC=avr-gcc
#OBJCOPY=avr-objcopy
#CFLAGS=-std=c99 -Wall -g -Os -mmcu=${MCU} -DF_CPU=${F_CPU} -I.
#TARGET=main
#SRCS=main.c
#all:
#${CC} ${CFLAGS} -o ${TARGET}.bin ${SRCS}
#${OBJCOPY} -j .text -j .data -O ihex ${TARGET}.bin ${TARGET}.hex
#flash:
#avrdude -p ${MCU} -c usbasp -U flash:w:${TARGET}.hex:i -F -P usb
#clean:
#rm -f *.bin *.hex
#Если вы запустите в терминале простую команду make , будет выполнена только метка «all». При запуске (sudo) make flash будет выполнена #метка «flash» и так далее.

#make
#avr-gcc -std=c99 -Wall -g -Os -mmcu=attiny13 -DF_CPU=1200000 -I. -o main.bin main.c
#avr-objcopy -j .text -j .data -O ihex main.bin main.hex

#make flash



#Создание объектного файла, линковка и получение исполняемого модуля:
#avr-gcc -g -Os -mmcu=attiny2313 -c main.c
#avr-gcc -g -Os -mmcu=attiny2313 -o main.elf main.c
#avr-objcopy -j .text -j .data -O ihex main.elf main.hex
#Заливка:
#avrdude -c usbasp -p attiny2313 -U flash:w:main.hex

# Создание elf объектного файла
# avr-gcc -Wall -g -Os -mmcu=atmega16 -o BLINK.elf BLINK.c TIMER.c

# Дизассемблирование
#avr-objdump -d BLINK.elf

