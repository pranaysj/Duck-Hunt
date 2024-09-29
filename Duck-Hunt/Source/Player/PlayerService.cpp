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
		levelService = nullptr;
	}
	PlayerService::~PlayerService()
	{

	}
	void PlayerService::Initialize()
	{
		gameWindow = Global::ServiceLocator::GetInstance()->GetGraphicsService()->GetGameWindow();
		enemyService = Global::ServiceLocator::GetInstance()->GetEnemyService();
		levelService = Global::ServiceLocator::GetInstance()->GetLevelService();
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

		bool isBirdClicked = false;

		for (size_t i = 0; i < enemyService->GetBirdList().size(); i++)
		{
			Enemy::EnemyController* bird = enemyService->GetBirdIndex(i);

			if (Fire(bird->GetEnemySprite(), mousePositon)) {
				isBirdClicked = true;
				std::cout << "Kill bird" << endl;

				int score = levelService->GetScore();;
				levelService->SetScore(++score);
				std::cout << "Score : " << levelService->GetScore() << "\n";

				int bullet = levelService->GetBullet();
				levelService->SetBullet(--bullet);
				std::cout << "Bullet : " << levelService->GetBullet() << "\n";


				break;
			}
			
		}

		if (!isBirdClicked && MissFire()) {
			std::cout << "Miss" << "\n";
		}
	}

	bool PlayerService::Fire(sf::Sprite* _birdSprite, sf::Vector2f _mousePosition)
	{
		Event::EventsService* eventService = Global::ServiceLocator::GetInstance()->GetEventService();
		return eventService->PressedLeftMouseButton() && _birdSprite->getGlobalBounds().contains(_mousePosition);
	}

	bool PlayerService::MissFire()
	{
		Event::EventsService* eventService = Global::ServiceLocator::GetInstance()->GetEventService();
		if (eventService->PressedLeftMouseButton()) {
			return true;
		}
		return false;
	}
}