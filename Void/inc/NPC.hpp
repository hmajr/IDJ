#pragma once
#include "GameObject.hpp"
#include "Sprite.hpp"
#include "Camera.hpp"

using namespace GameEngine;

namespace Objects
{
class NPC :	public GameObject
{
	/* state enum*/
	public:
		typedef enum npc_type
		{
			IRMA = 0,
			PAI,
			MAE,
			AMIGO
		}NpcType;

	/* CONSTANTES */
	private:
		std::string m_IRMA_PATH = "./img/irmaIdle.png";
		std::string m_MAE_PATH = "./img/maeIdle.png";
		std::string m_PAI_PATH = "./img/paiIdle.png";
		std::string m_AMIGO_PATH = "./img/amigoIdle.png";
		const int m_TILE_WIDTH = 70;
		const int m_TILE_HEIGHT = 140;
	public:
		static const float m_ACTION_RAY; //raio de atuação
	/* ATRIBUTOS */
	private:
		Sprite sprite;
		NpcType type;

	/* CONSTRUTOR */
	public:
		NPC( float x, float y, int npcType );
		~NPC();

	/* METODOS */
	public:
		/**
		* Resgata tipo de NPC
		* @return Tipo Enum do NPC
		*/
		NpcType GetType();
		
		/**
		* Reuni instrucoes de atualizacao
		* @param dt deltaTime
		*/
		void Update(float dt);
		
		/**
		* Reuni instrucoes de renderizacao
		*/
		void Render( );
		
		/**
		* Notifica colisão com objetos
		* @param other Objeto alvo da colisão
		*/
		virtual void NotifyCollision(GameObject& other);

		/**
		* Identifica qual objete é
		* @param  type Tipo do objeto
		* @return      true  -> é do tipo type
		*              false -> caso contrário
		*/
		virtual bool Is(std::string type);

		/**
		* Defini o gameobject como morto(ser deletado)
		*/
		virtual bool IsDead();
};
}


