#include "MultiTileSet.hpp"

namespace GameEngine {
/* Classe MultiTileSet*/
	/* CONSTRUTOR*/
	MultiTileSet::MultiTileSet( int tileWidth, int tileHeight )
	{
		this->tileWidth = tileWidth;
		this->tileHeight = tileHeight;
	}

	MultiTileSet::~MultiTileSet()
	{
		tileArray.clear();
	}

	/* METODOS */
	/*Abre sprite e insere no array de sprites: tileArray*/
	void MultiTileSet::Open( std::string &file )
	{
		this->tileArray.emplace_back( (new GameEngine::Sprite( file )) );

	}

	void MultiTileSet::Render( unsigned index, int x, int y )
	{
		if( index < this->tileArray.size() ){
			this->tileArray[ index ]->Render( x, y);
		}
	}
/* FIM - MultiTileSet*/
} // GameEngine
