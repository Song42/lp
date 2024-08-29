#include <linux/module.h>
#include <linux/debugfs.h>
#include <linux/fs.h>
#include <linux/init.h>
#include "debugfs.h"

MODULE_AUTHOR("schaehun");
MODULE_DESCRIPTION("learning debugfs");
MODULE_LICENSE("GPL");
MODULE_VERSION("1.0");

static struct dentry *dfs_fortytwo;
static struct dentry *dfs_id;
static struct dentry *dfs_foo;
static struct dentry *dfs_jiffies;

static int __init debugfs_init(void)
{
	printk(KERN_INFO "debugfs: init\n");

	dfs_fortytwo = debugfs_create_dir("fortytwo", NULL);
	if (!dfs_fortytwo)
	{
		printk(KERN_ERR "debugfs: create_dir error\n");
		return -1;
	}
	
	dfs_id = debugfs_create_file("id", 0666, dfs_fortytwo, NULL, &fops_id);
	if (!dfs_id)
	{
		printk(KERN_ERR "debugfs: create_file error: %s\n", "id");
		debugfs_remove(dfs_fortytwo);
		return -1;
	}

#if BITS_PER_LONG == 64
	debugfs_create_u64("jiffies", 0444, dfs_fortytwo, (u64*) &jiffies);
#else
	debugfs_create_u32("jiffies", 0444, dfs_fortytwo, (u32*) &jiffies);
#endif

	dfs_foo = debugfs_create_file("foo", 0644, dfs_fortytwo, NULL, &fops_foo);
	if (!dfs_foo)
	{
		debugfs_remove(dfs_id);
		debugfs_remove(dfs_jiffies);
	}

	return 0;
}

static void __exit debugfs_exit(void)
{
	debugfs_remove_recursive(dfs_fortytwo);
	printk(KERN_INFO "debugfs: exit\n");
}

module_init(debugfs_init);
module_exit(debugfs_exit);
