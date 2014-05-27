#pragma once

#include <iostream>
#include <stack>
#include <memory>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"

#include "State.hpp"
#include "InputManager.hpp"

//JANELA
const std::string WIN_NAME = "Helio Junior - 10/0030688";// nome da tela do jogo
const int SCREEN_WIDTH = 1024;// largura da tela do jogo
const int SCREEN_HEIGHT = 600;// altura da tela do jogo
const int POS_X = 20;// posicao X da janela de jogo
const int POS_Y = 20;// posicao Y da janela do jogo

namespace GameEngine {
class Game
{
	/* ATRIBUTOS */
	private:
		int frameStart;
		float dt;
		static Game *instance; // instancia da classe
		State *storedState; 
		SDL_Renderer *renderer;  // instancia do renderizador de janela
		SDL_Window *window; // instancia da janela de jogo
		std::stack< std::unique_ptr<State> > stateStack;

	/* CONSTRUTOR */
    public:
		Game( std::string title = WIN_NAME, int width = SCREEN_WIDTH, int height = SCREEN_HEIGHT);
        ~Game();

	/* METODOS */
	public:
		/**
		 * Loop básico do jogo
		 */
		void Run();

		/**
		 * Retorna instancia da classe (Pattern: Single Ton)
		 * @return Referencia para o objeto da classe GameBase
		 */
		static Game& GetInstance();
		
		/**
		 * Retorna ponteiro para o render de tela
		 * @return [description]
		 */
		SDL_Renderer* GetRenderer();
		
		/**
		 * Resgata referencia para o estado de tela atual
		 * @return Referencia para o estado atual
		 */
		static State& GetCurrentState();
		void Push( State* state = NULL );

	private:
		/**
		 * Calcula deltaTime
		 */
		void CalculateDeltaTime();
	

};
} // GameEngine