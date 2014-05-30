#include "TristeEnemy.hpp"

namespace Objects
{
	TristeEnemy::TristeEnemies()
	{
	}


	TristeEnemy::~TristeEnemies()
	{
	}

	void TristeEnemy::Udate(float dt)
	{
		//atualiza direcao da velocidade
		Point pDeslocamento = pFinal - pInit; //vetor descolacamento

		this->speed.Rotate(pDeslocamento.AngEixoX(), this->magSpeed);

		//atualiza posicao;
		this->box.x += this->speed.x * dt;
		this->box.y += this->speed.y * dt;
	}
}

