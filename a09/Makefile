#obj-m += mounts.o
#
#all:
#	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
#clean:
#	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
#
#test: all
#	#rmmod -f mounts
#	insmod mounts.ko
#	mount -t debugfs none /sys/kernel/debug/
#	echo -n schaehun > /sys/kernel/debug/fortytwo/id || true
#	cat /sys/kernel/debug/fortytwo/id && echo
#	echo "hello world!" > /sys/kernel/debug/fortytwo/foo
#	cat /sys/kernel/debug/fortytwo/foo
#	cat /sys/kernel/debug/fortytwo/jiffies

CONFIG_MODULE_SIG=n

ifneq ($(KERNELRELEASE),)
	obj-m := mounts.o
else
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)

all:
	make -C $(KERNELDIR) M=$(PWD) modules

default:
	make -C $(KERNELDIR) M=$(PWD) modules
endif

