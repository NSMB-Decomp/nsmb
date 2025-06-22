# Commands
Extract your existing rom using `dsd rom extract -r rom.nds -o extracted`  
Generate objdiff config `dsd objdiff --scratch -c arm9/config.yaml -C mwcc_20_79 -p 148`  
`dsd delink -c arm9/config.yaml`
Generate lcf info `dsd lcf -c arm9/config.yaml`  
Build a new rom using `dsd rom build -c extracted/config.yaml -o build/NSMB_USA.nds`  

# Supported releases
|No-Intro Name|Release Code|
|-|-|
|[New Super Mario Bros. (USA, Australia)](https://datomatic.no-intro.org/index.php?page=show_record&s=28&n=0434)|A2DE|

# Tools
[ds-decomp](https://github.com/AetiasHax/ds-decomp)  
[dsd-ghidra](https://github.com/AetiasHax/dsd-ghidra)  
[ghidra](https://github.com/NationalSecurityAgency/ghidra)  

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