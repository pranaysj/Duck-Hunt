#pragma once
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Enemy {
	EnemyController::EnemyController()
	{
		enemyModel = new Enemy::EnemyModel();
		enemyView = new Enemy::EnemyView();
	}

	EnemyController::~EnemyController()
	{
		Destroy();
	}

	void EnemyController::Initialize()
	{
		enemyModel->Initialize();
		//enemyModel->SetEnemyPositon(GetRandomInitialPosition());
		enemyView->Initialize(this);
	}

	void EnemyController::Move()
	{

	}

	sf::Vector2f EnemyController::GetRandomInitialPosition()
	{
		float x_offset_distance = (std::rand() % static_cast<int>(enemyModel->rightMostPosition.x - enemyModel->leftMostPosition.x));

		float x_position = enemyModel->leftMostPosition.x + x_offset_distance;

		float y_position = enemyModel->leftMostPosition.y;

		return sf::Vector2f(x_position, y_position);
	}

	void EnemyController::Update()
	{
		enemyView->Update();
	}

	void EnemyController::Render()
	{
		enemyView->Render();
	}

	sf::Vector2f EnemyController::GetEnemyPosition()
	{
		return enemyModel->GetEnemyPositon();

	}

	void EnemyController::Destroy()
	{
		delete(enemyModel);
		delete(enemyView);
	}

	//void EnemyController::UpdateFireTimer()
	//{
	//	elapsedFireDuration += Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

	//}

	//void EnemyController::ProcessBulletFire()
	//{
	//	if (elapsedFireDuration >= rateOfFire)
	//	{
	//		FireBullet();
	//		elapsedFireDuration = 0.f; //set elapsed duration back to 0.
	//	}
	//}
}

