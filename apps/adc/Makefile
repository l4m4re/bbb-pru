PRU_COMPILER_DIR=/usr/share/ti/cgt-pru
PRU_PKG_INC_DIR=/opt/source/pru-software-support-package/include
PRU_C_FLAGS=--silicon_version=2 --hardware_mac=on -i$(PRU_COMPILER_DIR)/include -i$(PRU_COMPILER_DIR)/lib -i$(PRU_PKG_INC_DIR) -i$(PRU_PKG_INC_DIR)/am335x 
PRU_LD_FLAGS=-llibc.a

HOST_C_FLAGS += -Wall -g -O2 -mtune=cortex-a8 -march=armv7-a -I/usr/local/include
#HOST_LD_FLAGS += /usr/lib/libprussdrv.a -lpthread -lsndfile
HOST_LD_FLAGS += -lprussdrv -lpthread -lsndfile

FIND_ADDRESS_COMMAND=`dispru pru.elf | grep _c_int00 | cut -f1 -d\  `

.PHONY: all
all:
	# Compile pru.c into pro.obj
	clpru $(PRU_C_FLAGS) -c pru.c

	# Link pru.obj with libraries and output pru.map and pru.elf
	clpru $(PRU_C_FLAGS) -z pru.obj $(PRU_LD_FLAGS) \
		-m pru.map -o pru.elf AM3359_PRU.cmd

	# Convert pru.elf into text.bin and data.bin
	hexpru ./bin.cmd ./pru.elf

	# Find address of start of program and compile host program
	export START_ADDR=0x$(FIND_ADDRESS_COMMAND) && \
	gcc $(HOST_C_FLAGS) -DSTART_ADDR=`echo $$START_ADDR` -c -o host.o host.c && \
	gcc $(HOST_C_FLAGS) -o host host.o $(HOST_LD_FLAGS)

.PHONY: clean
clean:
	-rm -f *.obj
	-rm -f *.map
	-rm -f *.elf
	-rm -f *.bin
	-rm -f *.o
	-rm -f host
	-rm -f out.wav
	 
