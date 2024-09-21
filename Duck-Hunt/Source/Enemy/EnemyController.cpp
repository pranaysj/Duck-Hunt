#pragma once
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Global/ServiceLocator.h"
#include<iostream>

namespace Enemy {
	EnemyController::EnemyController()
	{
		enemyModel = new Enemy::EnemyModel();
		enemyView = new Enemy::EnemyView();
	}

	EnemyController::~EnemyController()
	{
		delete(enemyModel);
		delete(enemyView);
	}

	void EnemyController::Initialize()
	{
		enemyModel->Initialize();

		enemyView->Initialize(this);
		moveTimer = moveInterval;
		
	}

	void EnemyController::UpdateMoveTimer()
	{
		moveTimer += Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
	}

	void EnemyController::ProcessMovement()
	{
		if (moveTimer >= moveInterval) {
			directionX = GetRandomPlusOrMinus();
			directionY = GetRandomPlusOrMinus();
			moveTimer = 0;
		}
	}

	int EnemyController::GetRandomPlusOrMinus() {

		// Generate a random number
		int number = rand() % 300 + 100; // Random number between 99 and 199

		//std::cout << number << endl;

		// Randomly decide if it should be positive or negative
		if (rand() % 2 == 0) {
			return number;  // Positive number
		}
		else {    
			return -number; // Negative number
		}
	}

	void EnemyController::Move()
	{
		switch (enemyModel->GetMovementDirection())
		{
		case ::Enemy::MovementDirection::LEFT:
			MoveLeft();
			break;

		case ::Enemy::MovementDirection::RIGHT:
			MoveRight();
			break;

		/*case ::Enemy::MovementDirection::UP:
			MoveUp();
			break;

		case ::Enemy::MovementDirection::DOWN:
			MoveDown();
			break;*/
		default:
			break;
		}
		
	}

	void EnemyController::MoveLeft()
	{
		sf::Vector2f currentPositoin = enemyModel->GetEnemyPositon();

		//currentPositoin.x -= Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime() * 300.0f;

		currentPositoin.y += Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime() * directionY;

		//std::cout << directionX << " " << directionY << endl;

		if (currentPositoin.y <= enemyModel->topMostPosition.y) {

			std::cout << "LEFT" << endl;
			enemyModel->SetMovementDirection(MovementDirection::RIGHT);
			enemyModel->SetEnemyPositon(currentPositoin);
		}
		else {
			enemyModel->SetEnemyPositon(currentPositoin);
		}

	}

	void EnemyController::MoveRight()
	{
		sf::Vector2f currentPositoin = enemyModel->GetEnemyPositon();

		//currentPositoin.x += Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime() * 300.0f;

		currentPositoin.y += Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime() * directionY;

		//std::cout << directionX << " " << directionY << endl;

		if (currentPositoin.y >= enemyModel->bottomtMostPosition.y) {

			std::cout << "RIGHT" << endl;
			enemyModel->SetMovementDirection(MovementDirection::LEFT);
			enemyModel->SetEnemyPositon(currentPositoin);

		}
		else {
			enemyModel->SetEnemyPositon(currentPositoin);
		}
	}

	void EnemyController::MoveUp()
	{
		sf::Vector2f currentPositoin = enemyModel->GetEnemyPositon();

		currentPositoin.x += Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime() * directionX;

		currentPositoin.y -= Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime() * directionY;

		//std::cout << directionX << " " << directionY << endl;

		if (currentPositoin.y <= enemyModel->topMostPosition.y) {
			std::cout << "UP" << endl;

			enemyModel->SetMovementDirection(MovementDirection::LEFT);
			enemyModel->SetEnemyPositon(currentPositoin);
		}
		else {
			enemyModel->SetEnemyPositon(currentPositoin);
		}
	}

	void EnemyController::MoveDown()
	{
		sf::Vector2f currentPositoin = enemyModel->GetEnemyPositon();

		currentPositoin.x += Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime() * directionX;

		currentPositoin.y += Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime() * directionY;

		//std::cout << directionX << " " << directionY << endl;

		if (currentPositoin.y >= enemyModel->bottomtMostPosition.y) {
			std::cout << "DOWN" << endl;
			enemyModel->SetMovementDirection(MovementDirection::RIGHT);
			enemyModel->SetEnemyPositon(currentPositoin);
		}
		else {
			enemyModel->SetEnemyPositon(currentPositoin);
		}
	}
	  

	void EnemyController::Update()
	{
		UpdateMoveTimer();
		ProcessMovement();
		Move();
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
}

