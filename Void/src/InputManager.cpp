#include "InputManager.hpp"

namespace GameEngine {
/* CLASS - InputManager*/
	/* CONSTRUTORES */
		/**
		 * Recupera instancia da classe InputManager
		 */
		InputManager& InputManager::GetInstance()
		{
			static InputManager input;

			return input;
		}

		InputManager::InputManager()
		{
			for (int count = 0; count < N_MOUSE_BUTTONS; ++count){
				this->mouseState[ count ] = RELEASED;
			}
		}

		InputManager::~InputManager()
		{

		}
	/* FIM - CONSTRUTORES */
	/* METODOS */
		/**
		 * Atualiza entradas de input
		 */
		void InputManager::Update()
		{
			SDL_Event event;

			SDL_GetMouseState( &mouseX, &mouseY );
			this->quitGame = false;

			// Atualiza estado das teclas do frame passado
			for ( auto count = keyState.begin(); count != keyState.end(); ++count ){
				int tempKey = count->first;

				if( InputState::JUST_PRESSED == keyState[ tempKey ] ){
					keyState[ tempKey ] = PRESSED;
				}
				else if( InputState::JUST_RELEASED == keyState[ tempKey ] ){
					keyState[ tempKey ] = RELEASED;
				}
			}

			//Atualiza estado do mouse do frame passado
			for ( int count = 0; count < N_MOUSE_BUTTONS; ++count )
			{
				if ( mouseState[ count ] == InputState::JUST_PRESSED ){
					mouseState[ count ] = InputState::PRESSED;
				}
				else if( mouseState[ count ] == InputState::JUST_RELEASED ){
					mouseState[ count ] = InputState::RELEASED;
				}
			}
			
			while( SDL_PollEvent( &event ) )
			{
				switch( event.type )
				{
					/* Analisar possivel bug com relacao aos keycode*/
					case SDL_KEYDOWN:
					{
						SDL_Keycode keycode = static_cast<int>(event.key.keysym.sym);
						
						if ( InputState::RELEASED == keyState[ keycode ] ){
							keyState[ keycode ] = InputState::JUST_PRESSED;
						}
						// if( InputState::JUST_PRESSED == keyState[ keycode ] ){
						// }

						break;
					}
					case SDL_KEYUP:
					{
						SDL_Keycode keycode = static_cast<int>(event.key.keysym.sym);

						if ( InputState::PRESSED == keyState[ keycode ] ){
							keyState[ keycode ] = InputState::JUST_RELEASED;
						}
						break;
					}
					case SDL_MOUSEBUTTONDOWN:
					{
						this->mouseState[ event.button.button ] = InputState::JUST_PRESSED;
						break;
					}
					case SDL_MOUSEBUTTONUP:
					{
							this->mouseState[ event.button.button ] = InputState::JUST_RELEASED;
						break;
					}
					case SDL_QUIT:
					{
						this->quitGame = true;
						break;
					}
				}
			}
		}
		
		/**
		 * Verifica se uma tecla está pressionada
		 */
		bool InputManager::KeyPress( int key )
		{
			std::unordered_map< int, InputState >::const_iterator found = this->keyState.find ( key );
			return (  found != keyState.end() && 
					  found->second == InputState::JUST_PRESSED )? true : false;
		}

		/**
		 * Verifica se uma tecla foi liberada
		 */
		bool InputManager::KeyRelease( int key )
		{
			std::unordered_map< int, InputState >::const_iterator found = this->keyState.find ( key );
			return ( found != keyState.end()  && 
					 found->second == InputState::JUST_RELEASED )? true : false;
		}

		/**
		 * Verifica se uma tecla foi pressionada
		 */
		bool InputManager::IsKeyDown( int key )
		{
			std::unordered_map< int, InputState >::const_iterator found = this->keyState.find ( key );
			return ( found != keyState.end() &&
			 		 found->second == InputState::PRESSED )? true : false;;

		}

		/**
		 * Verifica se um botão está pressionada
		 */
		bool InputManager::MousePress( int button )
		{
			return ( InputState::JUST_PRESSED == mouseState[ button ])? true : false;
		}

		/**
		 * Verifica se um botão foi liberada
		 */
		bool InputManager::MouseRelease( int button )
		{
			return ( InputState::JUST_RELEASED == mouseState[ button ] )? true : false;

		}

		/**
		 * Verifica se um botão foi pressionada
		 */
		bool InputManager::IsMouseDown( int button )
		{
			return ( InputState::PRESSED == mouseState[ button ] )? true : false;
		}

		/**
		 * Retorna posição X do mouse na tela
		 */
		int InputManager::GetMouseX()
		{
			return mouseX;
		}

		/**
		 * Retorna posição Y do mouse na tela
		 */
		int InputManager::GetMouseY()
		{
			return mouseY;
		}

		/**
		 * Verifica se ponteiro do mouse está dentro de uma área determinada
		 */
		bool InputManager::IsMouseInside( Rect rect )
		{
			return rect.IsInside( mouseX, mouseY);
		}

		/**
		 * Retorna valor de quitGAme
		 */
		bool InputManager::ShouldQuit()
		{
			return quitGame;
		}
	/* FIM - METODOS */

/* FIM - InputManager*/
} // GameEngine
