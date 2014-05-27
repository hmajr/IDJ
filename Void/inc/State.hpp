#pragma once

#include <memory>
#include <vector>
#include "GameObject.hpp"

namespace GameEngine {
class State
{
	/* ATRIBUTOS */
	protected:
		bool requestDelete;
		bool requestQuit;
        std::vector< std::unique_ptr<GameObject> > objectArray;
	/* CONSTRUTOR */
	public:
		State();
		virtual ~State();
	
	/* METODOS */
	public:
		virtual void Update( float dt ) = 0;
		virtual void Render() = 0;
		virtual void AddObject( GameObject *object );
		bool RequestedDelete();
		bool RequestedQuit();
	protected:
		virtual void UpdateArray( float dt );
		virtual void RenderArray();
};
} // GameEngine