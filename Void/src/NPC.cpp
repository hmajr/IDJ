#include "NPC.hpp"

namespace Objects
{
	const float NPC::m_ACTION_RAY = 100.0f;
	/* CONSTRUTOR */
	NPC::NPC( float initX, float initY, int npcType )
	{
		switch (npcType)
		{
			case NpcType::IRMA:
				this->sprite.Open(m_IRMA_PATH);
				break;
			//case NpcType::MAE:
			//	this->sprite.Open(m_MAE_PATH);
			//	break;
			//case NpcType::PAI:
			//	this->sprite.Open(m_PAI_PATH);
			//	break;
			//case NpcType::AMIGO:
			//	this->sprite.Open(m_AMIGO_PATH);
			//	break;
		}

		this->box.x = initX - this->box.w / 2;
		this->box.y = initY - this->box.h / 2;
	}

	NPC::~NPC()
	{

	}

	/* METODOS */
	NPC::NpcType NPC::GetType()
	{
		return this->type;
	}
	void NPC::Update(float dt)
	{

	}

	/*
		Renderiza objeto na tela
	*/
	void NPC::Render( )
	{
		this->sprite.Render( this->box.x + Camera::pos.x, 
							 this->box.y + Camera::pos.y, 
							 this->isFlipped );
	}

	/**
	* Notifica colisão com objetos
	*/
	void NPC::NotifyCollision(GameObject& other)
	{

	}

	/**
	* Identifica qual objete é
	*/
	bool NPC::Is(std::string type)
	{
		return ("NPC" == type)? true : false;
	}

	/**
	* Defini o gameobject como morto(ser deletado)
	*/
	bool NPC::IsDead()
	{
		return false;
	}
}