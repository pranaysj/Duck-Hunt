#pragma once
#include "../../Header/Event/EventService.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Event {

	EventService::EventService()
	{
		gameWindow = nullptr;
	}

	EventService::~EventService()
	{
	}

	void EventService::Initialize()
	{
		gameWindow = Global::ServiceLocator::GetInstance()->GetGraphicsService()->GetGameWindow();
	}

	void EventService::ProcessEvent()
	{
		if (IsGameWindowOpen()) {

			while (gameWindow->pollEvent(gameEvent)) {

				if (GameWindowWasClosed()) {

					gameWindow->close();
				}
			}
		}
	}

	bool EventService::IsGameWindowOpen()
	{
		return gameWindow != nullptr;
	}

	bool EventService::HasQuitGame()
	{
		return false;
	}

	bool EventService::GameWindowWasClosed()
	{
		return gameEvent.type == sf::Event::Closed;
	}


	void EventService::Update()
	{
	}

	void EventService::Render()
	{
	}

}


