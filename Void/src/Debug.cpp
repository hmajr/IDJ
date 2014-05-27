#ifdef DEBUG_MODE

#include "Debug.hpp"

namespace GameEngine 
{
// class Debug : public GameObject
	Debut& Debug::GetInstance()
	{
		static Debug debug;

		return debug;
	}

	Debug::Debug()
	{
		if( -1 != TTF_Init() ){
			std::cerr << "ERRO INIT TTF_Init" << std::endl;
		}

		TTF_Font* font = TTF_OpenFont("ARIAL.TTF", 12);
		
		SDL_Color foregroundColor = { 255, 255, 255 }; // vermelho escuro
		SDL_Color backgroundColor = { 255, 0, 50 }; // branco
		
		SDL_Surface* textSurface = TTF_RenderText_Shaded(font, "DEBUG CONSOLE", 
														 foregroundColor, backgroundColor);
		SDL_Rect textLocation = { 10, 10, 0, 0 };
        
    	SDL_BlitSurface(textSurface, NULL, screen, &textLocation);
	}

	Debug::~Debug()
	{

	}
	
	void Debug::Update( float dt )
	{
		/* Update */
        // TEXT
        // TileMaps
        // GameObjects
		//atualiza posicao dos retangulos
		//-> gameObjects
		//-> TileMap
		//-> vetores (mod, dir, sent )
		//-> pontos
	}

	void Debug::Render( float dt )
	{
		/* DESENHA */
		// retangulos dos gameObjects
		// centro das imagens
		// 
		// atualiza texto
		// -> posicao da camera
		// -> dt do frame
	}

} // GameEngine

#endif // DEBUG_HPP
