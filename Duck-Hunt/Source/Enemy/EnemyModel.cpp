#include "../../Header/Enemy/EnemyModel.h"

namespace Enemy {
	
	Enemy::EnemyModel::EnemyModel()
	{
	}

	EnemyModel::~EnemyModel()
	{
	}

	void EnemyModel::Initialize()
	{
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

	Vector2f EnemyModel::GetRefPositon()
	{
		return enemyStartRefPositon;
	}

	void EnemyModel::SetRefPositon(Vector2f _posiiton)
	{
		enemyStartRefPositon = _posiiton;
	}

	/*MovementDirection EnemyModel::GetMovementDirection()
	{
		return MovementDirection();
	}

	void EnemyModel::SetMovementDirection(MovementDirection _direction)
	{

	}*/
}

