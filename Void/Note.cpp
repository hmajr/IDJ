#include "Note.hpp"

namespace Objects{
	/* CONSTRUTOR */
	Note::Note(float initX, float initY)
		:sprite( m_NOTA_PATH )
	{

	}
	Note::~Note()
	{

	}

	/* METODOS */
	void Note::Update(float dt)
	{

	}

	void Note::Render()
	{

	}

	/**
	* Notifica colisão com objetos
	*/
	void Note::NotifyCollision(GameObject& other)
	{

	}

	/**
	* Identifica qual objete é
	*/
	bool Note::Is(std::string type)
	{
		return (type == "Note") ? true : false;
	}

	/**
	* Defini o gameobject como morto(ser deletado)
	*/
	bool Note::IsDead()
	{
		return (this->collected);
	}
}