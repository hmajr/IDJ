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

namespace States
{
class TristeState :
	public State
{
	/* CONSTANTES */
	private:
		Point m_INIT_PLAYER_POS;
		/* MAP */
		std::string m_TRISTE_LEVEL_MAP_PATH;
		std::string m_TRISTE_TILE_SET_PATH;
		const int m_TILE_WIDTH;
		const int m_TILE_HEIGHT;
		/* SOUND */
		std::string m_BG_MUSIC_PATH;
		std::string m_SFX_COLLECT_PATH;
		std::string m_SFX_ENEMY_SOUND_PATH;
		std::string m_SFX_PLAYER_LOSE_PATH;
		/* Point */
		Point m_INIT_PLAYER_POS;
	// END - private

		/* ATRIBUTOS */
	private:
		std::vector<Point> m_NOTES_SPAWN_POS;
		// bool requestedQuit;
		// bool requestedDeleted;
		TileMap map_tileMap;
		BlockTileSet tile_blockTiles;
		//Text txt_Titulo;
		Music mus_Background;
		Sound sfx_select, sfX_talkNPC;
	// END - private

	/* CONSTRUTOR */
	public:
		TristeState();
		~TristeState();
	
	/* METODOS */
	public:
		void Update(float dt);
		void Render();
};
}

