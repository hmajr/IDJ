#include "Point.hpp"

namespace Geometry {
/* CLASSE POINT */
	/* CONSTRUTOR */
	Point::Point( float x1, float y1) : x(x1), y(y1){ 
	}

	Point::~Point(){ 
	}

	/* METODOS */
	// distancia 2 pontos
	float Point::Distancia( Point p )
	{
		float tempX = this->x - p.x; //armazena distancia em X
		float tempY = this->y - p.y; //armazena distancia em Y

		//calcular distancia
		return hypot(tempX, tempY);
	}

	// inclinacao reta dado 2 pontos
	float Point::InclReta( Point &p1 )
	{
        Point p = *this - p1; // p(this->x - p1.x; this->y - p1.y)

        return atan2( p.y, p.x );
	}

	//rotaciona vetor em ang angulos (em radianos)
	void Point::Rotate( float rad, float mod )
	{
		// float rad = (ang * PI) / 180;
		this->x = std::cos( rad ) * mod;
		this->y = std::sin( rad ) * mod;
	}

	
	// Retorna magnitude
	float Point::GetMag()
	{
		return hypot( this->x, this->y);
	}

	// escalar * vetor
	void Point::DotEscalar( float& num )
	{
		(*this).x = (*this).x * num;
		(*this).y = (*this).y * num;
	}
	/* FIM - METODOS*/

/* FIM - CLASSE POINT */

} // Geo
