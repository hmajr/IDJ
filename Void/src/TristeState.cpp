#include "TristeState.hpp"

namespace States {
	TristeState::TristeState()
		: map_tileMap(m_TRISTE_LEVEL_MAP_PATH, &tile_blockTiles), //carrega arquivo de mapas
		tile_blockTiles(m_TILE_WIDTH, m_TILE_HEIGHT, m_TRISTE_TILE_SET_PATH), //carrega sprite de blocos
		mus_Background(m_BG_MUSIC_PATH) //carrega musica de fundo
	{
		Player *player = new Player(m_INIT_PLAYER_POS.x, m_INIT_PLAYER_POS.y);

		Note *note = new Note(m_NOTES_SPAWN_POS.x, m_NOTES_SPAWN_POS.y);
		this->AddObject(note);

		this->AddObject(player);

		Camera::Follow(player);
	}

	TristeState::~TristeState()
	{
		this->mus_Background.Stop();
		this->objectArray.clear();
		Music::Clear();
		Sound::Clear();
		//  Sprite::Clear();         
 
		// Game::GetInstance().Push( new EndState( this->stateData ) );           
	}

	void TristeState::Update(float dt)
	{
		this->Input();

		// CAMERA
		Camera::Update(dt);

		for (unsigned i = 0; i < this->objectArray.size(); i++) {
			this->objectArray[i]->Update(dt);
		}

		//Condicao de Vitoria
		// WIN
		if(  0 == this->notesCount ){
			this->requestDelete = true;
			// this->stateData.playerVictory = true;
			std::cout << "VITORIAA!!" << std::endl;
            // Game::GetInstance().Push( new States::EndState( this->stateData ) );
		}
		// LOSE
        if( NULL == Player::player ) {
			this->requestDelete = true;
			// this->stateData.playerVictory = false;
			std::cout << "DERROTA!!" << std::endl;
            // Game::GetInstance().Push( new States::EndState( this->stateData ) );
		}


	}

	void TristeState::Render()
	{
		// Renderiza MAPA
		this->map_tileMap.RenderLayer(0, Camera::pos.x, Camera::pos.y);

		// Renderiza objetos do array
		this->RenderArray();

		// // Renderiza MAPA
		// this->tileMap.RenderLayer( 1, Camera::pos.x, Camera::pos.y );
	}

	void TristeState::Input()
	{
		// QUIT
		if ((InputManager::GetInstance()).ShouldQuit() ||
			(InputManager::GetInstance()).KeyRelease(ESCAPE_KEY)){
			//this->requestDelete = true;
			this->requestQuit = true;
		}

	}// FIM - Input()


}
