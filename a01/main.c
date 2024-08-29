#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_AUTHOR("schaehun");
MODULE_DESCRIPTION("hello world");
MODULE_LICENSE("GPL");
MODULE_VERSION("1.0");
MODULE_INFO(intree, "Y");

static int __init hello_init(void)
{
	printk(KERN_INFO "Hello World!\n");
	return 0;
}

static void __exit hello_cleanup(void)
{
	printk(KERN_INFO "Cleaning up module.\n");
}

module_init(hello_init);
module_exit(hello_cleanup);
