#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("schaehun");
MODULE_DESCRIPTION("misc");

#define LOGIN "schaehun"

static ssize_t ft_read(struct file *file, char __user *buf, size_t count, loff_t *ppos) {
	int len = simple_read_from_buffer(buf, count, ppos, LOGIN, strlen(LOGIN));
	//printk(KERN_INFO "@@@@ read: ppos: %ld\n", *ppos);
	return len;
}

static ssize_t ft_write(struct file *file, const char __user *buf, size_t count, loff_t *ppos) {
	char kernel_buf[32];
	ssize_t len;

	//printk(KERN_INFO "@@@@ write: ppos: %ld\n", *ppos);
	for (int i = 0; i < sizeof(kernel_buf); i++)
		kernel_buf[i] = 0;
	
	printk(KERN_INFO "count: %ld\nbuf: %s\n", count, buf);
	*ppos = 0;
	len = simple_write_to_buffer(kernel_buf, sizeof(kernel_buf) - 1, ppos, buf, count);
	if (len < 0)
		return len;
	kernel_buf[len] = 0;

	//printk(KERN_INFO "in loop:\n");
	//for (int i = 0; i < len * 2; i++)
	//	printk(KERN_INFO "%c ", kernel_buf[i]);
	//printk(KERN_INFO "end loop\n");

	printk(KERN_INFO "kernel_buf = %s\nlen: %ld\n", kernel_buf, len);

	if (strcmp(kernel_buf, LOGIN) == 0)
		return count;
	else
	{
		printk(KERN_INFO "%s, %ld\n",kernel_buf, len);
		return -EINVAL;
	}
}

static const struct file_operations ft_fops = {
	.owner = THIS_MODULE,
	.read = ft_read,
	.write = ft_write,
};

static struct miscdevice ft_device;

static int __init ft_init(void) {
	int	ret;

	ft_device.minor = MISC_DYNAMIC_MINOR;
	ft_device.name = "fortytwo";
	ft_device.fops = &ft_fops;

	ret = misc_register(&ft_device);
	if (ret)
		printk(KERN_ERR "Can not register misc device. name : %s\n", "fortytwo");
	else
		printk(KERN_INFO "misc device registed. name : %s\n", "fortytwo");

	return ret;
}

static void __exit ft_exit(void) {
	misc_deregister(&ft_device);
	printk(KERN_INFO "misc device deregisted. name : %s\n", "fortytwo");
}

module_init(ft_init);
module_exit(ft_exit);
