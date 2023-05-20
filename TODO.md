# TODOs

Failed with Embarcadero Tokyo C++ with following message:

```text
D:/Work/cpptetgs_experimental/dist/libceu/cmake-build-broadland $ rm * -rf
D:/Work/cpptetgs_experimental/dist/libceu/cmake-build-broadland $ PATH="D:/Software/BCC102/bin;${PATH}" cmake .. -DCMAKE_C_COMPILER="bcc32c.exe" -DCMAKE_CXX_COMPILER="bcc32x.exe"  -G"Borland Makefiles"
-- The C compiler identification is Embarcadero 7.30.36015
-- The CXX compiler identification is Embarcadero 7.30.36015
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: D:/Software/BCC102/bin/bcc32c.exe - skipped
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - failed
-- Check for working CXX compiler: D:/Software/BCC102/bin/bcc32x.exe
-- Check for working CXX compiler: D:/Software/BCC102/bin/bcc32x.exe - broken
CMake Error at D:/Software/Scoop/apps/cmake/3.22.2/share/cmake-3.22/Modules/CMakeTestCXXCompiler.cmake:62 (message):
  The C++ compiler

    "D:/Software/BCC102/bin/bcc32x.exe"

  is not able to compile a simple test program.

  It fails with the following output:

    Change Dir: D:/Work/cpptetgs_experimental/dist/libceu/cmake-build-broadland/CMakeFiles/CMakeTmp

    Run Build Command(s):make -f Makefile cmTC_0938a\fast && MAKE Version 5.41  Copyright (c) 1987, 2014 Embarcadero Technologies, Inc.
        make  -f CMakeFiles\cmTC_0938a.dir\build.make -l -o  CMakeFiles\cmTC_0938a.dir\build
    MAKE Version 5.41  Copyright (c) 1987, 2014 Embarcadero Technologies, Inc.
    Building CXX object CMakeFiles/cmTC_0938a.dir/testCXXCompiler.cxx.obj
        D:\Software\BCC102\bin\bcc32x.exe -tR -DWIN32   -tM -Od -v -oCMakeFiles\cmTC_0938a.dir\testCXXCompiler.cxx.obj -P -c D:\Work\cpptetgs_experimental\dist\libceu\cmake-build-broadland\CMakeFiles\CMakeTmp\testCXXCompiler.cxx
    Embarcadero C++ 7.30 for Win32 Copyright (c) 2012-2017 Embarcadero Technologies, Inc.
    Embarcadero Technologies Inc. bcc32x version 3.3.1 (36350.30c6854.779bede) (based on LLVM 3.3.1)
    Target: i686-pc-win32-omf
    Thread model: posix
    D:\Work\cpptetgs_experimental\dist\libceu\cmake-build-broadland\CMakeFiles\CMakeTmp\testCXXCompiler.cxx:
     "D:/Software/BCC102/bin/bcc32x.exe" -cc1 -triple i686-pc-win32-omf -emit-obj -disable-llvm-verifier -tR -tM -main-file-name testCXXCompiler.cxx -mrelocation-model static -fmath-errno -masm-verbose -v -P -ffunction-sections -nobuiltininc -isystem "D:\\Software\\BCC102\\bin\\..\\include" -isystem "D:\\Software\\BCC102\\bin\\..\\include\\dinkumware64" -isystem "D:\\Software\\BCC102\\bin\\..\\include\\windows\\crtl" -isystem "D:\\Software\\BCC102\\bin\\..\\include\\windows\\sdk" -isystem "D:\\Software\\BCC102\\bin\\..\\include\\windows" -D WIN32 -Od -std=c++11 -fdeprecated-macro -fdebug-compilation-dir D:/Work/cpptetgs_experimental/dist/libceu/cmake-build-broadland -ferror-limit 19 -fmessage-length 0 -fno-threadsafe-statics -fno-use-cxa-atexit -fborland-extensions -fobjc-runtime=gcc -std=c++11 -fcxx-exceptions -fexceptions -fseh -fdiagnostics-show-option -fno-spell-checking -backend-option -vectorize-loops -cxx-abi borland -o "CMakeFiles\\cmTC_0938a.dir\\testCXXCompiler.cxx.obj" -x c++ "D:\\Work\\cpptetgs_experimental\\dist\\libceu\\cmake-build-broadland\\CMakeFiles\\CMakeTmp\\testCXXCompiler.cxx"
    error: invalid integral value 'd' in '-Od'
    error: invalid integral value 'd' in '-Od'

    ** error 1 ** deleting CMakeFiles\cmTC_0938a.dir\testCXXCompiler.cxx.obj

    ** error 1 ** deleting cmTC_0938a\fast
    




  CMake will not be able to correctly generate this project.
Call Stack (most recent call first):
  CMakeLists.txt:2 (project)


-- Configuring incomplete, errors occurred!
See also "D:/Work/cpptetgs_experimental/dist/libceu/cmake-build-broadland/CMakeFiles/CMakeOutput.log".
See also "D:/Work/cpptetgs_experimental/dist/libceu/cmake-build-broadland/CMakeFiles/CMakeError.log".
```