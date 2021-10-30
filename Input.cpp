#include "Input.h"

Input::Input()
{
	event = new SDL_Event();
}

void Input::update()
{
	SDL_PollEvent(event);

	//define inputs
	if (event->type == SDL_KEYDOWN) {
			

		switch (event->key.keysym.sym)
		{
		case SDLK_ESCAPE:
			m_KeysPressed[KEY_ESCAPE] = true;
			break;
			// Start/Pause input
		case SDLK_SPACE:
			m_KeysPressed[KEY_SPACE] = true;
			break;
			// Cash In input
		case SDLK_z:
			m_KeysPressed[KEY_Z] = true;
			break;
			// Cash Out input
		case SDLK_x:
			m_KeysPressed[KEY_X] = true;
			break;
		case SDLK_c:
			m_KeysPressed[KEY_C] = true;
			break;
		default:
			break;
		}

	}

	//else if (event->type == SDL_KEYUP)
	//{
	//	switch (event->key.keysym.sym)
	//	{
	//		// Start/Pause input
	//	case SDLK_SPACE:
	//		m_KeysPressed[KEY_SPACE] = false;
	//		break;
	//		// Cash In input
	//	case SDLK_z:
	//		m_KeysPressed[KEY_Z] = false;
	//		break;
	//		// Cash Out input
	//	case SDLK_x:
	//		m_KeysPressed[KEY_X] = false;
	//		break;
	//	default:
	//		break;
	//	}
	//}
	
}

bool Input::KeyIsPressed(KEY_PRESSED_LIST key)
{
	if (m_KeysPressed[key])
	{
		m_KeysPressed[key] = false;
		return true;
	}
	else
		return false;

}