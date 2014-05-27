#include "StillAnimation.hpp"

namespace GameEngine {
	
	/* CONSTRUTOR */	
	StillAnimation::StillAnimation( float x, float y, float rotation, 
									Sprite sprite, float timeLimit, bool ends )
	{
		this->box.x = x;
		this->box.y = y;

		this->rotation = rotation;
		this->sp = sprite;
		this->timeLimit = timeLimit;
		this->oneTimeOnly = ends;
	}

	StillAnimation::~StillAnimation()
	{

	}

	/* METODOS */
	void StillAnimation::Update( float dt )
	{
		this->endTimer.Update( dt );

		this->sp.Update( dt );

		if( (this->endTimer.Get() >= this->timeLimit) && !(this->oneTimeOnly) ){
			this->endTimer.Restart();
		}
	}

	void StillAnimation::Render()
	{
		this->sp.Render( this->box.x, this->box.y, this->rotation );
	}

	bool StillAnimation::IsDead()
	{ 
		if ( this->oneTimeOnly && (this->timeLimit <= this->endTimer.Get()) ){
			return true;
		}
		return false;
	}

    void StillAnimation::NotifyCollision( GameObject& other )
	{

	}

	bool StillAnimation::Is( std::string type )
	{
		return ( type == "StillAnimation" );
	}
} // GameEngine
