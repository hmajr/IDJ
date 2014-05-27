#include "Camera.hpp"

namespace GameEngine {
// TA BUGADO T.T
Point Camera::pos(0, 0);
float Camera::speed = 200;

GameObject* Camera::focus = NULL;
/* CLASS - CAMERA */
	void Camera::Follow ( GameEngine::GameObject* newFocus )
	{
		Camera::focus = newFocus;

		// Camera::pos.x = Camera::focus->box.GetCenter().x;
  //       Camera::pos.y = Camera::focus->box.GetCenter().y;
	}

	void Camera::Unfollow ()
	{
		std::cout<< "Sem foca no objeto" << std::endl;
		Camera::focus = NULL;
	}

	void Camera::Update( float dt )
	{
		// std::cout << "Camera X: "<< pos.x << ", Y: " << pos.y << std::endl;

		if( NULL == Camera::focus )
		{
			//camera deve obedecer aos inputs do jogador
			if ( (InputManager::GetInstance()).IsKeyDown( LEFT_ARROW_KEY )) {
				pos.x += speed * dt;
			}
			else if (  (InputManager::GetInstance()).IsKeyDown( RIGHT_ARROW_KEY )) {
				pos.x -= speed * dt;
			}
			if ( (InputManager::GetInstance()).IsKeyDown( UP_ARROW_KEY )) {
				pos.y += speed * dt;
			}
			else if ( (InputManager::GetInstance()).IsKeyDown( DOWN_ARROW_KEY )) {
				pos.y -= speed * dt;
			}
		}
		else
		{	
			//objeto do foco fica centralizado na tela
            Camera::pos.x = -Camera::focus->box.GetCenter().x + SCREEN_WIDTH/2;
            Camera::pos.y = -Camera::focus->box.GetCenter().y + SCREEN_HEIGHT/2;
		}
	}
/* FIM - CAMERA */
} // GameEngine
