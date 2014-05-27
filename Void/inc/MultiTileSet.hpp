#ifndef MULTI_TILE_SET_HPP
#define MULTI_TILE_SET_HPP

#include "Sprite.hpp"
#include "TileSet.hpp"
#include <iostream>
#include <vector>

namespace GameEngine 
{
class MultiTileSet : public TileSet
{
	protected:
		std::vector< std::unique_ptr<GameEngine::Sprite> > tileArray;
	/* CONTRUTOR */
	public:
		MultiTileSet( int tileWidth, int tileHeight );
		~MultiTileSet();

	/* METODOS */
	public:
		void Open( std::string& file );
		void Render( unsigned index, int x = 0, int y = 0);
};
} // GameEngine

#endif // MULTI_TILE_SET_HPPd