#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_AUTHOR("schaehun");
MODULE_DESCRIPTION("keyboard_rules");
MODULE_LICENSE("GPL");
MODULE_VERSION("1.0");

static int __init device_init(void) {
	printk(KERN_INFO "device: listening for keyboard\n");
	return 0;
}

static void __exit device_exit(void) {
	printk(KERN_INFO "device: stopped listening\n");
}

module_init(device_init);
module_exit(device_exit);
