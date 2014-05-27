#pragma once

#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "Rect.hpp"
#include "Game.hpp"

extern std::string FONT_PATH;

//SDL_Color DEF_COLOR = {.r = 0, .g = 0, .b = 0, .a = 0};
extern SDL_Color DEF_COLOR;

enum TextStyle{
        TEXT_SOLID,
        TEXT_SHADED,
        TEXT_BLENDED
};

namespace GameEngine {
class Text
{

    typedef std::unordered_map< std::string, TTF_Font* > UnorderedText;

	/* ATRIBUTOS */
	private:
		TTF_Font *font;
		SDL_Texture *texture = NULL;
		std::string fontFile;
		std::string text;
        TextStyle style = TextStyle::TEXT_SOLID;
        int fontSize = 10;
		SDL_Color color;
        SDL_Rect box;
		static UnorderedText assetTable;

	/* CONSTRUTOR */
	public:
        Text( std::string fontFile, int fontSize, TextStyle style,
              std::string text, SDL_Color &color, int x = 0, int y = 0 );
		~Text();

	/* METODOS */
	public:
		void Render( int cameraX = 0, int cameraY = 0);
		void SetPos( int x, int y, bool centerX = false, bool centerY = false );
		void SetText( std::string text );
		void SetColor( SDL_Color color );
		void SetStyle( TextStyle style);
		void SetFontSize( int fontSize );
		static void Clear();
		void RemakeTexture();
};
} // GameEngine
