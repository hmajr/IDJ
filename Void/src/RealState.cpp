#include "RealState.hpp"

/* TO-DO */
// inicializar
// m_TILE_WIDTH
// m_TILE_HEIGHT

namespace States
{
	/* CONSTRUTOR */
	RealState::RealState()
		: map_tileMap(m_REAL_LEVEL_MAP_PATH, &tile_blockTiles), //carrega arquivo de mapas
		  tile_blockTiles(m_TILE_WIDTH, m_TILE_HEIGHT, m_REAL_TILE_SET_PATH), //carrega sprite de blocos
		  mus_Background( m_BG_MUSIC_PATH ) //carrega musica de fundo
		//txt_Titulo(m_TEXT_FONT_PATH, m_FONT_SIZE, Text::)
	{
		//carrega jogador
		//carrega lista de npcs
		//efeitos sonoros
		//->caminhada
		//->conversa_npc
		//->pressed_button

	}


	RealState::~RealState()
	{
		//destruir SFX
		//destruir MUSICA
		//destruir PLAYER
		//destruir NPCS
		//chamar resource manager
	}

	/* METODOS */
	void RealState::Update(float dt)
	{
		//call player->update()
		//call npc->update()
		//check npc/player collision (circle collision)
		//	true: if pressed space
		//			change MAP
		//	false: do nothing
	}

	void RealState::Render()
	{
		//call tileMap->RenderLayer() [primeira layer]
		//for npc[i], i=1:end
		//	se player->box.y > npc[i]->box.y
		//		call player->Render
		//		call npc->Render
		//	senão
		//		call npc->Render
		//		call player->Render
		
	}
}

