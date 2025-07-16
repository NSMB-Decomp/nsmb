#!/bin/bash

input_file=$(echo "$1" | sed 's|/build/src|/src|; s|\.o$|.cpp|')
wine "$PWD/build/compiler/mwccarm/2.0/sp1p5/mwccarm.exe" \
    $PWD/$input_file -o $PWD/$1 \
    -O4,p -interworking -proc arm946e -lang=C++ -Cpp_exceptions off \
    -w off -gccinc -nolink -c -RTTI off


# -O4,p -enum int -proc arm946e -gccext,on -fp soft -lang c99 
# -Cpp_exceptions off -gccinc -interworking -gccdep -MD -g 
# -inline on -str reuse -lang=c -char signed -sym on
#echo $output_path> a.txt

#wine "/home/umbreon/nsmb/build/compiler/mwccarm/2.0/base/mwccarm.exe" -O4,p \
#    -enum int -char signed -str noreuse -proc arm946e -gccext,on -fp soft -inline \
#      noauto -lang=C++ -Cpp_exceptions off -RTTI off -interworking -w off \
#      -sym on -gccinc -nolink -msgstyle gcc -D_NITRO -D_DEBUG -str reuse  \
#      -MD -c ./src/Base.cpp 
