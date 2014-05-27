#include "TileSet.hpp"

namespace GameEngine {
/* CLASS TILESET*/
	/* CONSTRUTOR */
	TileSet::~TileSet()
	{
		
	}

	/* METODOS */
	/* Retorna largura do tile */
	int TileSet::GetTileWidth()
	{
		return this->tileWidth;
	}

	/* Retorna altura do tile */
	int TileSet::GetTileHeight()
	{
		return this->tileHeight;
	}
/* END - CLASS TILESET*/
} // GameEngine
