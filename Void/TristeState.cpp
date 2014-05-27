#include "TristeState.hpp"

namespace States{

	/* CONSTRUTOR */
	TristeState::TristeState()
	{
		//carrega tileMap
		//carrega sprites
		//-> Player
		//-> Irma
		//-> Enemy
		//-> Notes
		//-> Pagina
		//cria lista de pos aleatorias
		//carrega musica
		//carrega sfx
	}


	TristeState::~TristeState()
	{
	}

	/* METODOS */
	void Update(float dt)
	{
		//atualiza pos do jogador
		//atualiza pos dos enemies
		//atualiza pos da irma
		
		//check colis�o player/enemy
		//	true: desempilha TristeStage
		//		  jogar perdeu
		//se n�o
		//	check colisao de player/notes
		//		true: deleta nota
		//			  se possui notas ainda
		//				cria nova nota musical
		//				cria novo inimigo
		//			  se n�o
		//				desempilha fase
		//				jogador venceu
		//	check colis�o player/irma
		//		true: slowdown in enemies
		//			  set clock 3 seg.
		//
	}

	void Render()
	{
		//renderiza layer 1
		//for npc[i], i=1:end
		//	se player->box.y > enemy[i]->box.y
		//		call player->Render
		//		call enemy->Render
		//	sen�o
		//		call enemy->Render
		//		call player->Render
	}

}
