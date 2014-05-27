#ifdef DEBUG_MODE
#pragma once

#include "SDL.h"
#include "SDL_ttf.h"
#include "Camera.hpp"
#include "GameObject.hpp"
#include "Game.hpp"

namespace GameEngine 
{
// class Debug : public GameObject	
class Debug
{
	/* ATRIBUTOS */

	/* CONSTRUTOR */
	public:
		static Debut& GetInstance();
	private:
		Debug();
		~Debug();
		
	/* METODOS */
	public:
		void Update( float dt );
		void Render( float dt );
};
} // GameEngine
#endif // DEBUG_HPP
