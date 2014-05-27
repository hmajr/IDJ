#include "Music.hpp"

namespace GameEngine {
    /* VAR INIT*/
    std::unordered_map< std::string, Mix_Music* > Music::assetTable;

	/* CONSTRUTOR */
		Music::Music()
        {
            this->music = NULL;
        }

        Music::Music( std::string &file )
		{
            this->music = NULL;
            this->Open( file );
		}

	
	/* METODOS */
		void Music::Play( int times )
		{
            if( NULL != this->music ){
                Mix_PlayMusic( this->music , times );
            }
            else
                std::cout << "Music couldn't Play: " << Mix_GetError() << std::endl;
		}

		void Music::Stop( int fadeOut_ms )
		{
			Mix_FadeOutMusic( fadeOut_ms );
        }

        void Music::Open( std::string &file )
		{
			UnorderedMusic::const_iterator found = this->assetTable.find ( file );
            Mix_OpenAudio( MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 2048);

			if( found != assetTable.end() ){
                this->music = found->second;
			}
			else
			{
                // if( NULL == ( this->music = Mix_LoadMUS( file.c_str() )) ){
                if( NULL == ( this->music = Mix_LoadMUS( file.c_str() )) ){
                    std::cout << "Music couldn't Open: " << Mix_GetError() << std::endl;
                    return;
				}
				else{
					std::cout << "Music OKAY!" << std::endl;
				}
				
                this->assetTable.emplace( file, this->music ); //insere textura na tabela hash
	        }
		}

		bool Music::IsOpen()
		{
            return ( NULL != this->music )? true : false;
		}

		void Music::Clear()
		{
            for ( auto count = assetTable.begin(); count != assetTable.end(); ++count ){
				Mix_FreeMusic( count->second );
			}

            assetTable.clear();
		}

} // GameEngine	
