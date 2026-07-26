#pragma once
#include "../../src/base_types.hpp"

namespace NDS {
namespace Text {

int format(char* destination, const char* format, ...);
char* copyString(char* destination, const char* source);

}
}
