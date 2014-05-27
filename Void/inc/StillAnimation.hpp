#pragma once
#include "GameObject.hpp"
#include "Sprite.hpp"
#include "Timer.hpp"

namespace GameEngine {
class StillAnimation : public GameObject
{
	/* ATRIBUTOS */
	private:
		Sprite sp; //sprite da animacao
		Timer endTimer; //temporizador
		float timeLimit; //tempo limite da animacao
		bool oneTimeOnly; //tocar animacao uma vez só

	/* CONSTRUTOR */
	public:
		StillAnimation( float x, float y, float rotation, Sprite sprite, float timeLimit, bool ends );
		~StillAnimation();
	/* METODOS */
	public:
		void Update( float dt );
		void Render();
		void NotifyCollision( GameObject& other );
		bool Is( std::string type );
		bool IsDead();
};
} // GameEngine

