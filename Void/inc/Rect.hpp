#pragma once

#include "Point.hpp"

namespace Geometry {

class Rect
{
	/* ATRIBUTOS */
	public:
		float x, y;
		float h, w;
	/* CONSTRUTOR */
	public:
		Rect( float x1 = 0, float y1 = 0, float h1 = 1, float w1 = 1 );
		~Rect();

	/* METODOS */
	public:
		/**
		 * Obtem centro do retangulo (this)
		 * @return Ponto com coordenadas do centro
		 */
		Point GetCenter();

		/**
		 * Verifica se um ponto (x1, y1) está contido no retangulo (this)
		 * @param  x1 Coordenada X
		 * @param  y1 Coordenada Y
		 * @return    true  Contido no retangulo
		 *            false Caso contrário
		 */
		bool IsInside( float x1, float y1 );
	
		/**
		 * Adciona a posição do retangulo uma coordenada p
		 * @param p Coordenada (x,y) a ser somada
		 */
		void AddPoint( Point& p );

		// Distancia em relacao a um Rect
		/**
		 * Distancia em relação a um retangulo
		 * @param  b Retangulo a comparação
		 * @return   Módulo da distancia entre os retangulos
		 */
		float DistRect( Rect& b );

	/* FIM - public*/

};
} // Geometry
