#pragma once

#include <iostream>

namespace GameEngine {
class TileSet {
	/* ATRIBUTOS */
	protected:
		int tileWidth;
		int tileHeight;

	/* CONSTUTOR */
	public:
		virtual ~TileSet();

	/* METODOS */
	public:
		virtual void Open( std::string& file ) = 0;
		virtual void Render( unsigned index, int x, int y ) = 0;
		int GetTileWidth();
		int GetTileHeight();
	/* FIM - public*/
}; // TileSet
} // GameEngine
