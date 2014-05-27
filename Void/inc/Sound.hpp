#pragma once
#include <iostream>
#include <unordered_map>
#include "SDL.h"
#include "SDL_mixer.h"
#include "SDL_audio.h"


namespace GameEngine {
class Sound
{
	typedef std::unordered_map< std::string, Mix_Chunk* > UnorderedSound;
	
	private:
		std::string file;
	    Mix_Chunk *chunk;
	    int channel;
		static UnorderedSound assetTable;

	/* CONSTRUTOR */
	public:
		Sound();
		Sound( std::string &file );
		~Sound();
	
	/* METODOS */
	public:
		/**
		 * Toca um SFX
		 * @param times Numero de repetições
		 */
		void Play( int times = 0 );

		/**
		 * Interrompe som de um canal
		 */
		void Stop();

		/**
		 * Abre um arquivo de som
		 * @param file Caminho do arquivo
		 */
		void Open( std::string &file );

		/**
		 * Verifica se existe um arquivo aberto
		 * @return true, existe
		 *         false, caso contrario
		 */
		bool IsOpen();
		static void Clear();
};
} // GameEngine
