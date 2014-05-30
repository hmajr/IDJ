#pragma once
#include "GameObject.hpp"

using namespace GameEngine;

namespace Objects
{
class TristeEnemy : public GameObject
{
	public:
		TristeEnemy();
		~TristeEnemy();

	public:
		void Update(float dt);
};
}


