#pragma once
#include "../../Header/Event/EventsService.h"
#include "../../Header/Global/ServiceLocator.h"
#include <iostream>

namespace Event {

	EventsService::EventsService()
	{
		gameWindow = nullptr;
	}

	EventsService::~EventsService()
	{
	}

	void EventsService::Initialize()
	{
		gameWindow = Global::ServiceLocator::GetInstance()->GetGraphicsService()->GetGameWindow();
	}

	void EventsService::ProcessEvent()
	{
		if (IsGameWindowOpen()) {

			while (gameWindow->pollEvent(gameEvent)) {

				if (GameWindowWasClosed()) {

					gameWindow->close();
				}
			}
		}
	}


	bool EventsService::IsGameWindowOpen()
	{
		return gameWindow != nullptr;
	}

	bool EventsService::HasQuitGame()
	{
		return false;
	}

	bool EventsService::GameWindowWasClosed()
	{
		return gameEvent.type == sf::Event::Closed;
	}

	void EventsService::UpdateMouseButtonState(ButtonState& _currentButtonState, sf::Mouse::Button _mouseButton)
	{
		if (sf::Mouse::isButtonPressed(_mouseButton)) {
			switch (_currentButtonState)
			{
			case ButtonState::RELEASED:
				_currentButtonState = ButtonState::PRESSED;
				break;
			case ButtonState::PRESSED:
				_currentButtonState = ButtonState::HELD;
			default:
				break;
			}
		}
		else {
			_currentButtonState = ButtonState::RELEASED;
		}
	}


	bool EventsService::PressedLeftMouseButton()
	{
		return leftMouseButtonState == ButtonState::PRESSED;
	}

	void EventsService::Update()
	{
		UpdateMouseButtonState(leftMouseButtonState, sf::Mouse::Left);
	}

	void EventsService::Render()
	{
	}

}


