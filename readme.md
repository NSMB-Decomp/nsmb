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