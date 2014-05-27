#include "BlockTileSet.hpp"

namespace GameEngine {
/* CLASSE - BlockTileSet */
	/* CONSTRUTORES */
		BlockTileSet::BlockTileSet( int tileWidth, int tileHeight, std::string file )
			// : tileWidth( tileWidth ), tileHeight( tileHeight )
		{
			this->tileWidth = tileWidth;
			this->tileHeight = tileHeight;

            this->Open( file );
		}

	/* METODOS */
		void BlockTileSet::Open( std::string &file )
		{
			this->tileSet.Open( file );

			this->rows = this->tileSet.GetHeight() / this->tileHeight;
			this->columns = this->tileSet.GetWidth() / this->tileWidth;
		}

		void BlockTileSet::Render( unsigned index, int x, int y )
		{
			if ( ((int)index) < (this->rows * this->columns) )
			{
				int clipX = index % this->columns;
				int clipY = index / this->columns;

				// std::cout<<"X: " << x << ", Y: " << y << std::endl;
				// std::cout<<"Clip X: " << clipX << ", Y: " << clipY << std::endl;
				// std::cout<<"Tile X: " << tileWidth << ", Y: " << tileHeight << std::endl;
				this->tileSet.SetClip( clipX*tileWidth, clipY*tileHeight, tileWidth, tileHeight);

				this->tileSet.Render( x, y );
			}
			/*else{
				std::cout << "Indice invalido: " << (int)index << std::endl;
			}*/
		}
/* FIM - BlockTileSet */
} // GameEngine
