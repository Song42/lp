#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/mutex.h>
#include "debugfs.h"

DEFINE_MUTEX(foo_mutex);

static char	foo_buf[PAGE_SIZE];
static size_t	foo_buf_len = 0;

static ssize_t foo_read(struct file *f, char __user *buf, size_t count, loff_t *ppos)
{
	ssize_t	ret;

	mutex_lock(&foo_mutex);
	ret = simple_read_from_buffer(buf, count, ppos, foo_buf, foo_buf_len);
	mutex_unlock(&foo_mutex);
	return ret;
}

static ssize_t foo_write(struct file *f, const char __user *buf, size_t count, loff_t *ppos)
{
	int	not_copied;

	mutex_lock(&foo_mutex);
	if (count > PAGE_SIZE)
	{
		mutex_unlock(&foo_mutex);
		return -EINVAL;
	}

	not_copied = copy_from_user(foo_buf, buf, count);
	if (not_copied)
	{
		mutex_unlock(&foo_mutex);
		foo_buf_len = count - not_copied;
		return -EFAULT;
	}

	foo_buf_len = count;
	mutex_unlock(&foo_mutex);
	return count;
}

const struct file_operations	fops_foo = {
	owner	: THIS_MODULE,
	read	: foo_read,
	write	: foo_write,
};
