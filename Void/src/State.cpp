#include "State.hpp"

namespace GameEngine {
	/* CONSTRUTOR */
	State::State() : requestDelete( false ), requestQuit( false )
	{
        this->objectArray.clear();
	}

	State::~State()
	{

	}


	/* METODOS */
	void State::Update( float dt )
	{

	}

	void State::Render()
	{

	}

	void State::AddObject( GameObject *object )
	{
        if( NULL != object){
            this->objectArray.emplace_back( object );
        }
        else{
            std::cout << "OBJECT NULL: " << std::endl;
        }
	}

	bool State::RequestedDelete()
	{
		return this->requestDelete;
	}

	bool State::RequestedQuit()
	{
		return this->requestQuit;
	}

	void State::UpdateArray( float dt )
	{
		// Renderiza objetos do array
		for(unsigned i = 0; i < this->objectArray.size(); ++i) {
			this->objectArray[i]->Update( dt );
		}
	}

	void State::RenderArray()
	{
		// Renderiza objetos do array
		for(unsigned i = 0; i < this->objectArray.size(); ++i) {
            if( NULL != this->objectArray[i] ){
                this->objectArray[i]->Render();
            }
            else{
                this->objectArray.erase( this->objectArray.begin() + i);
            }

        }
	}


} // GameEngine
