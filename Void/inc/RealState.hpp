#pragma once

#include "State.hpp"
#include "TileMap.hpp"
#include "BlockTileSet.hpp"
//#include "Text.hpp"
#include "Music.hpp"
#include "Sound.hpp"
#include "Camera.hpp"
#include "Collision.hpp"

using namespace GameEngine;


/* =========== FUTURO  ===================*/
/* ATRIBUTOS */
// bool playerMoveLocked;	
/* METODOS */
// void (*Update_Ptr)();
// void titleUpdate();
// void realUpdate();

namespace States
{
class RealState : 
	public State
{
	/* CONSTANTES */
	private:
		 Point m_INIT_PLAYER_POS;
		 /* MAP */
		 std::string m_REAL_LEVEL_MAP_PATH;
		 std::string m_REAL_TILE_SET_PATH;
		 const int m_TILE_WIDTH;
		 const int m_TILE_HEIGHT;
		 /* SOUND */
		 std::string m_BG_MUSIC_PATH;
		 std::string m_SFX_SELECT_PATH;
		 std::string m_SFX_NPC_TALK_PATH;
		 // TEXT
		 //std::string m_TEXT_FONT_PATH;
		 //int m_FONT_SIZE;
	// END - private

		/* ATRIBUTOS */
	private:
		 std::vector<Point> m_INIT_NPC_POS;
		// bool requestedQuit;
		// bool requestedDeleted;
		 TileMap map_tileMap;
		 BlockTileSet tile_blockTiles;
		 //Text txt_Titulo;
		 Music mus_Background;
		 Sound sfx_select,sfX_talkNPC;
	// END - private

	/* CONSTRUTOR */
	public:
		RealState();
		~RealState();

	/* METODOS */
	public:
		void Update(float dt);
		void Render();
};
}
