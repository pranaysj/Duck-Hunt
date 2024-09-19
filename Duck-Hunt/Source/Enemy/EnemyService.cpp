#pragma once
#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Enemy/EnemyController.h"


namespace Enemy {

	EnemyService::EnemyService()
	{
		std::srand(static_cast<unsigned>(std::time(nullptr)));
	}

	EnemyService::~EnemyService()
	{
		Destory();
	}

	void EnemyService::Initialize()
	{
		spwanTimer = spawnInterval;
	}

	void EnemyService::Update()
	{
		UpdateSpawnTimer();
		ProcessEnemySpawn();
		enemyController->Update();
	}


	void EnemyService::UpdateSpawnTimer()
	{
		spwanTimer += Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
	}

	void EnemyService::ProcessEnemySpawn()
	{
		if (spwanTimer >= spawnInterval) {
			SpawnEnemy();
			spwanTimer = 0;
		}
	}

	EnemyController* EnemyService::SpawnEnemy()
	{
		EnemyController* enemyController = CreateEnemy();

		enemyController->Initialize();

		return enemyController;
	}

	EnemyController* EnemyService::CreateEnemy()
	{
		return new EnemyController();
	}

	void EnemyService::Destory()
	{
		delete(enemyController);
	}

	void EnemyService::Render()
	{
		enemyController->Render();
	}

	void EnemyService::Reset()
	{
	}

}

