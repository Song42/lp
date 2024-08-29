obj-m		= debugfs.o

debugfs-y	= foo.o id.o main.o

KERN-VERSION	= $(shell uname -r)

all:
#		mount -t debugfs none /sys/kernel/debug
		make -C /lib/modules/$(KERN-VERSION)/build M=$(PWD) modules

chmod:
		chmod +r /sys/kernel/debug/fortytwo

clean:
		make -C /lib/modules/$(KERN-VERSION)/build M=$(PWD) clean
