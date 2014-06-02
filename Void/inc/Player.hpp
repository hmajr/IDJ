#pragma once

#include <cmath>
#include "GameObject.hpp"
#include "InputManager.hpp"
#include "Sprite.hpp"
#include "Timer.hpp"
#include "Camera.hpp"

using namespace GameEngine;

namespace Objects
{
class Player :
		public GameObject
{
	typedef enum playerEnum
	{
		IDLE = 0,
		MOVING_UP,
		MOVING_DOWN,
		MOVING_SIDE,
	}PlayerEnum;

	/* CONSTANTES */
	/* SPRITE */
	std::string m_ANIM_IDLE_PATH = "./img/mainIdle.png";
	std::string m_ANIM_WALK_UP_PATH = "./img/mainWalkCostas.png";
	std::string m_ANIM_WALK_SIDE_PATH = "./img/mainWalkEsq.png";
	std::string m_ANIM_WALK_DOWN_PATH = "./img/mainWalkFrent.png";
	const int m_TILE_WIDTH = 70;
	const int m_TILE_HEIGHT = 140;
	/* MOVIMENTACAO */
	const float m_SPEED_MAX = 200.0f;
	const float m_ACELERATION = 50.0f;
	const int m_PLAYER_HP = 20.0f;
	/* SOUNDS */
	// caminhada
	// morte

	/* ATRIBUTOS */
	private:
		PlayerEnum playerState;
		Point speed;
		float hitPoints;
		Sprite &currentAnimation, idleAnim, walkSide, walkUp, walkDown;
		bool isHitted;
	public:
		static Player *player;
	

	/* CONSTRUTOR */
	public:
		Player( float initX, float initY );
		~Player();
	
	/* METODOS */
	public:
		/**/
		void Update( float dt );

		/**/
		void Render( );
		
		/*
		* Pega posição atual do player
		*/
		Point GetPosition();

		/**
		* Notifica colisão com objetos
		*/
		void Player::NotifyCollision(GameObject& other);

		/**
		* Identifica qual objete é
		*/
		bool Player::Is(std::string type);

		/**
		* Verifica se GameObject está morto
		*/
		bool Player::IsDead();
};
}

