#pragma once
#include "Rect.hpp"

namespace GameEngine 
{
class GameObject 
{
	/* ATRIBUTOS */
    protected:
        bool isCollided;
	public:
		Geometry::Rect box; //posicao e dimensao do objeto
		float rotation = 0;

	/* CONSTUTOR */
	public:
		virtual ~GameObject();

	/* METODOS */
	public:
		/**
		 * Reuni instrucoes de atualizacao
		 * @param dt deltaTime
		 */
		virtual void Update( float dt ) = 0;

		/**
		 * Reuni instrucoes de renderizacao
		 */
		virtual void Render() = 0;

		/**
		 * Notifica colisão com objetos
		 * @param other Objeto alvo da colisão
		 */
		virtual void NotifyCollision( GameObject& other ) = 0;

		/**
		 * Identifica qual objete é
		 * @param  type Tipo do objeto
		 * @return      true  -> é do tipo type
		 *              false -> caso contrário
		 */
		virtual bool Is( std::string type ) = 0;
		
		/**
		 * Defini o gameobject como morto(ser deletado)
		 */
		virtual bool IsDead() = 0;
};
} // GameEngine
