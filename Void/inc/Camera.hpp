#pragma once

#include "GameObject.hpp"
#include "Game.hpp"

using namespace Geometry;

namespace GameEngine {
class Camera
{
	/* ATRIBUTOS */
	public:
		static Point pos; // posicao da camera
		static float speed; // velocidade da camera
	private:
		static GameObject* focus; // objeto de foco atual da camera
		
	/* METODOS */
	public:
		/**
		 * Faz camera seguir um objeto especifico
		 * @param newFocus Ponteiro para o objeto a ser seguido
		 */
		static void Follow ( GameEngine::GameObject* newFocus );

		/**
		 * Tira objeto foco da camera
		 */
		static void Unfollow ();

		/**
		 * Atualiza posicao da camera caso não exista objeto focalizado
		 * @param dt DeltaTime
		 */
		static void Update( float dt );

};
} // GameEngine
