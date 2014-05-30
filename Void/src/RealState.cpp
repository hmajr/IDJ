#include "RealState.hpp"

namespace States {
		RealState::RealState()
			: map_tileMap( m_REAL_LEVEL_MAP_PATH, &tile_blockTiles ), //carrega arquivo de mapas
			  tile_blockTiles( m_TILE_WIDTH, m_TILE_HEIGHT, m_REAL_TILE_SET_PATH ), //carrega sprite de blocos
			  mus_Background( m_BG_MUSIC_PATH ) //carrega musica de fundo
		{
		    Player *player = new Player( m_INIT_PLAYER_POS.x, m_INIT_PLAYER_POS.y );

	        for (int i = 0; i < m_NUM_NPC; ++i)
	        {
	            NPC *npc = new NPC( m_INIT_NPC_POS.x, m_INIT_NPC_POS.y, i );
	        	this->AddObject( npc );
	        }

		    this->AddObject( player );

		    Camera::Follow( player );
		}

		RealState::~RealState()
		{
			this->mus_Background.Stop();
			this->objectArray.clear();
			Music::Clear();
			Sound::Clear();
//            Sprite::Clear();

//            Game::GetInstance().Push( new EndState( this->stateData ) );
		}

		void RealState::Update( float dt )
		{
			Input();

			// CAMERA
	        Camera::Update( dt );

			for ( unsigned i = 0; i < this->objectArray.size(); i++) {
				this->objectArray[i]->Update(dt);
			}

		}

		void RealState::Render( )
		{
			// Renderiza MAPA
			this->map_tileMap.RenderLayer( 0, Camera::pos.x, Camera::pos.y );

			// Renderiza objetos do array
			this->RenderArray();

			// // Renderiza MAPA
			// this->tileMap.RenderLayer( 1, Camera::pos.x, Camera::pos.y );
		}

		void RealState::Input()
		{
			// CHANGE WORLD
			if ((InputManager::GetInstance()).KeyRelease(SPACE_KEY))
			{
				for (unsigned i = 0; i < m_NUM_NPC; i++){
					if( NPC::m_ACTION_RAY > (this->objectArray[i]->box.GetCenter().Distancia( Player::player->GetPosition() )) )
					{
						if (this->objectArray[i]->Is("NPC"))
						{
							//std::cout << "CHANGE WORLD" << std::endl;
							/*NPC* temp = static_cast<NPC*>(this->objectArray[i]);
							switch ( temp->GetType() )
							{
								case NPC::NpcType::IRMA:*/
									std::cout << " ESTAGIO DO IRMA" << std::endl;
									Game::GetInstance().Push(new TristeState);
									//break;
							//	case NPC::NpcType::PAI:
							//		std::cout << " ESTAGIO DO PAI" << std::endl;
							//		//Game::GetInstance().Push(new StageState);
							//		break;
							//	case NPC::NpcType::MAE:
							//		std::cout << " ESTAGIO DO MAE" << std::endl;
							//		//Game::GetInstance().Push(new StageState);
							//		break;
							//	case NPC::NpcType::AMIGO:
							//		std::cout << " ESTAGIO DO AMIGO" << std::endl;
							//		//Game::GetInstance().Push(new StageState);
							//		break;
							//	default:
							//		std::cout << "=== ERROR === ESTAGIO DESCONHECIDO!!!! === ERROR === " << std::endl;
							//		break;
							//}
						}
					}
				}
			}

			// QUIT
			if ((InputManager::GetInstance()).ShouldQuit() ||
				(InputManager::GetInstance()).KeyRelease(ESCAPE_KEY)){
				//this->requestDelete = true;
				this->requestQuit = true;
			}
	        
		}// FIM - Input()


}
