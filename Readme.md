# Readme for `libceu`

This is a small C/C++ library designed for the following purposes:

1. A small portable C runtime library like MUSL or uCLibC;
2. String manipulation functions and data structures like GLib;
3. Other tasks related to portability: Perform platform detection.

It is still under development. Do not use.

## Supported Operating Systems

For Visual Studio Users:

Tested under MS Visual Studio 2019 (Windows 7) and 2022 (Windows 10). A Windows 10 SDK and Universal C Runtime (UCRT) should be needed.

## Building libceu

## Integrating libceu to Your Program

## Future Targets

Further modularize CMake modules.

Add [GNU Autotools](https://www.gnu.org/software/autoconf/) and [pkg-config](https://www.freedesktop.org/wiki/Software/pkg-config/)/[pkgconf](http://pkgconf.org/) support to allow it run on ancient OS that does not have a CMake.
