obj-m += mounts.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

#CONFIG_MODULE_SIG=n
#
#ifneq ($(KERNELRELEASE),)
#	obj-m := mounts.o
#else
#	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
#	PWD := $(shell pwd)
#
#all:
#	make -C $(KERNELDIR) M=$(PWD) modules
#
#default:
#	make -C $(KERNELDIR) M=$(PWD) modules
#endif
#
