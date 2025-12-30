#include "Goomba.hpp"

Goomba::Goomba() {}

bool Goomba::onCreate() {

}

void *Goomba::create()
{
    return new Goomba();
}