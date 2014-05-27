#include "Sprite.hpp"

using GameEngine::Sprite;

namespace GameEngine {
/* SPRITE CLASS */
	/* Inicializacao */
	std::unordered_map<std::string, SDL_Texture*> Sprite::assetTable;

	/* CONSTRUTORES */
	Sprite::Sprite() 
	{
		this->texture = NULL;
        this->resource.userCount = 0;
        this->resource.data.texture = this->texture;
		this->SetFrameCount();
		this->SetFrameTime();
	}
	
	Sprite::Sprite( std::string& file, int frameCount, float frameTime )//Carrega textura do arquivo
	{
        //num de frames
        this->frameCount = frameCount;
        this->frameTime = frameTime;

        this->texture = NULL;
        this->Open( file ); // carrega textura

        this->numFramesLine = this->dimensions.w / clipRect.w;
//        this->numFramesColunm = this->dimensions.h / clipRect.h;

        // calcula largura/altura de um frame
        this->clipRect.w = (this->dimensions.w / this->frameCount);
        this->clipRect.h = this->dimensions.h;
	} 
	
	// destroy loaded sprite file 	
	Sprite::~Sprite()
	{
        this->resource.userCount -= 1;
	} 

	/* METODOS */
	// load image from file path	
	void Sprite::Open( std::string& file )
	{
        this->resource.userCount += 1;
		UnorderedSprite::const_iterator found = assetTable.find ( file );

		if( found != assetTable.end() ){
			this->texture = found->second;
		}
		else
		{
            if( NULL == ( this->texture = IMG_LoadTexture( Game::GetInstance().GetRenderer(), file.c_str() )) ){
				std::cerr << "Loading Texture: " << SDL_GetError() << std::endl;
				return;
			}
			
            this->assetTable.emplace( file, this->texture ); //insere textura na tabela hash

        }
        SDL_QueryTexture( this->texture, NULL, NULL, &(this->dimensions.w), &(this->dimensions.h) );

        /*resource*/
        this->resource.data.texture = this->texture;

        this->SetClip( 0, 0, this->dimensions.w , this->dimensions.h);
	}

	// Set retangulo de recorte da imagem a ser renderizada
	void Sprite::SetClip( int x, int y, int w, int h ) 
	{
		clipRect.x = x;
		clipRect.y = y;
		clipRect.w = w;
		clipRect.h = h;
	}

	//UPDATE
	void Sprite::Update( float dt )
	{
		this->timeElapsed += dt;

		// std::cout<<"TimeElapsed " << this->timeElapsed << std::endl;

		if( this->timeElapsed >= this->frameTime )
		{
			currentFrame = (currentFrame + 1) % this->frameCount;

// std::cout<<"ENTROU IF ANIMATION, frame: " << this->currentFrame << std::endl;
// std::cout<<"FRAME, w: " << this->clipRect.w << std::endl;
			// calcula posicao do retangulo de recorte
			this->clipRect.x = (this->currentFrame * this->clipRect.w) % this->GetWidth();
			this->clipRect.y = (this->currentFrame / this->clipRect.w) * this->GetFrameHeight() % this->GetHeight();


			this->timeElapsed = 0;

		}
	}

	// Renderiza texture na tela de jogo
	void Sprite::Render( int x, int y, float angle ) 
	{
		SDL_Rect dstrect;
		angle = (angle*180)/PI;

		dstrect.x = x * this->scaleX;
		dstrect.y = y * this->scaleY;
		
		dstrect.w = clipRect.w * this->scaleX;
		dstrect.h = clipRect.h * this->scaleY;
		
		// std::cout<< "clipRect W: "<< clipRect.w <<",H: " << clipRect.h <<std::endl;

		SDL_RenderCopyEx( Game::GetInstance().GetRenderer(), texture, &clipRect, &dstrect,
						  angle, NULL, SDL_FLIP_NONE );
	}

	/* GET/SET */
	/**
	 * Seta frame de spritesheet
	 */
	void Sprite::SetFrame( int frame )
	{
		if( (0 <= frame) && (this->frameCount > frame) )
		{
			currentFrame = frame;

			clipRect.x = (currentFrame * numFramesLine) % this->GetWidth();
			clipRect.y = (currentFrame / numFramesLine) * this->GetFrameHeight() % this->GetHeight();
		}
	}

	/**
	 * Seta contador de frames
	 */
	void Sprite::SetFrameCount( int frameCount )
	{
		this->frameCount = frameCount;
	}

	/**
	 * Seta velocidade da animacao
	 */
	void Sprite::SetFrameTime( float frameTime )
	{
		this->frameTime = frameTime;
	}

	// retorna largura da imagem
	int Sprite::GetWidth() 
	{
		return this->dimensions.w * (this->scaleX);
	}

	// retorna altura da imagem
	int Sprite::GetHeight() 
	{
		return this->dimensions.h * (this->scaleY);
	}

	/**
	 * Resgata altura do frame atual
	 */
	int Sprite::GetFrameHeight()
	{
		return this->clipRect.h;
	}

	/**
	 * Get largura do frame atual
	 */
	int Sprite::GetFrameWidth()
	{
		return this->clipRect.w;
	}

	// Verifica se já existe textura alocada	
	bool Sprite::IsOpen() 
	{
		return ( NULL != texture)? true : false;
	}
	
	/**
	 * Limpa tabela de hash
	 */
	void Sprite::Clear()
	{
		for ( auto count = assetTable.begin(); count != assetTable.end(); ++count ){
//            if( 0 == resource.userCount ){
				SDL_DestroyTexture( count->second );
//				assetTable.remove( count );
//			}
		}

		//limpa vetor
	}
/* END - SPRITE CLASS */
} // GameEngine
