#pragma once
#include "../../Header/Player/PlayerService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Event/EventsService.h"
#include<iostream>
namespace Player {
	PlayerService::PlayerService()
	{
		gameWindow = nullptr;
		enemyService = nullptr;
	}
	PlayerService::~PlayerService()
	{

	}
	void PlayerService::Initialize()
	{
		gameWindow = Global::ServiceLocator::GetInstance()->GetGraphicsService()->GetGameWindow();
		enemyService = Global::ServiceLocator::GetInstance()->GetEnemyService();
	}

	void PlayerService::Update()
	{
		ProcessButtonInteractions();
	}
	void PlayerService::Render()
	{
	}

	void PlayerService::ProcessButtonInteractions()
	{
		sf::Vector2f mousePositon = sf::Vector2f(sf::Mouse::getPosition(*gameWindow));


		for (size_t i = 0; i < enemyService->GetBirdList().size(); i++)
		{
			Enemy::EnemyController* bird = enemyService->GetBirdList()[i];

			if (FireButton(bird->GetEnemySprite(), mousePositon)) {
				std::cout << "Kill bird" << endl;
			}
			if (MissFireButton(bird->GetEnemySprite(), mousePositon)) {
				std::cout << "Miss" << endl;
			}
		}

		/*if (FireButton(Enemy::EnemyService::birdList)) {

		}*/
	}

	bool PlayerService::FireButton(sf::Sprite* _birdSprite, sf::Vector2f _mousePosition)
	{
		Event::EventsService* eventService = Global::ServiceLocator::GetInstance()->GetEventService();
		return eventService->PressedLeftMouseButton() && _birdSprite->getGlobalBounds().contains(_mousePosition);
	}

	bool PlayerService::MissFireButton(sf::Sprite* _birdSprite, sf::Vector2f _mousePosition)
	{
		Event::EventsService* eventService = Global::ServiceLocator::GetInstance()->GetEventService();
		return eventService->PressedLeftMouseButton() && !_birdSprite->getGlobalBounds().contains(_mousePosition);
	}
}