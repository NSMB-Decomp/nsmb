# Contibuting
> [!CAUTION]
> Do not use NitroSDK libraries when contributing to this project. If it is suspected you relied on the NitroSDK in a pull request it will be rejected.

> [!NOTE]
> To speed up compiling on linux run "wineserver -p" after each reboot, this will start a persistent wineserver so it does not need to start wine up every time you compile.

## Setting up this repository
1. Dump a copy of your DS game onto your computer, you can find guides for this on the internet
2. Rename the file to the release code in the table below, for example the USA rom will bnecome A2DE.nds and place it in the root of this repository
3. Download and install the latest version of [dsd](https://github.com/AetiasHax/ds-decomp)
4. Download and install the latest version of [zig](https://ziglang.org/)
5. If you're on Linux or macOS, download and install the latest version of [wine](https://gitlab.winehq.org/wine/wine/-/wikis/Download)
6. Somehow obtain a copy of mwccarm 1.2sp3 and place this under build/compiler/mwccarm/1.2/sp3/
7. Run `zig build extract`, this will extract all the files in the rom to the extracted/ directory
8. Run `zig build delink`, this will create delinked files which are used within objdiff
9. Run `zig build objdiff` this will generate a new objdiff configuration to allow comparing your code with the games code

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
