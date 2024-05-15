#!/usr/bin/env sh
export LD_LIBRARY_PATH=/home/yuzj/xenial-chroot/usr/lib/x86_64-linux-gnu/
export PATH=/home/yuzj/xenial-chroot/usr/bin:/home/yuzj/xenial-chroot/bin:/home/yuzj/xenial-chroot/sbin
/home/yuzj/xenial-chroot/usr/bin/gcc --sysroot /home/yuzj/xenial-chroot/ "${@}"
