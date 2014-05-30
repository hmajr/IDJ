#include "Bullet.hpp"

namespace Objects {

/* CLASSE BULLET*/
	/* CONSTRUTOR */
	/**
	 * Carrega sprite, inicializa variaveis, seta vetor velocidade, 
	 */
	Bullet::Bullet( float x, float y, float angle, float speed, float maxDistance, Sprite sprite, bool targetPlayer )
	{
		this->sp = sprite;
		this->box.w = this->sp.GetFrameWidth();
		this->box.h = this->sp.GetFrameHeight();
		this->box.x = x - ( (this->box.w) / 2);
		this->box.y = y - ( (this->box.h) / 2);
		this->targetsPlayer = targetPlayer;
		
        this->distanceLeft = maxDistance;

		this->speed.x = speed;
        // rotacionar vetor normalizado
		this->speed.Rotate( angle, speed );
        // multiplicar pela velocidade
		
		
	}

	/* METODOS */
	/**
	 * Atualiza posicao e distancia remanescente
	 */
	void Bullet::Update( float dt )
	{
        //this->isCollided = false;
		this->box.x += this->speed.x * dt;
		this->box.y += this->speed.y * dt;
		this->distanceLeft -= this->speed.GetMag() * dt;

		this->sp.Update( dt );
	}

	/**
	 * Renderiza bullet
	 */
	void Bullet::Render()
	{
		sp.Render( this->box.x + Camera::pos.x, //*OBJECTS_LAYER, 
				   this->box.y + Camera::pos.y, //*OBJECTS_LAYER,
				   this->speed.AngEixoX() );
	}

	/**
	 * Notifica colisão com objetos
	 */
	void Bullet::NotifyCollision( GameObject& other )
	{
        if( ((other.Is( "Alien" ) || other.Is( "Minion" )) && !(this->targetsPlayer) ) ||
            (other.Is( "Penguins" ) && this->targetsPlayer) )//&& !(this->isCollided) )
        {
			std::cout << "BULLET: COLISAO" << std::endl;
			this->distanceLeft = -1;
            //this->isCollided = true;
		}		
	}

    /**
     * Identifica qual objete é
     */
    bool Bullet::Is( std::string type )
    {
		return ( type == "Bullet" )? true : false;
    }


	/**
	 * Verifica se distancia max foi percorrida
	 */
	bool Bullet::IsDead()
	{
		return ( 0 >= this->distanceLeft )? true : false;
	}
/* FIM - CLASSE BULLET*/
} // Objects
