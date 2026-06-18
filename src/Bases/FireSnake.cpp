#include "FireSnake.hpp"

FireSnake::FireSnake()
{
}

s32 FireSnake::onCreate()
{
}

void *FireSnake::create()
{
	return new FireSnake();
}
void *FireSnake::create_unused()
{
	return new FireSnake();
}
