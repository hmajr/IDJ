#pragma once

#include "GameObject.hpp"
#include "Sprite.hpp"
#include "Point.hpp"
#include "Camera.hpp"
#include <iostream>

extern const int OBJECTS_LAYER;

using namespace GameEngine;

namespace Objects {
class Bullet : public GameObject
{
	/* ATRIBUTOS */
	private:
		Sprite sp; //imagem da bullet
		Point speed; //velocidade da bala
		float distanceLeft; //distancia restante a ser percorrida
	public:
		bool targetsPlayer;

	/* CONSTRUTOR */
	public:
		/**
		 * Carrega sprite, inicializa variaveis, seta vetor velocidade, 
		 */
		Bullet( float x, float y, float angle, float speed, float maxDistance, Sprite sprite, bool targetPlayer = true );
	
	/* METODOS */
	public:
		/**
		 * Atualiza posicao e distancia remanescente
		 * @param dt DeltaTime do frame passado
		 */
		void Update( float dt );

		/**
		 * Renderiza bullet
		 */
		void Render();

		/**
		 * Notifica colisão com objetos
		 * @param other Objeto alvo da colisão
		 */
		virtual void NotifyCollision( GameObject& other );

		/**
		 * Identifica qual objete é
		 * @param  type Tipo do objeto
		 * @return      true  -> é do tipo type
		 *              false -> caso contrário
		 */
		virtual bool Is( std::string type );

		/**
		 * Verifica se distancia max foi percorrida
		 * @return true  distanceLeft <= 0
		 *         false Caso contrario
		 */
		bool IsDead();
};

} // Objects
