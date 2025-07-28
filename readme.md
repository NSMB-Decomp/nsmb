> [!CAUTION]
> This project is currently in early stages and is unable to be compiled into a full rom at this time  
> If you would like to help develop this project read [contributing.md](contributing.md)

# Supported releases
<!--
✔️ Supported
➖ In Progress
❌ None
-->
| No-Intro Name                                                                                                                                        | Release Code | Support       | Build Date          |
| ---------------------------------------------------------------------------------------------------------------------------------------------------- | ------------ | ------------- | ------------------- |
| [0434 - New Super Mario Bros. (USA, Australia)](5https://datomatic.no-intro.org/index.php?page=show_record&s=28&n=0434)                              | A2DE         | ➖ In Progress | 2006-03-29 09:48:19 |
| [0442 - New Super Mario Bros. (Japan)](https://datomatic.no-intro.org/index.php?page=show_record&s=28&n=0442)                                        | A2DJ         | ❌ None        | 2006-04-04 19:07:45 |
| [z054 - New Super Mario Bros. (Japan) (Demo) (Kiosk, A85J)](https://datomatic.no-intro.org/index.php?page=show_record&s=28&n=z054)                   | A85J         | ❌ None        | 2006-04-07 11:17:21 |
| [x100 - New Super Mario Bros. (USA) (Demo) (Kiosk)](https://datomatic.no-intro.org/index.php?page=show_record&s=28&n=x100)                           | A85E         | ❌ None        | 2006-04-07 11:29:13 |
| [0479 - New Super Mario Bros. (Europe) (En,Fr,De,Es,It)](https://datomatic.no-intro.org/index.php?page=show_record&s=28&n=0479)                      | A2DP         | ❌ None        | 2006-04-26 14:20:08 |
| [x168 - New Super Mario Bros. (Europe) (En,Fr,De,Es,It) (Demo) (Kiosk, Y78P)](https://datomatic.no-intro.org/index.php?page=show_record&s=28&n=x168) | A85P         | ❌ None        | 2006-04-27 11:13:34 |
| [x039 - New Super Mario Bros. (Europe) (En,Fr,De,Es,It) (Demo) (Kiosk)](https://datomatic.no-intro.org/index.php?page=show_record&s=28&n=x039)       | A85P         | ❌ None        | 2006-04-27 11:13:34 |
| [0879 - New Super Mario Bros. (Korea) ](https://datomatic.no-intro.org/index.php?page=show_record&s=28&n=0879)                                       | A2DK         | ❌ None        | 2006-12-27 14:32:43 |
| [x142 - New Chaoji Maliou Xiongdi (China) (iDS)](https://datomatic.no-intro.org/index.php?page=show_record&s=28&n=x142)                              | A2DC         | ❌ None        | 2009-04-27 20:29:28 |
| [z393 - New Super Mario Bros. (Japan) (Demo) (Kiosk, Y7QJ)](https://datomatic.no-intro.org/index.php?page=show_record&s=28&n=z393)                   | Y7QJ         | ❌ None        | 2009-10-23 16:23:25 |

<!--
These Wii U Virtual console releases seem to be idential to the builds above, however they have some extra data in the range 0x1000-0x3FFF.
| [z434 - New Super Mario Bros. (Japan) (Wii U Virtual Console)](https://datomatic.no-intro.org/index.php?page=show_record&s=28&n=z434)                   | WUP-N-DADJ   | ❌ None        | 2006-04-04 19:07:45 |
| [z435 - New Super Mario Bros. (USA) (Wii U Virtual Console)](https://datomatic.no-intro.org/index.php?page=show_record&s=28&n=z435)                     | WUP-N-DADE   | ❌ None        | 2006-03-29 09:48:19 |
| [z436 - New Super Mario Bros. (Europe) (En,Fr,De,Es,It) (Wii U Virtual Console)](https://datomatic.no-intro.org/index.php?page=show_record&s=28&n=z436) | WUP-N-DADP   | ❌ None        | 2006-04-26 14:20:08 |
-->

# Tools
* [ds-decomp](https://github.com/AetiasHax/ds-decomp) - Main tool this project uses, extracts the games, manages regions and symbols
* [dsd-ghidra](https://github.com/AetiasHax/dsd-ghidra) - Used for importing ds-decomp config into Ghidra
* [ghidra](https://github.com/NationalSecurityAgency/ghidra) - Used for disassembling the game
* [zig](https://ziglang.org/) - Used as the build system