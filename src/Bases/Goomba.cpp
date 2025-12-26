#include "Goomba.hpp"

Goomba::Goomba() {}

bool Goomba::onCreate() {

}

void *Goomba::operator new(u32 a)
{
    return new Goomba();
}