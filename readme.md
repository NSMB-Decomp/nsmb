# Setting up this repository
1. Dump a copy of your DS game onto your computer, you can find guides for this on the internet
2. Rename the file to the release code in the table below, for example the USA rom will bnecome A2DE.nds and place it in the root of this repository
3. Download and install the latest copy of [dsd](https://github.com/AetiasHax/ds-decomp), this tool is used for  
4. Download and install the latest copy of [zig](https://ziglang.org/)
5. Somehow obtain a copy of mwccarm 1.2sp3 and place this under build/compiler/mwccarm/1.2/sp3/
6. Run `zig build extract`, this will extract all the files within the rom to the extracted/ directory
7. Run `zig build delink`, this will create delinked files which are used within objdiff
8. Run `zig build objdiff` this will generate a new objdiff configuration to allow comparing your code with the games code

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

# Supported releases
| No-Intro Name                                                                                                                                           | Release Code | Support        | Build Date          |
| ------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------ | -------------- | ------------------- |
| [0434 - New Super Mario Bros. (USA, Australia)](5https://datomatic.no-intro.org/index.php?page=show_record&s=28&n=0434)                                 | A2DE         | ✔️ In Progress | 2006-03-29 09:48:19 |
| [0442 - New Super Mario Bros. (Japan)](https://datomatic.no-intro.org/index.php?page=show_record&s=28&n=0442)                                           | A2DJ         | ❌ None        | 2006-04-04 19:07:45 |
| [z054 - New Super Mario Bros. (Japan) (Demo) (Kiosk, A85J)](https://datomatic.no-intro.org/index.php?page=show_record&s=28&n=z054)                      | A85J         | ❌ None        | 2006-04-07 11:17:21 |
| [x100 - New Super Mario Bros. (USA) (Demo) (Kiosk)](https://datomatic.no-intro.org/index.php?page=show_record&s=28&n=x100)                              | A85E         | ❌ None        | 2006-04-07 11:29:13 |
| [0479 - New Super Mario Bros. (Europe) (En,Fr,De,Es,It)](https://datomatic.no-intro.org/index.php?page=show_record&s=28&n=0479)                         | A2DP         | ❌ None        | 2006-04-26 14:20:08 |
| [x168 - New Super Mario Bros. (Europe) (En,Fr,De,Es,It) (Demo) (Kiosk, Y78P)](https://datomatic.no-intro.org/index.php?page=show_record&s=28&n=x168)    | A85P         | ❌ None        | 2006-04-27 11:13:34 |
| [x039 - New Super Mario Bros. (Europe) (En,Fr,De,Es,It) (Demo) (Kiosk)](https://datomatic.no-intro.org/index.php?page=show_record&s=28&n=x039)          | A85P         | ❌ None        | 2006-04-27 11:13:34 |
| [0879 - New Super Mario Bros. (Korea) ](https://datomatic.no-intro.org/index.php?page=show_record&s=28&n=0879)                                          | A2DK         | ❌ None        | 2006-12-27 14:32:43 |
| [x142 - New Chaoji Maliou Xiongdi (China) (iDS)](https://datomatic.no-intro.org/index.php?page=show_record&s=28&n=x142)                                 | A2DC         | ❌ None        | 2009-04-27 20:29:28 |
| [z393 - New Super Mario Bros. (Japan) (Demo) (Kiosk, Y7QJ)](https://datomatic.no-intro.org/index.php?page=show_record&s=28&n=z393)                      | Y7QJ         | ❌ None        | 2009-10-23 16:23:25 |
| [z434 - New Super Mario Bros. (Japan) (Wii U Virtual Console)](https://datomatic.no-intro.org/index.php?page=show_record&s=28&n=z434)                   | WUP-N-DADJ   | ❌ None        |
| [z435 - New Super Mario Bros. (USA) (Wii U Virtual Console)](https://datomatic.no-intro.org/index.php?page=show_record&s=28&n=z435)                     | WUP-N-DADE   | ❌ None        |
| [z436 - New Super Mario Bros. (Europe) (En,Fr,De,Es,It) (Wii U Virtual Console)](https://datomatic.no-intro.org/index.php?page=show_record&s=28&n=z436) | WUP-N-DADP   | ❌ None        |

# Tools
[ds-decomp](https://github.com/AetiasHax/ds-decomp)  
[dsd-ghidra](https://github.com/AetiasHax/dsd-ghidra)  
[ghidra](https://github.com/NationalSecurityAgency/ghidra)  
[zig](https://ziglang.org/)