# Readme for `libceu`

This is a small C/C++ library designed for the following purposes:

1. A correct, **portable**, well-documented C runtime library like [MUSL](https://musl.libc.org) or [uCLibC](https://uclibc.org);
2. String manipulation functions and basic data structures like [GLib](https://docs.gtk.org/glib/);
3. A build system that supports [CMake](https://cmake.org/) for modularized integration to other projects and [GNU Autotools](https://www.gnu.org/software/autoconf/) that allows execution over diverse machines.
4. Other tasks related to portability: Perform platform detection.
5. Other miscelanrous tasks: Inclusion of loggings, `malloc` wrappers, etc., from third-parties.
6. CMake modules for creation of portable software.

It is still under development. Do not use.

## Supported Operating Systems

- GNU/Linux. Tested on Debian GNU/Linux 11.
- BSD. Test on FreeBSD 14 (quarter).
- OpenSolaris. Tested on OpenIndiana (latest).
- Haiku (latest).
- Debian GNU/Hurd (latest).
- Microsoft Windows. Supports Windows 7 and above.

For Visual Studio Users:

Tested under MS Visual Studio 2019 (Windows 7) and 2022 (Windows 10/11). A Windows 10 SDK should be needed.

## Building libceu

## Integrating libceu to Your Program

## Future Targets

Further modularize CMake modules.

Add [GNU Autotools](https://www.gnu.org/software/autoconf/) and [pkg-config](https://www.freedesktop.org/wiki/Software/pkg-config/)/[pkgconf](http://pkgconf.org/) support to allow it run on ancient OS that does not have a CMake.

The `ceu_check` and the function `ceu_snprintf` is now a total mess. They're subjected to be revised.

yStr: Support NULL inside string.

## Historical Stuff

`libceu` were previously created for the development of `cpptetgs`, a C++ 11 program that designed to perform TE-gene fusion identification out of Long-Read RNA-Seq using split alignment and EM algorithm. After deprecation of `cpptetgs`, `libceu` was kept to provide a library for the development of other programs.
