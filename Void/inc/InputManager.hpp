#pragma once
#include <iostream>
#include <unordered_map>
#include "Rect.hpp"
#include "SDL2/SDL.h"

#define LEFT_ARROW_KEY    SDLK_LEFT
#define RIGHT_ARROW_KEY   SDLK_RIGHT
#define UP_ARROW_KEY      SDLK_UP
#define DOWN_ARROW_KEY    SDLK_DOWN
#define A_KEY  			  SDLK_a
#define D_KEY   		  SDLK_d
#define W_KEY      		  SDLK_w
#define S_KEY    		  SDLK_s
#define ESCAPE_KEY 		  SDLK_ESCAPE
#define SPACE_KEY 		  SDLK_SPACE
#define LEFT_MOUSE_BUTTON SDL_BUTTON_LEFT

#ifdef DEBUG_MODE
	#define DEBUG_KEY SDLK_F8
#endif

using namespace Geometry;

const int N_MOUSE_BUTTONS = 5;

enum InputState
{
	RELEASED = 0, //liberado
	JUST_RELEASED, //já liberado
	PRESSED, //pressionado
	JUST_PRESSED //já pressionado
};

namespace GameEngine {
class InputManager
{	

	/* ATRIBUTOS */
	private:
		InputState mouseState[ N_MOUSE_BUTTONS ];
		std::unordered_map< int, InputState > keyState;
		bool quitGame; //sair do jogo?
        int mouseX, mouseY; //posicao do mouse
	/* FIM - ATRIBUTOS */

	/* CONSTRUTORES */
	public:
		/**
		 * Recupera instancia da classe InputManager
		 * @return Referencia para a classe
		 */
		static InputManager& GetInstance();
	private:
		InputManager();
		~InputManager();
	/* FIM - CONSTRUTORES */
		
	/* METODOS */
	public:
		/**
		 * Atualiza entradas de input
		 */
		void Update();
		
		/**
		 * Verifica se uma tecla está pressionada
		 * @param  key Codigo da tecla
		 * @return     true: está pressionada
		 *             false: caso contrário
		 */
		bool KeyPress( int key );

		/**
		 * Verifica se uma tecla foi liberada
		 * @param  key Codigo da tecla
		 * @return     true: se liberada
		 *             false: caso contrário
		 */
		bool KeyRelease( int key );

		/**
		 * Verifica se uma tecla foi pressionada
		 * @param  key Código da tecla
		 * @return     true: foi pressionada
		 *             false: caso contrário
		 */
		bool IsKeyDown( int key );

		/**
		 * Verifica se um botão está pressionada
		 * @param  button Codigo da botão
		 * @return   	  true: está pressionada
		 *            	  false: caso contrário
		 */
		bool MousePress( int button );

		/**
		 * Verifica se um botão foi liberada
		 * @param  button Codigo da botão
		 * @return     	  true: se liberada
		 *             	  false: caso contrário
		 */
		bool MouseRelease( int button );

		/**
		 * Verifica se um botão foi pressionada
		 * @param  button Código da botão
		 * @return    	  true: foi pressionada
		 *                false: caso contrário
		 */
		bool IsMouseDown( int button );

		/**
		 * Retorna posição X do mouse na tela
		 * @return Posição X do mouse em pixels
		 */
		int GetMouseX();

		/**
		 * Retorna posição Y do mouse na tela
		 * @return Posição Y do mouse em pixels
		 */
		int GetMouseY();

		/**
		 * Verifica se ponteiro do mouse está dentro de uma área determinada
		 * @param  rect Área a ser verificada
		 * @return      true: mouse está dentro de rect
		 *              false: caso contrário
		 */
		bool IsMouseInside( Rect rect );

		/**
		 * Retorna valor de quitGAme
		 * @return valor de quitGame
		 */
		bool ShouldQuit();
	/* fim - public */
	/* FIM - METODOS */
};
} // GameEngine
