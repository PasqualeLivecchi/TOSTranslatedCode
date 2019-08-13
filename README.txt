This contains examples of some of my initial work to get HolyC code to run on Linux.

The code should compile with only warnings using g++ (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0

The Examples and Translated* folders contain pairs of ASM/HolyC code and translated pseudo C/C++ code which g++ will barely accept :-)

All .c files should compile with:
g++ -c -fpermissive

Examples from TOS:
g++ -c -fpermissive TranslatedASM/KUtils.HC.cpp
g++ -c -fpermissive TranslatedHolyC/Compress.HC.cpp

Simple Example App:
g++ -fpermissive Examples/FizzBuzz.HC.c

Translating HolyC to C/C++ is a huge task.  To help I tried to make a big header file which defines some common assumed available Temple OS functions in HeadersAndWrappers/TOSFunctionsAll.h.  This will allow you to test compile code which uses functions which have not yet been translated using the -c to see if you can make a .o or not.  If you can generate a .o hopefully your code will be able to be linked and run once all missing functions have been translated.

HeadersAndWrappers/TOSKernelStuff.h contains stuff scraped and VERY CRUDELY translated from Kernal*.HH from Temple OS and a few other headers.

Both HeadersAndWrappers/TOSFunctionsAll.h and HeadersAndWrappers/TOSKernelStuff.h are in very rough shape and are not complete by any means!  Some functions may be flat out wrongly converted.

Most HolyC files will not simply compile by adding my crudely hacked up headers, they will likely need lots of tweaking!  Terry used some things not valid in C/C++ like variables named const (which I guess makes sense for a spring constant).  Many functions are defined differently in multiple HH/HC files (which is ok in Temple OS because the new one just shadows the old).  These and others are missing form HeadersAndWrappers/TOSFunctionsAll.h.  Also many functions are called without () and these are only known to be functions because HolyC knows the currently available symbols.  Also you'll have to convert the many ways of printing strings.  The list is huge, I'll try to create more wrappers for TOS functions eventually.

