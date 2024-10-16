#pragma once
#include "../../Header/Enemy/EnemyModel.h"
#include<iostream>
#include <cstdlib> // For srand() and rand()

#include<ctime>
#include<random>


namespace Enemy {
	Enemy::EnemyModel::EnemyModel() { }

	EnemyModel::~EnemyModel() { }

	void EnemyModel::Initialize()
	{
		float randomPosX = 100 + rand() % 1600;
		float randomPosY = 600 + rand() % 200;

		moveDirection = MovementDirection::RIGHT;

		//std::cout << "X : " << randomPosX ;
		//std::cout << "  Y : " << randomPosY << "\n";
		enemyCurrentPositon = sf::Vector2f(randomPosX, randomPosY); 
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

