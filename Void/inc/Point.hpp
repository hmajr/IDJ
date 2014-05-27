#pragma once
#include <iostream>
#include <cmath>

// const float HIP = 200;
const float PI = 3.1415f;

namespace Geometry {
class Point
{
	/* ATRIBUTOS */
	public:
		float x, y;

	/* CONSTRUTOR */
	public:
		Point( float x1 = 0, float y1 = 0 ); //inicializa ponto na pos (x, y)
		~Point();
	// FIM - public

	/* METODOS */
	public:
		/**
		 * Distancia em relação a um ponto
		 * @param  p Ponto origem
		 * @return   Distancia entre this e p
		 */
		float Distancia( Point p );

		// distancia ponto reta
		// float Distancia( Point& p1 );


		/**
		 * Inclinacao da reta dado 2 pontos
		 * @param  p1 Ponto final
		 * @return    Inclinacao da reta em RADIANOS
		 */
		float InclReta( Point &p1 );

		//Vector - ( 0, 0 ) - canto superior esquerdo
		// rotacao 
		void Rotate( float rad, float mod );

		// inclinacao em rel. eixo x
		float AngEixoX ()
		{
			float rad = atan2( y, x);

			return rad;
		}

		// magnitude
		float GetMag();

		// normalizacao
		// projecao em X
		// projecao em Y

		// escalar * vetor
		void DotEscalar( float& num );
		
		// colisao ponto/rect
		// bool ColisaoRect( Rect rect );
	/* FIM - public*/

	/* OPERADORES */
	public:
        Point operator + (const Point &p) const {
            return Point((this->x + p.x), (this->y + p.y));
        }

        void operator - () {
            this->x = -(this->x);
            this->y = -(this->y);
        }

        Point operator-(const Point& rhs) const {
           return Point(x - rhs.x, y - rhs.y);
        }

        void operator += (Point &p) {
            (*this).x = ((*this).x + p.x);
            (*this).y = ((*this).y + p.y);
        }

        void operator -= (Point &p){
            (*this).x = ((*this).x - p.x);
            (*this).y = ((*this).y - p.y);
        }

        Point operator*(const float rhs) const {
            return Point(x * rhs, y * rhs);
         }
	/* FIM - public */
};
} // Geometry
