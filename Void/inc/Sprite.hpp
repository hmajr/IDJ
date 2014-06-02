#pragma once
#include <iostream>
#include <vector>
#include <unordered_map> //tabela hash
#include "Point.hpp"
#include "SDL.h"
#include "SDL_image.h"
#include "Game.hpp"
#include "Resource.hpp"

using namespace Geometry;


namespace GameEngine {
class Sprite
{
	typedef std::unordered_map<std::string, SDL_Texture*> UnorderedSprite;

	/* ATRIUTOS */
	public:					//chave   , Objeto apontado
		static UnorderedSprite assetTable;
	private:
		SDL_Texture *texture; // imagem
		SDL_Rect dimensions; // dimensoes da imagem
		SDL_Rect clipRect; // recorte da imagem a ser renderizada
        float scaleX = 1.0f, scaleY = 1.0f; //escala do sprite
        /* GERECIANMENTO */
        Resource resource;
        /* VARIAVEIS DE ANIMACAO */
        int frameCount = 1; //numero de frame
        int currentFrame = 0; //numero do frame atual
        float timeElapsed; //tempo transcorrido desde ultimo frame
        float frameTime; //segundos por frame
        int numFramesLine; // numero de frames por linha
		int numFramesColunm; //numero de frames por coluna


		
	/* CONSTRUTORES */
	public:
		/**
		 * Set texture para NULL (no image)
		 */
		Sprite();

		/**
		 * Carrega textura do arquivo
		 * @param file Caminho da imagem
		 */
		Sprite(std::string& file, int numFramesColunm = 1, int numFramesLine = 1, float frameTime = 1.0f);

		/**
		 * Desaloca textura
		 */
		~Sprite();

	/* METODOS */
	public:
		/**
		 * Carrega imagem
		 * @param file Caminho da imagem a ser carregada
		 */
		void Open( std::string& file );

		/**
		 * Set retangulo de recorte da imagem a ser renderizada
		 * @param x Posicao X do ponto superior esquerdo do retangulo
		 * @param y Posicao Y do ponto superior esquerdo do retangulo
		 * @param w Largura do retangulo de recorte
		 * @param h Altura do retangulo de recorte
		 */
		void SetClip( int x, int y, int w, int h );

		/**
		 * Atualiza sprite
		 * @param Update Delta time
		 */
		void Update ( float dt );
		
		/**
		 * Renderiza texture na tela de jogo
		 * @param x 	Posicao X do ponto supoerior esquerdo da textura a ser renderizada
		 * @param y 	Posicao Y do ponto supoerior esquerdo da textura a ser renderizada
		 * @param angle Angulo de rotacao (rad)
		 * @param flip  Sprite esta espelhado
		 */
		void Render( int x = 0, int y = 0, float angle = 0, bool flip = false);


		/* GET/SET */

		/**
		 * Seta frame de spritesheet
		 * @param frame Indice do frame
		 */
		void SetFrame(int frame = 0);
		/**
		 * Seta contador de frames
		 * @param frameCount [description]
		 */
		void SetFrameCount(int frameCount = 0);
		/**
		 * Seta velocidade da animacao
		 * @param frameTime Tempo em (frame/seg)
		 */
		void SetFrameTime( float frameTime = 0);
		
		/**
		 * Get largura da imagem
		 * @return Retorna largura da imagem
		 */
		int GetWidth(); 
		
		/**
		 * Get altura da imagem
		 * @return Retorna altura da imagem
		 */
		int GetHeight();
		
		/**
		 * Resgata altura do frame atual
		 * @return Altura do frame (pixels)
		 */
		int GetFrameHeight();

		/**
		 * Get largura do frame atual
		 * @return Largura do frame (pixel)
		 */
		int GetFrameWidth();

		/**
		 * Verifica se já existe textura alocada
		 * @return true Existe textura alocada
		 *              false Caso contrario
		 */
		bool IsOpen(); // retorna se existe textura carregada

		/**
		 * Altera escala em X
		 * @param scale Proporcao do sprite no eixo X
		 */
		void SetScaleX( float scale = 1.0f )
		{
			this->scaleX = scale;
		}

		/**
		 * Altera escala em Y
		 * @param scale Proporcao do sprite no eixo Y
		 */
		void SetScaleY( float scale = 1.0f )
		{
			this->scaleY = scale;
		}
		
		/**
		 * Limpa tablea de hash
		 */
		static void Clear();
	/* FIM - public*/

};
} // GameEngine
