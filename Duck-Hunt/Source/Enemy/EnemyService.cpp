#pragma once
#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Enemy/EnemyController.h"

#include<iostream>

namespace Enemy {

	EnemyService::EnemyService()
	{
		enemyController = new Enemy::EnemyController();

	}

	EnemyService::~EnemyService()
	{
		delete(enemyController);
	}

	void EnemyService::Initialize()
	{
		enemyController->Initialize();
	}

	void EnemyService::Update()
	{
		enemyController->Update();
	}

	void EnemyService::Render()
	{
		enemyController->Render();
	}


}

