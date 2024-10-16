#pragma once
#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Level/LevelService.h"
#include<vector>
#include<iostream>
#include <cstdlib> // For srand() and rand()
#include <ctime>

namespace Enemy {

	EnemyService::EnemyService()
	{
		//enemyController = new Enemy::EnemyController();
		std::srand(static_cast<unsigned int>(std::time(nullptr)));

	}

	EnemyService::~EnemyService()
	{
		delete(enemyController);
	}

	void EnemyService::Initialize()
	{
		levelService = Global::ServiceLocator::GetInstance()->GetLevelService();;
		SpawnBird();
		//enemyController->Initialize();
	}

	void EnemyService::Update()
	{
		//enemyController->Update();
		for (size_t i = 0; i < birdList.size(); i++)
		{
			birdList[i]->Update();
		}
	}

	void EnemyService::Render()
	{
		//enemyController->Render();
		for (size_t i = 0; i < birdList.size(); i++)
		{
			if (birdList[i] == nullptr) {
				continue;
			}
			birdList[i]->Render();
		}
	}

	EnemyController* EnemyService::SpawnBird()
	{
		for (size_t i = 0; i < levelService->GetRound(); i++)
		{
			for (size_t j = 0; j < levelService->GetDuck(); j++)
			{
				enemyController = new Enemy::EnemyController();
				enemyController->Initialize();
				birdList.push_back(enemyController);
			}
			return enemyController;
		}
	}

	std::vector<EnemyController*> EnemyService::GetBirdList()
	{
		return birdList;
	}

	EnemyController* EnemyService::GetBirdIndex(int _i)
	{
		return birdList[_i];
	}

	void EnemyService::RemoveBird(int i)
	{
		//delete(birdList[i]);
		birdList.erase(birdList.begin() + i);
	}

}

