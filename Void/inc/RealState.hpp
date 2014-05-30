#pragma once

#include <memory>
#include <vector>
#include "State.hpp"
#include "TileMap.hpp"
#include "BlockTileSet.hpp"
//#include "Text.hpp"
#include "TristeState.hpp"
#include "Music.hpp"
#include "Sound.hpp"
#include "Camera.hpp"
#include "Collision.hpp"
#include "Player.hpp"
#include "NPC.hpp"

using namespace GameEngine;
using namespace Objects;


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
		/* GAME OBJECTS */
		Point m_INIT_PLAYER_POS = Point(500, 500);
		Point m_INIT_NPC_POS = Point(200,200);
		const int m_NUM_NPC = 1;
		/* MAP */
		std::string m_REAL_LEVEL_MAP_PATH = "./map/RealWorld.txt";
		std::string m_REAL_TILE_SET_PATH = "./img/RealWorldTile.png";
		const int m_TILE_WIDTH = 64;
		const int m_TILE_HEIGHT = 64;
		/* SOUND */
		std::string m_BG_MUSIC_PATH;
		std::string m_SFX_SELECT_PATH;
		std::string m_SFX_NPC_TALK_PATH;
		std::string m_SFX_PLAYER_WALK_PATH;
		// TEXT
		//std::string m_TEXT_FONT_PATH;
		//int m_FONT_SIZE;
		
	// END - private

		/* ATRIBUTOS */
	private:
		//Player *player;
		//std::vector< std::unique_ptr<NPC> > npcs;
		TileMap map_tileMap;
		BlockTileSet tile_blockTiles;
		//Text txt_Titulo;
		Music mus_Background;
		Sound sfx_Sound;
	// END - private

	/* CONSTRUTOR */
	public:
		RealState();
		~RealState();

	/* METODOS */
	public:
		void Update( float dt );
		void Render();
		void Input();
};
}
