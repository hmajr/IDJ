#pragma once

#include <iostream>

namespace GameEngine {
class Timer
{
	private:
		float time;

	public:
		Timer();

	public:
		void Update( float dt );
		void Restart();
		float Get();
};
} // GameEngine
