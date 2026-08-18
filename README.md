# Linux Device Driver Practice

Learning embedded Linux device driver development from scratch, one small
module at a time. Each directory is a self-contained exercise with source,
Makefile, and README.

## Exercises

| Directory              | Topic                                   |
|------------------------|-----------------------------------------|
| `01-hello-world-lkm/`  | Minimal "Hello, world" kernel module    |

## Getting started

Each exercise builds against the running kernel:

```sh
cd 01-hello-world-lkm
make          # builds <name>.ko
make clean    # removes generated files
```

Load/unload a module with `insmod`/`rmmod` (as root) and read its output
with `dmesg`. `modinfo <name>.ko` shows the module metadata.

## Prerequisites

- Linux kernel headers for your running kernel (`linux-headers-$(uname -r)`)
- `make` and a matching toolchain (`gcc`)