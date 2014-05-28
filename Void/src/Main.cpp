#include "Main.hpp"

using namespace GameEngine;
using States::RealState;

int main (int argc, char **argv)
{
    Game game;
    RealState *realState = new RealState();
	
    game.GetInstance().Push( realState );
	game.GetInstance().Run();

	return 0;
}
