#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "BlockTileSet.hpp"

using GameEngine::TileSet;

namespace GameEngine 
{
class TileMap
{
	/* ATRIBUTOS */
	private:
		int mapWidth;
		int mapHeight;
		int mapDepth;
		int mapTileWidth;
		int mapTileHeight;
		TileSet *tileSet;
		std::vector<int> tileMatrix;
		int parallaxSpeed = 1;
	
	/* CONSTRUTORES */
	public:
		TileMap( int mapWidth = 0, int mapHeight = 0, int layers = 0, TileSet* tileSet = NULL );
		TileMap(std::string &file, TileSet* tileSet = NULL );

	/* METODOS */
	public:
		/**
		 * Carrega tilemap a partir de um arquivo
		 * @param file Caminho para o arquivo de map
		 */
		void Load( std::string &file );

		/**
		 * Atualiza tileSet atual
		 * @param tileSet Novo tileSet
		 */
		void SetTileSet( TileSet *tileSet );

		/**
		 * Acessa elemento do vetor tileMatrix(x, y, z)
		 * @param  x Posicao X do elemento
		 * @param  y Posicao Y do elemento
		 * @param  z Posicao Z do elemento
		 * @return   Referencia para o elemento
		 */
		int& At( int x, int y, int z = 0 );

		/**
		 * Renderiza todas as camadas
		 * @param cameraX Posicao X da camera de renderizacao
		 * @param cameraY Posicao Y da camera de renderizacao
		 */
		void Render( int cameraX = 0, int cameraY = 0 );

		/**
		 * Renderiza camada especifica
		 * @param layer    Numero da camada a ser renderiazada
		 * @param cameraX  Posicao X da camada
		 * @param cameraY  Posicao Y da camada
		 * @param parallax 1 = ativo
		 *				   0 = desativado
		 */
		void RenderLayer(int layer, int cameraX = 0, int cameraY = 0, int parallax = 0);
	/* Get/Set */
	public:
		/**
		 * Resgata largura do mapa de tile
		 * @return Largura em unidades
		 */
		int GetWidth();

		/**
		 * Resgata altura do mapa de tiles
		 * @return Altura em unidades
		 */
		int GetHeight();

		/**
		 * Resgata profunidade do mapa de tiles
		 * @return Profundidade em unidades
		 */
		int GetDepth();
};
} // GameEngine
