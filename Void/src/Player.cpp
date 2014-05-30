#include "Player.hpp"

namespace Objects
{

	/* CONSTANTES */
	Player *Player::player = NULL;

	Player::Player( float initX, float initY )
		: idleAnim( m_ANIM_IDLE_PATH ), walkSide(m_ANIM_WALK_SIDE_PATH, 4, 6, 0.033f), 
		  walkUp(m_ANIM_WALK_UP_PATH, 4, 6, 0.033f), walkDown(m_ANIM_WALK_DOWN_PATH, 4, 6, 0.033f),
		  currentAnimation(idleAnim)
	{
		Player::player = this;
		this->speed = 0;
		this->hitPoints = m_PLAYER_HP;
		// this->deathSound.Open( DEATH_SOUND_PATH );

		this->box.h = this->idleAnim.GetHeight();
		this->box.w = this->idleAnim.GetWidth();
		this->box.x = initX - (this->box.w / 2);
		this->box.y = initY - (this->box.h / 2);
	}

	Player::~Player()
	{

	}

	/* METODOS */
	/**
	* Reuni instrucoes de atualizacao
	*/
	void Player::Update(float dt)
	{
		/* MOVIMENTACAO */
		if ((InputManager::GetInstance()).IsKeyDown(A_KEY)) {
			this->speed.x -= m_ACELERATION*dt;
			this->isFlipped = true;
			//set animation
			this->currentAnimation = this->walkSide;
		}
		else if ((InputManager::GetInstance()).IsKeyDown(D_KEY)) {
			this->speed.x += m_ACELERATION*dt;
			this->isFlipped = false;
			//set animation
			this->currentAnimation = this->walkSide;
		}

		if ((InputManager::GetInstance()).IsKeyDown(W_KEY)) {
			this->speed.y -= m_ACELERATION*dt;
			//set animation UP
			this->currentAnimation = this->walkUp;
		}
		else if ((InputManager::GetInstance()).IsKeyDown(S_KEY)) {
			this->speed.y += m_ACELERATION*dt;
			//set animation DOWN
			this->currentAnimation = this->walkDown;
		}
		if ((InputManager::GetInstance()).IsKeyDown(A_KEY) ||
			(InputManager::GetInstance()).IsKeyDown(D_KEY) ||
			(InputManager::GetInstance()).IsKeyDown(W_KEY) ||
			(InputManager::GetInstance()).IsKeyDown(S_KEY) )
		{
			//set animation IDLE
			this->currentAnimation = this->idleAnim;
			this->speed = (0, 0);
			this->currentAnimation.SetFrame();
		}
		this->box.x += this->speed.x;
		this->box.y += this->speed.y;
		
		
		//calcula velocidade
		//this->speed += m_ACELERATION * dt;
		//calcula posicao
		//this->box.x += cos(this->rotation) * this->speed;
		//this->box.y += sin(this->rotation) * this->speed;

		// VERIFICA VEL MAX
		if ( m_SPEED_MAX < this->speed.GetMag() ){
			this->speed.x = cos(this->speed.AngEixoX()) * m_SPEED_MAX;
			this->speed.y = sin(this->speed.AngEixoX()) * m_SPEED_MAX;
		}
		
		/* ANIMACAO */
		this->currentAnimation.Update( dt );
	}

	/**
	* Reuni instrucoes de renderizacao
	*/
	void Player::Render()
	{
		/* RENDER SPRITE ANIMATION */
		this->currentAnimation.Render(this->box.x + Camera::pos.x, this->box.y + Camera::pos.y,
									  this->rotation			 , this->isFlipped);
	}

	/*
	* Pega posição atual do player
	*/
	Point Player::GetPosition()
	{
		return this->box.GetCenter();
	}

	/**
	* Notifica colisão com objetos
	*/
	void Player::NotifyCollision( GameObject& other )
	{
		
	}

	/**
	* Identifica qual objete é
	*/
	bool Player::Is( std::string type )
	{
		return ("Player" == type) ? true : false;
	}

	/**
	* Verifica se GameObject está morto
	*/
	bool Player::IsDead()
	{
		return (this->isHitted) ? true : false;
	}
}