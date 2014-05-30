#pragma once

#include "State.hpp"
#include "TileMap.hpp"
#include "BlockTileSet.hpp"
#include "StateData.hpp"
//#include "Text.hpp"
#include "Music.hpp"
#include "Sound.hpp"
#include "Camera.hpp"
#include "Collision.hpp"
#include "Player.hpp"
#include "Note.hpp"
#include "TristeEnemy.hpp"

using namespace GameEngine;
using namespace Objects;
using namespace Geometry;

namespace States
{
class TristeState :
	public State
{
	/* CONSTANTES */
	private:
		/* MAP */
		std::string m_TRISTE_LEVEL_MAP_PATH = "./map/TristeWorld.txt";
		std::string m_TRISTE_TILE_SET_PATH = "./img/TristeWorldTile.png";
		int m_TILE_WIDTH;
		int m_TILE_HEIGHT;
		/* ENEMIES */
		std::string m_ENEMEY_PATH = "./img/irmaMonster.png";
		/* SOUND */
		std::string m_BG_MUSIC_PATH;
		std::string m_SFX_COLLECT_PATH;
		std::string m_SFX_ENEMY_SOUND_PATH;
		std::string m_SFX_PLAYER_LOSE_PATH;
		/* Point */
		int m_NUM_NOTES = 5;
		Point m_INIT_PLAYER_POS = Point(100.0f, 100.0f);
		Point m_NOTES_SPAWN_POS = Point(600.0f, 600.0f);
	// END - private

		/* ATRIBUTOS */
	private:
		// std::vector<Point> m_NOTES_SPAWN_POS;
		// bool requestedDeleted;
		int notesCount = 0;
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
		void Input();
};
}

