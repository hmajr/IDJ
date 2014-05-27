#include "Sound.hpp"

namespace GameEngine {
    /* VAR INIT*/
    std::unordered_map< std::string, Mix_Chunk* > Sound::assetTable;

	/* CONSTRUTOR */
		Sound::Sound()
		{
			this->chunk = NULL;
		}

        Sound::Sound( std::string &file )
		{
			this->chunk = NULL;
            this->Open( file );
		}

		Sound::~Sound()
		{
			Clear();
        }

	
	/* METODOS */
		void Sound::Play( int times )
		{
            if( NULL != this->chunk ){
                this->channel = Mix_PlayChannel( -1, chunk, times );
			}
			else{
                std::cout << "Sound.PLAY: " << Mix_GetError() << std::endl;
			}
		}

		void Sound::Stop()
		{
			Mix_HaltChannel( this->channel );
		}

        void Sound::Open( std::string &file )
		{
			UnorderedSound::const_iterator found = this->assetTable.find ( file );

			if( found != assetTable.end() ){
				this->chunk = found->second;
			}
			else
			{
                if( NULL == ( this->chunk = Mix_LoadWAV( file.c_str() )) ){
                    std::cout << "Sound.Open: " << Mix_GetError() << std::endl;
					return;
				}
				else{
					std::cout << "Sound OKAY!" << std::endl;
				}

	            this->assetTable.emplace( file, this->chunk ); //insere textura na tabela hash
	        }
		}

		bool Sound::IsOpen()
		{
			return ( NULL != this->chunk )? true : false;
		}

		void Sound::Clear()
		{
            for ( auto count = assetTable.begin(); count != assetTable.end(); ++count ){
				Mix_FreeChunk( count->second );
			}

            assetTable.clear();
		}

} // GameEngine
