#include "ExceptionHandler.hpp"
#include "base_types.hpp"
#include "Nitro.hpp"


u32 func_02005b34() {

}

void ExceptionHandlerLoop() {
    u32 a = REG_IME << 0x20;
    REG_IME = 0;
    while (true) {
        a = func_02005b34();
    }
}