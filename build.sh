#!/bin/bash

wine "/home/umbreon/nsmb/build/compiler/mwccarm/2.0/base/mwccarm.exe" -O4 -interworking -proc arm946e -lang=C++ -Cpp_exceptions off -w off -gccinc -nolink -c ./src/Base.cpp -o $PWD/$1

#wine "/home/umbreon/nsmb/build/compiler/mwccarm/2.0/base/mwccarm.exe" -O4,p \
#    -enum int -char signed -str noreuse -proc arm946e -gccext,on -fp soft -inline \
#      noauto -lang=C++ -Cpp_exceptions off -RTTI off -interworking -w off \
#      -sym on -gccinc -nolink -msgstyle gcc -D_NITRO -D_DEBUG -str reuse  \
#      -MD -c ./src/Base.cpp 
