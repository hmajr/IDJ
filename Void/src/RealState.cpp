#include "RealState.hpp"

/* TO-DO */
// inicializar
// m_TILE_WIDTH
// m_TILE_HEIGHT

namespace States
{
	/* ATRIBUTOS */

	/* CONSTRUTOR */
	RealState::RealState()
		: map_tileMap( m_REAL_LEVEL_MAP_PATH, &tile_blockTiles ), //carrega arquivo de mapas
		  tile_blockTiles( m_TILE_WIDTH, m_TILE_HEIGHT, m_REAL_TILE_SET_PATH ), //carrega sprite de blocos
		  mus_Background( m_BG_MUSIC_PATH ) //carrega musica de fundo
		//txt_Titulo(m_TEXT_FONT_PATH, m_FONT_SIZE, Text::)
	{
		/* GAME OBJECTS */
		////inicializa posicao dos npcs
		//this->m_INIT_NPC_POS = { Point(50.0f, 50.0f), Point(200.0f, 150.0f), Point(500.0f, 600.0f), Point(800.0f, 500.0f), Point(50.0f, 50.0f) };
		////carrega jogador
		////this->player = new Player( m_INIT_PLAYER_POS.x, m_INIT_PLAYER_POS.y );
		//this->AddObject(new Player(m_INIT_PLAYER_POS.x, m_INIT_PLAYER_POS.y));
		////carrega lista de npcs
		//for (unsigned i = 0; i < m_NUM_NPC; i++) {
		//	/*npcs->emplace(this->m_INIT_NPC_POS[i].x, this->m_INIT_NPC_POS[i].y, i);*/
		//	this->AddObject(new NPC(this->m_INIT_NPC_POS[i].x, this->m_INIT_NPC_POS[i].y, i));
		//}

		/* EFEITOSz SONOROS */
		////->pressed_button
		//this->sfx_select.Open(m_SFX_SELECT_PATH);
		////->conversa_npc
		//this->sfX_talkNPC.Open(m_SFX_NPC_TALK_PATH);
		////->caminhada
		//this->sfx_walkPlayer.Open(m_SFX_PLAYER_WALK_PATH);
	}


	RealState::~RealState()
	{
		//destruir SFX
		this->sfx_Sound.Clear();
		//destruir MUSICA
		this->mus_Background.Stop();
		//destruir PLAYER
		//this->
		//destruir NPCS
		//chamar resource manager
	}

	/* METODOS */
	void RealState::Update( float dt )
	{
		this->Input();

		Camera::Update(dt);

		//call objects->Update()
		for ( unsigned i = 0; i < this->objectArray.size(); i++)	{
			this->objectArray[i]->Update(dt);
		}
	}

	void RealState::Render()
	{
		float cameraX = Camera::pos.x;
		float cameraY = Camera::pos.y;

		//call tileMap->RenderLayer() [primeira layer]
		this->map_tileMap.Render( cameraX, cameraY );

		//for npc[i], i=1:end
		for (unsigned i = 0; i < this->objectArray.size(); i++)
		{
			for (unsigned j = i + 1; j < this->objectArray.size(); j++)
			{
				if (this->objectArray[ i ]->box.y > this->objectArray[ j ]->box.y)
				{
			//		call player->Render
					this->objectArray[j]->Render();

					//for (unsigned j = 0; j < m_NUM_NPC; j++){
					//// se já renderizou player, renderiza todos npcs
					//	this->npcs[i]->Render(cameraX, cameraY);
					//}
					break;
				}
				else{
			//		call npc->Render
					this->objectArray[i]->Render();
				}
			}
		//	se player->box.y > npc[i]->box.y
		}
	}
	
	/* Trata input na fase do mundo real*/
	void RealState::Input()
	{
		//check npc/player collision (circle collision)
		
		//	true: if pressed space
		//			change MAP
		//	false: do nothing
		
		// CHANGE WORLD
		if ((InputManager::GetInstance()).KeyRelease(SPACE_KEY))
		{
			for (unsigned i = 0; i < m_NUM_NPC; i++){
				if( NPC::m_ACTION_RAY > (this->objectArray[i]->box.GetCenter().Distancia( Player::player->GetPosition() )) )
				{
					if (this->objectArray[i]->Is("NPC"))
					{
						//NPC* temp = static_cast<NPC*>(this->objectArray[i]);
						//switch ( temp->GetType() )
						//{
						//	case NPC::NpcType::IRMA:
						//		std::cout << " ESTAGIO DO IRMA" << std::endl;
						//		//Game::GetInstance().Push(new TristeState);
						//		break;
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
	}

}

