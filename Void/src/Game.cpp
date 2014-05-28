#include "Game.hpp"

namespace GameEngine 
{
	/* ATRIBUTOS */
	Game* Game::instance = NULL;

	/* CONSTRUTOR */
	Game::Game( std::string title, int width, int height)
	{
		srand( time(NULL) ); //srand que recebe long
		this->frameStart = 0;
		this->dt = 0;
		this->storedState = NULL;

        if( NULL == instance )
		{
			// Init SDL base - retorna 0 (OKAY)
            if( !(SDL_Init(  SDL_INIT_VIDEO | SDL_INIT_TIMER ) ||
            	 SDL_InitSubSystem(SDL_INIT_AUDIO) ||
                 IMG_Init( IMG_INIT_JPG | IMG_INIT_PNG ) ||
                 Mix_Init( MIX_INIT_OGG ) ||
                 TTF_Init() ||
                 Mix_OpenAudio( MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024 )) )
            {
                std::cout << "SDL_ERROR: " << SDL_GetError() << std::endl;
                std::cout << "MIX_ERROR: " << Mix_GetError() << std::endl;
                exit( 9 );
			}			
			if( NULL == (window = SDL_CreateWindow( title.c_str(), POS_X, POS_Y, width, height, 0 )) ||
                NULL == (renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED)) )
			{ 
				std::cout << SDL_GetError() << std::endl;
                exit( 10 );
			}

            instance = this;
        }
	}

	Game::~Game()
	{
		IMG_Quit(); // close image render
		Mix_CloseAudio();
        TTF_Quit();
		SDL_DestroyRenderer( renderer ); // libera window render instance
		SDL_DestroyWindow( window ); // destroy window instance
		Mix_Quit();
		SDL_Quit(); // close SDL base
	}

    /* METODOS */
	/**
	 * Loop básico do jogo
	 */
	void Game::Run()
	{
		if ( this->instance == NULL)
		{
			std::cout << "Instance igual null" << std::endl;
			return;
		}

		this->Push( this->storedState );
		this->storedState = NULL;
		
		//tratar consultando o estado atual
		while( !(this->stateStack.top()->RequestedQuit()) )
		{
			// calcula tempo do frame
			CalculateDeltaTime();

			/* Input */
			(InputManager::GetInstance()).Update();

			// verifica estado do jogo
			// quer ser deletado?
			if ( this->stateStack.top()->RequestedDelete() ){
                this->stateStack.pop();
            }

			// pilha possui um novo estado?
			this->Push();
							
			// pilha esta vazia?
			if( this->stateStack.empty() ) {
				break;
			}

			/* Update Objects */
			this->stateStack.top()->Update( dt ); //Top state Update()

			/* Render Objects */
			this->stateStack.top()->Render(); //Top state Render()

			SDL_RenderPresent( renderer );
            SDL_Delay( 33 ); //Frame Limit

            //trata estados de tela
		}

		return;
	}

	/**
	 * Retorna instancia da Game::classe (Pattern: Single Ton)
	 */
	Game& Game::GetInstance()
	{
        if( NULL != instance ){
            return (*instance);
        }
        else {
            std::cout << "GameBase NULL!!" << std::endl;
            exit(1);
        }
	}
	
	/**
	 * Retorna ponteiro para o render de tela
	 */
	SDL_Renderer* Game::GetRenderer()
	{
		if( NULL != this->renderer ){
			return this->renderer;
		}
		else{
			std::cerr << "Renderer reference is NULL" << std::endl;
		}
		
		return this->renderer;
	}
	
	State& Game::GetCurrentState()
	{
		if ( NULL != instance ){
			return *(instance->stateStack.top());
		}
		else{
			std::cout << "stateStack EMPTY" << std::endl;
			exit(2);
		}
	}

	void Game::Push( State *state )
	{
		if ( NULL != this->storedState ){
			this->stateStack.emplace( storedState );
		}

		this->storedState = state;
	}

	/**
	 * Calcula deltaTime
	 */
	void Game::CalculateDeltaTime()
	{
		this->dt = ( (float)(SDL_GetTicks()) - ((float)this->frameStart) )/1000.0f;
		frameStart = SDL_GetTicks();
	}
} // GameEngine
