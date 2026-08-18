# 01 - Hello World LKM

A minimal "Hello, world" Linux kernel module. The first step in learning
Linux device driver development.

## Files

| File       | Description                                        |
|------------|----------------------------------------------------|
| `hello.c`  | Module source: init/exit functions, metadata       |
| `Makefile` | kbuild wrapper that builds `hello.ko`              |

## Build

```sh
make
```

This produces `hello.ko` (a loadable kernel module) using the kbuild system
of the currently running kernel (`uname -r`).

Clean up generated files:

```sh
make clean
```

## Load and unload

```sh
sudo insmod ./hello.ko      # calls hello_mod_init(), prints "Hello world Dinesh"
sudo rmmod hello            # calls hello_mod_exit(), prints "Good bye world -100"
```

Kernel messages are not printed to the terminal. Check them with:

```sh
dmesg | tail -5
```

Inspect the module metadata:

```sh
modinfo hello.ko
```

## How it works

- Every module has two entry points registered with the kernel:
  - `module_init()`  -> called on `insmod`, must return `0` on success.
  - `module_exit()`  -> called on `rmmod`.
- `pr_info()` writes to the kernel log (visible via `dmesg`); there is no
  libc, so `printf()` does not exist in kernel space.
- `__init` / `__exit` markers let the kernel free the function code after it
  has run (for loadable modules, `__exit` has no effect).
- `MODULE_LICENSE("GPL")` is required; a wrong or missing license taints the
  kernel.