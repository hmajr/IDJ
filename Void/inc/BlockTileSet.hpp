#pragma once

#include <iostream>
#include "SDL.h"
#include "TileSet.hpp"
#include "Sprite.hpp"

namespace GameEngine {
class BlockTileSet : public TileSet
{
	/* ATRIBUTOS */
	private:
		int columns, rows; //tamanho do bloco de tile
		Sprite tileSet; //bloco de tile
		
	/* CONSTRUTORES */
	public:
		BlockTileSet( int tileWidth, int tileHeight, std::string file );

	/* METODOS */
	public:
		/**
		 * Abre arquivo de tileSet 
		 * @param file Caminho para o arquivo de tileSet
		 */
		void Open( std::string &file );

		/**
		 * Se indice válido, clipa tileSet e renderiza na tela
		 * @param index Indice da tileSet
		 * @param x     Posicao X na tela
		 * @param y     Posicao Y na tela
		 */
		void Render( unsigned index, int x, int y );
};
} // GameEngine
