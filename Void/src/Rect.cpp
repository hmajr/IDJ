#include "Rect.hpp"

namespace Geometry {
/* CLASSE RECT*/
	/* CONSTRUTOR */
	Rect::Rect( float x1, float y1, float h1, float w1 )
		: x(x1), y(y1), h(h1), w(w1)
	{
		
	}

	Rect::~Rect()
	{
		
	}

	/* METODOS */
	// obtem centro de um rect
	Point Rect::GetCenter()
	{
		Point center( x+(w/2), y+(h/2) );

		return center;
	}
	
	// ponto dentro rect?
	bool Rect::IsInside( float x1, float y1 )
	{
		bool vertical;
		bool horizontal;

		vertical = ( y1 >= (*this).y && y1 <= ((*this).y + (*this).w) )? true:false;
		horizontal = ( x1 >= (*this).x && x1 <= ((*this).x + (*this).w) )? true:false;
		
		return (vertical && horizontal);
	}

	// soma ponto a pos do rect
	void Rect::AddPoint( Point& p )
	{
		(*this).x += p.x;
		(*this).y += p.y;
	}
	
	// Distancia em relacao a um Rect
	float Rect::DistRect( Rect& b )
	{
		Point cR1, cR2; // posicao do centro dos rects

		// obtem centro dos retangulos
		cR1 = (*this).GetCenter();
		cR2 = b.GetCenter();

		return cR2.Distancia( cR1 ); //obtem distancia
	}
/* FIM - CLASSE GEOMETRY */
} // Geometry
