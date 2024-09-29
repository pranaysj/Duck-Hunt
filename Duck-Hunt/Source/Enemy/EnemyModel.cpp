#pragma once
#include "../../Header/Enemy/EnemyModel.h"
#include<iostream>

namespace Enemy {
	Enemy::EnemyModel::EnemyModel() { }

	EnemyModel::~EnemyModel() { }

	void EnemyModel::Initialize()
	{
		//std::srand(static_cast<unsigned>(std::time(nullptr)));

		moveDirection = MovementDirection::RIGHT;
		float randomPos = 200 + rand() % 500;
		//std::cout << randomPos << "\n";
		enemyCurrentPositon = enemyStartRefPositon + sf::Vector2f(randomPos, 0.0f); 
	}

	Vector2f EnemyModel::GetEnemyPositon()
	{
		return enemyCurrentPositon;
	}

	void EnemyModel::SetEnemyPositon(Vector2f _posiiton)
	{
		enemyCurrentPositon = _posiiton;
	}

	MovementDirection EnemyModel::GetMovementDirection()
	{
		return moveDirection;
	}

	void EnemyModel::SetMovementDirection(MovementDirection _direction)
	{
		moveDirection = _direction;
	}

	
}

