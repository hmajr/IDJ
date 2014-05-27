#pragma once

#include <iostream>
#include <unordered_map>
#include "SDL.h"
#include "SDL_mixer.h"

namespace GameEngine {
class Music
{
    typedef std::unordered_map< std::string, Mix_Music* > UnorderedMusic;
	/* ATRIBUTOS */
	private:
		std::string file;
        Mix_Music *music;
        static UnorderedMusic assetTable;
	
	/* CONSTRUTOR */
	public:
		Music();
        Music(std::string &file );
	
	/* METODOS */
	public:
        void Play( int times = 0 );
		void Stop( int fadeOut_ms = 100 );
        void Open( std::string &file );
		bool IsOpen();
		static void Clear();
	
	
};
} // GameEngine
