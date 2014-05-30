#include "Main.hpp"

using namespace GameEngine;
using namespace States;

int main (int argc, char **argv)
{
    Game game;
	RealState *realState = new RealState();
	//TristeState *tristeState = new TristeState();
	
	game.GetInstance().Push(realState);
	game.GetInstance().Run();

	return 0;
}
