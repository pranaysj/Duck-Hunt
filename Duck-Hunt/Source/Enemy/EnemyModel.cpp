#include "../../Header/Enemy/EnemyModel.h"

namespace Enemy {
	Enemy::EnemyModel::EnemyModel() { }

	EnemyModel::~EnemyModel() { }

	void EnemyModel::Initialize()
	{
		moveDirection = MovementDirection::UP;
		enemyCurrentPositon = enemyStartRefPositon; 
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

