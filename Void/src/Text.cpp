//#include "Text.hpp"
//
//namespace GameEngine {
//	std::unordered_map< std::string, TTF_Font* > Text::assetTable;
//
//	/* CONSTRUTOR */
//    Text::Text(std::string fontFile, int fontSize, TextStyle style,
//                std::string text, SDL_Color &color, int x, int y )
//        : fontFile( fontFile ), text( text ), color( color )
//	{
//        this->style = style;
//        this->fontSize = fontSize;
//        this->box.x = x;
//        this->box.y = y;
//        this->box.h = 0;
//        this->box.w = 0;
//
//        UnorderedText::const_iterator found = assetTable.find ( fontFile.c_str() );
//		
//		if( found != assetTable.end() ){
//			this->font = found->second;
//		}
//		else
//		{
//            if( NULL == ( this->font = TTF_OpenFont( this->fontFile.c_str(), this->fontSize ) ) ){
//                std::cerr << "Loading Texture: " << SDL_GetError() << std::endl;
//				return;
//			}
//			
//			assetTable.emplace(this->fontFile + std::to_string(this->fontSize), font);
//        }
//
//        this->RemakeTexture();
//	}
//
//	Text::~Text()
//	{
//		//se tiver texture
//		//	DESTRUA
//	}
//
//	/* METODOS */
//	void Text::Render( int cameraX, int cameraY)
//	{
//        SDL_Rect dstrect;
//
//        dstrect.x = this->box.x + cameraX;
//        dstrect.y = this->box.y + cameraY;
//
//        dstrect.w = this->box.w;
//        dstrect.h = this->box.h;
//
//        if( NULL != this->texture ){
//            SDL_RenderCopy( Game::GetInstance().GetRenderer(), this->texture, &(this->box), &(dstrect) );
//		}
//	}
//
//    void Text::SetPos( int x, int y, bool centerX, bool centerY )
//	{
//        this->box.x = ( !centerX )? x : x - (box.w/2);
//        this->box.y = ( !centerY )? y : y - (box.h/2);
//	}
//
//	void Text::SetText( std::string text )
//	{
//		this->text = text;
//
//        this->RemakeTexture();
//	}
//
//	void Text::SetColor( SDL_Color color )
//	{
//		this->color = color;
//
//        this->RemakeTexture();
//	}
//
//	void Text::SetStyle( TextStyle style)
//	{
//        this->style = style;
//
//        this->RemakeTexture();
//	}
//
//	void Text::SetFontSize( int fontSize )
//	{
//        std::string key = this->fontFile.c_str() + std::to_string(this->fontSize);
//
//        UnorderedText::const_iterator found = assetTable.find( key );
//		
////		if( found != assetTable.end() ){
////			// Achou a fonte
////            assetTable.erase( found );
////            assetTable.emplace( this->fontFile + std::to_string(fontSize), this->font );
////            this->RemakeTexture();
////		}
//        if( found == assetTable.end() ){
//            this->fontSize = fontSize;
//
//            this->RemakeTexture();
//        }
//	}
//
//	void Text::Clear()
//	{
//		for ( auto count = assetTable.begin(); count != assetTable.end(); ++count ){
//            TTF_CloseFont( count->second );
//		}
//
//		//limpa vetor
//		assetTable.clear();
//	}
//
//	void Text::RemakeTexture()
//	{
//		if( NULL != this->texture )
//		{
//			SDL_DestroyTexture( this->texture );
//		}
//        SDL_Surface *tempSurf = NULL;
//
//        switch( this->style )
//        {
//            case TextStyle::TEXT_BLENDED:
//            {
//                tempSurf = TTF_RenderText_Blended( this->font, this->text.c_str(), this->color );
//
//                break;
//            }
//            case TextStyle::TEXT_SHADED:
//            {
//                SDL_Color bgColor = DEF_COLOR;
//
//                tempSurf = TTF_RenderText_Shaded( this->font, this->text.c_str(), this->color, bgColor);
//
//                break;
//            }
//            case TextStyle::TEXT_SOLID:
//            {
//                tempSurf = TTF_RenderText_Solid( this->font, this->text.c_str(), this->color );
//
//                break;
//            }
//        }
//
//        this->texture = SDL_CreateTextureFromSurface( Game::GetInstance().GetRenderer(), tempSurf );
//        SDL_FreeSurface( tempSurf ); //libera surface
//
//        SDL_QueryTexture( this->texture, NULL, NULL, &(this->box.w), &(this->box.h) );
//	}
//
//
//} // GameEngine
