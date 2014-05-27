#include "TileMap.hpp"

namespace GameEngine {
/* CLASSE TILEMAP */
	/* CONSTRUTORES */
		/**
		 * Inicializa variaves, redimensiona tileMatrix para o novo tamanho e zera valores
		 */
		TileMap::TileMap( int mapWidth, int mapHeight, int layers, TileSet *tileSet )
		 : mapWidth( mapWidth ), mapHeight( mapHeight ), mapDepth( layers ), tileSet( tileSet )
		{
			// redimensiona tileMatrix
			this->tileMatrix.resize( mapWidth * mapHeight * mapDepth );
			
			// Inicializa tileMatrix
			for(int k = 0; k < mapDepth; ++k) { //profunidade
				for(int j = 0; j < mapHeight; ++j) { //Linha
					for(int i = 0; i < mapWidth; ++i) { //Coluna
						this->At( i, j, k ) = -1;
					}
				}
			}
		}

		TileMap::TileMap( std::string &file, TileSet *tileSet )
			: tileSet( tileSet )
		{

			this->Load( file );
		}

	/* METODOS */
		void TileMap::Load( std::string &file )
		{
			//abre arquivo
			std::ifstream mapFile( file, std::ios_base::in );
			// std::
			int intDump;
			char dump;
			int tempLarg, tempAlt, tempProf;
			//se falhou, 
			if( !mapFile ) {
				//	exibe erro
				std::cout << "File cannot be open! " << std::endl;
			}
			else
			{

				mapFile >> this->mapWidth;
				mapFile >> dump; //lixo
								
				mapFile >> this->mapHeight;
				mapFile >> dump; //lixo

				mapFile >> this->mapDepth;
				mapFile >> dump; //lixo

				mapFile >> this->mapTileWidth;
				mapFile >> dump; //lixo

				mapFile >> this->mapTileHeight;
				mapFile >> dump; //lixo

				// redimensiona tileMatrix
				this->tileMatrix.resize( mapWidth * mapHeight * mapDepth );
				
				// Inicializa tileMatrix
				for(int k = 0; k < mapDepth; ++k) { //profunidade
					for(int j = 0; j < mapHeight; ++j) { //Linha
						for(int i = 0; i < mapWidth; ++i) { //Coluna
							this->At( i, j, k ) = -1;
						}
					}
				}

				#ifdef DEBUG_MODE
					std::cout << "============= ( TileMap ) ===============" << std::endl;
					std::cout << "+ MAP WIDHT:  " << this->mapWidth << std::endl;
					std::cout << "+ MAP HEIGHT: " << this->mapHeight << std::endl;
					std::cout << "+ MAP DEPHT:  " << this->mapDepth << std::endl;
					std::cout << "+ TIL WIDTH:  " << this->mapTileWidth << std::endl;
					std::cout << "+ TIL HEIGHT: " << this->mapTileHeight << std::endl;
					std::cout << "=========================================" << std::endl;
				#endif 

				//  enquanto !(fim do arquivo) - DEPTH
				for( tempProf = 0; tempProf < this->mapDepth; ++tempProf )
				{
					//enquanto tempAlt < tileH - LINE
					for(tempAlt = 0; tempAlt < this->mapHeight; ++tempAlt ) 
					{
						//enquanto tempLar < tileH - COLUNM
						for( tempLarg = 0; tempLarg < this->mapWidth; ++tempLarg ) {
							//le int
							mapFile >> intDump;

							this->At( tempLarg, tempAlt, tempProf) += intDump;
							//descarta char
							mapFile >> dump; //lixo
						}
					}
				}

				mapFile.close();
			}
		}

		/**
		 * Atualiza tileSet atual
		 */
		void TileMap::SetTileSet( TileSet *tileSet )
		{
			/* verificar */
			delete this->tileSet;

			this->tileSet = tileSet;
		}

		/**
		 * Acessa elemento do vetor tileMatrix(x, y, z)
		 */
		int& TileMap::At( int x, int y, int z )
		{
			return this->tileMatrix[ ((y*( this->mapWidth ) + x) + z*( this->mapWidth )*( this->mapHeight )) ];
		}

		/**
		 * Renderiza todas as camadas do mapa
		 * Renderiza todo o mapa, tile a tile. Note que há dois ajustes a se
		 */
		void TileMap::Render( int cameraX, int cameraY )
		{
			// Inicializa tileMatrix
			for(int k = 0; k < mapDepth; ++k) { //profunidade
				this->RenderLayer( k, cameraX, cameraY );
			}
		}

		/**
		 * Renderiza camada especifica do mapa
		 * Faz o mesmo que Render, mas para uma layer só.
		 */
		void TileMap::RenderLayer( int layer, int cameraX, int cameraY )
		{
			for(int j = 0; j < mapHeight; ++j) { //Linha
				for(int i = 0; i < mapWidth; ++i) { //Coluna
					this->tileSet->Render( this->At( i, j, layer ), //valor referencia para tileArray
										   ( i*(this->tileSet->GetTileWidth()) + (cameraX*parallaxSpeed*(layer*2+1)) ), //pos X p/ renderizar
										   ( j*(this->tileSet->GetTileHeight()) + (cameraY*parallaxSpeed*(layer*2+1)) ) ); //pos Y p/ renderizar

				}
			}

		}

		// /**
		//  * ZOOM
		//  */
		// void TileMap::RenderLayer( int layer, int cameraX, int cameraY )
		// {
		// 	for(int j = 0; j < mapHeight; ++j) { //Linha
		// 		for(int i = 0; i < mapWidth; ++i) { //Coluna

		// 			this->tileSet->Render( this->At( i, j, layer ), //valor referencia para tileArray
		// 								   ( i*(this->tileSet->GetTileWidth()) + (cameraY*parallaxSpeed*i) ), //pos X p/ renderizar
		// 								   ( j*(this->tileSet->GetTileHeight()) + (cameraY*parallaxSpeed*j) ) ); //pos Y p/ renderizar
		// 		}
		// 	}

		// }
	/* Get/Set */
		/**
		 * Resgata largura do mapa de tile
		 */
		int TileMap::GetWidth()
		{
			return this->mapWidth;
		}

		/**
		 * Resgata altura do mapa de tiles
		 */
		int TileMap::GetHeight()
		{
			return this->mapHeight;
		}

		/**
		 * Resgata profunidade do mapa de tiles
		 */
		int TileMap::GetDepth()
		{
			return this->mapDepth;
		}
/* END - CLASSE TILEMAP */
} // GameEngine
