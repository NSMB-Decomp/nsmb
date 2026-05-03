#include "FireSnake.hpp"

FireSnake::FireSnake()
{
}

bool FireSnake::onCreate()
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
