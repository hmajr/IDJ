#pragma once
#include "GameObject.hpp"
#include "Sprite.hpp"

using namespace GameEngine;

namespace Objects{
class Note : public GameObject
{
	/* CONSTANTES */
	std::string m_NOTA_PATH = "./img/note.png";
	const int m_TILE_WIDTH = 67;
	const int m_TILE_HEIGHT = 80;
	/* ATRIBUTOS */
	private:
		bool collected;
		Sprite sprite;
	/* CONSTRUTOR */
	public:
		Note(float initX, float initY);
		~Note();

	/* METODOS */
	public:
		void Update(float dt);
		void Render();

		/**
		* Notifica colisão com objetos
		*/
		virtual void NotifyCollision(GameObject& other);

		/**
		* Identifica qual objete é
		*/
		virtual bool Is(std::string type);

		/**
		* Defini o gameobject como morto(ser deletado)
		*/
		virtual bool IsDead();
};
}

