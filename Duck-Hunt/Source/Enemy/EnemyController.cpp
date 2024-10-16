#pragma once
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Event/EventsService.h"
#include<iostream>

namespace Enemy {


	using namespace Event;

	EnemyController::EnemyController()
	{
		enemyModel = new Enemy::EnemyModel();
		enemyView = new Enemy::EnemyView();
		gameWindow = nullptr;

	}

	EnemyController::~EnemyController()
	{
		delete(enemyModel);
		delete(enemyView);
		delete(gameWindow);
	}

	void EnemyController::Initialize()
	{
		enemyModel->Initialize();

		enemyView->Initialize(this);
		moveTimer = moveInterval;

		gameWindow = Global::ServiceLocator::GetInstance()->GetGraphicsService()->GetGameWindow();
		std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed the random number generator

	}

	void EnemyController::Update()
	{
		UpdateMoveTimer();
		ProcessMovement();
		Move();
		enemyView->Update();
		//ProcessButtonInteractions();
		
	}

	void EnemyController::UpdateMoveTimer()
	{
		moveTimer += Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
	}

	void EnemyController::ProcessMovement()
	{
		//std::srand(static_cast<unsigned>(std::time(nullptr)));
		if (moveTimer >= moveInterval) {
			directionX = GetRandomPlusOrMinus();
			directionY = GetRandomPlusOrMinus();
			moveTimer = 0;
		}
	}

	int EnemyController::GetRandomPlusOrMinus() {

		int number = 150 + rand() % 201; // Random number between 150 and 350
		return (rand() % 2 == 0) ? number : -number;
	}

	void EnemyController::Move()
	{
		sf::Vector2f currentPositoin = enemyModel->GetEnemyPositon();
		float deltaTime = Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

		currentPositoin.x += deltaTime * directionX;
		currentPositoin.y += deltaTime * directionY;

		// Check boundaries and change direction if necessary
		if (currentPositoin.x <= enemyModel->leftMostPosition.x || currentPositoin.x >= enemyModel->rightMostPosition.x) {
			directionX = -directionX;
		}

		if (currentPositoin.y <= enemyModel->topMostPosition.y || currentPositoin.y >= enemyModel->bottomtMostPosition.y) {
			directionY = -directionY;
		}

		enemyModel->SetEnemyPositon(currentPositoin);
	}

	void EnemyController::MoveLeft()
	{
		sf::Vector2f currentPositoin = enemyModel->GetEnemyPositon();

		currentPositoin.x -= Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime() * directionX;

		//currentPositoin.y += Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime() * directionY;

		//std::cout << directionX << " " << directionY << endl;

		if (currentPositoin.x <= enemyModel->leftMostPosition.x) {

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

		currentPositoin.x += Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime() * directionX;

		//currentPositoin.y += Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime() * directionY;

		//std::cout << directionX << " " << directionY << endl;

		if (currentPositoin.x >= enemyModel->rightMostPosition.x) {

			std::cout << "RIGHT" << endl;
			enemyModel->SetMovementDirection(MovementDirection::LEFT);
			enemyModel->SetEnemyPositon(currentPositoin);

		}
		else {
			enemyModel->SetEnemyPositon(currentPositoin);
		}
	}

	//void EnemyController::MoveUp()
	//{
	//	sf::Vector2f currentPositoin = enemyModel->GetEnemyPositon();

	//	//currentPositoin.x += Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime() * directionX;

	//	currentPositoin.y -= Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime() * 300.0f;

	//	//std::cout << currentPositoin.y  << endl;

	//	if (currentPositoin.y <= enemyModel->topMostPosition.y) {
	//		std::cout << "UP" << endl;

	//		enemyModel->SetMovementDirection(MovementDirection::DOWN);
	//		enemyModel->SetEnemyPositon(currentPositoin);
	//	}
	//	else {
	//		enemyModel->SetEnemyPositon(currentPositoin);
	//	}
	//}

	//void EnemyController::MoveDown()
	//{
	//	sf::Vector2f currentPositoin = enemyModel->GetEnemyPositon();

	//	//currentPositoin.x += Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime() * directionX;

	//	currentPositoin.y += Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime() * 300.0f;

	//	//std::cout << directionX << " " << directionY << endl;

	//	if (currentPositoin.y >= enemyModel->bottomtMostPosition.y) {
	//		std::cout << "DOWN" << endl;
	//		enemyModel->SetMovementDirection(MovementDirection::UP);
	//		enemyModel->SetEnemyPositon(currentPositoin);
	//	}
	//	else {
	//		enemyModel->SetEnemyPositon(currentPositoin);
	//	}
	//}
	  


	void EnemyController::Render()
	{
		enemyView->Render();
	}

	sf::Vector2f EnemyController::GetEnemyPosition()
	{
		return enemyModel->GetEnemyPositon();

	}

	sf::Sprite* EnemyController::GetEnemySprite()
	{
		return enemyView->GetEnemySprite();
	}
}
 
