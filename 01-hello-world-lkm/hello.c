#define pr_fmt(fmt)	KBUILD_MODNAME ": " fmt

#include <linux/module.h>
#include <linux/init.h>	
#include <linux/errno.h>


static int num = -100;
static char string[] = "Dinesh";

static int __init hello_mod_init(void){
	pr_info("Hello world %s\n", string);
	return 0;	/* 0 means success; non-zero means init failed */
}

static void __exit hello_mod_exit(void) {
	pr_info("Good bye world %d\n", num);
	return;
}


/* Register the init/exit callbacks with the kernel */
module_init(hello_mod_init);
module_exit(hello_mod_exit);

/* Metadata embedded in the .ko file, inspectable with `modinfo hello.ko`.
 * MODULE_LICENSE("GPL") is mandatory - a missing/unsuitable license makes
 * the kernel mark the module as TAINTED. */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Dinesh");
MODULE_DESCRIPTION("Hello world module");
