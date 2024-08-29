#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include "debugfs.h"

MODULE_AUTHOR("schaehun");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("from assignement 05");

#define LOGIN "schaehun"

static ssize_t id_read(struct file *file, char __user *buf, size_t count, loff_t *ppos) {
	return simple_read_from_buffer(buf, count, ppos, LOGIN, strlen(LOGIN));
}

static ssize_t id_write(struct file *file, const char __user *buf, size_t count, loff_t *ppos) {
	char kernel_buf[32];
	ssize_t len;

	for (int i = 0; i < sizeof(kernel_buf); i++)
		kernel_buf[i] = 0;
	
	len = simple_write_to_buffer(kernel_buf, sizeof(kernel_buf) - 1, ppos, buf, count);
	if (len < 0)
		return len;
	kernel_buf[len] = 0;

	if (strcmp(kernel_buf, LOGIN) == 0)
		return count;
	else
		return -EINVAL;
}

const struct file_operations	fops_id = {
	owner	: THIS_MODULE,
	read	: id_read,
	write	: id_write,
};
