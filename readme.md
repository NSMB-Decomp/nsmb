# Supported releases
|No-Intro Name|Release Code|Support
|-|-|-|
|[New Super Mario Bros. (Europe) (En,Fr,De,Es,It)](https://datomatic.no-intro.org/index.php?page=show_record&s=28&n=0479)|A2DP|N/A|
|[New Super Mario Bros. (USA, Australia)](5https://datomatic.no-intro.org/index.php?page=show_record&s=28&n=0434)|A2DE|In Progress|
|[New Super Mario Bros. (Japan)](https://datomatic.no-intro.org/index.php?page=show_record&s=28&n=0442)|A2DJ|N/A|
|[New Super Mario Bros. (Korea) ](https://datomatic.no-intro.org/index.php?page=show_record&s=28&n=0879)|A2DK|N/A|

# Setting up this repository
<!-- TODO: Made this section better -->
Set release region `export NSMB_RELEASE=A2DE`  
Extract your existing rom using `dsd rom extract -r $NSMB_RELEASE.nds -o extracted`  
Generate the config for this release using `dsd init -r extracted/config.yaml -o config/$NSMB_RELEASE/ -b build`  
Generate objdiff config `dsd objdiff --scratch -c config/$NSMB_RELEASE/arm9/config.yaml -m "wine /home/umbreon/nsmb/build/compiler/mwccarm/2.0/base/mwccarm.exe" -C mwcc_20_79 -f "-O4 -proc arm946e -lang=C++ -Cpp_exceptions off -w off -gccinc -nolink -c"`
`dsd delink -c config/$NSMB_RELEASE/arm9/config.yaml`  
Generate lcf info `dsd lcf -c config/$NSMB_RELEASE/arm9/config.yaml`  
Build a new rom using `dsd rom build -c extracted/config.yaml -o build/NSMB_USA.nds`  

## Importing nsmb.h into Ghidra
1. Open Ghidra
2. Open your nsmb project
3. Click **File** on the top left
4. Click **Parse C Source...**
5. Click the **Clear Profile** button on the top right
6. Click the Green Plus button under **Source files to parse**
7. Select the **nsmb.h** file.
8. At the bottom set **Program Architectre** to **ARM v5t little**
9. Click the **Save profile to new name** button on the top right
10. Name the profile anything you would like
11. Click the **Parse to Program** button on the bottom left
12. Click **Continue**
13. Click **Use Open Archives**

# Tools
[ds-decomp](https://github.com/AetiasHax/ds-decomp)  
[dsd-ghidra](https://github.com/AetiasHax/dsd-ghidra)  
[ghidra](https://github.com/NationalSecurityAgency/ghidra)  