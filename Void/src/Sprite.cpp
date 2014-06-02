#include "Sprite.hpp"

namespace GameEngine {
/* SPRITE CLASS */
	/* Inicializacao */
	std::unordered_map<std::string, SDL_Texture*> Sprite::assetTable;

	/* CONSTRUTORES */
	Sprite::Sprite() 
	{
		
	}
	
	Sprite::Sprite(  )//Carrega textura do arquivo
	{
    
	} 
	
	// destroy loaded sprite file 	
	Sprite::~Sprite()
	{
	} 

	/* METODOS */
	// load image from file path	
	void Sprite::Open( std::string& file )
	{
       
	}

	// Set retangulo de recorte da imagem a ser renderizada
	void Sprite::SetClip( int x, int y, int w, int h ) 
	{

	}

	//UPDATE
	void Sprite::Update( float dt )
	{
		
	}

	// Renderiza texture na tela de jogo
	void Sprite::Render( int x, int y, float angle, bool flip)
	{
		
	}

	/* GET/SET */
	/**
	 * Seta frame de spritesheet
	 */
	void Sprite::SetFrame( int frame )
	{
		
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

	}
/* END - SPRITE CLASS */
} // GameEngine
