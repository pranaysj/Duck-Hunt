#pragma once
#include<SFML/Graphics.hpp>

namespace Enemy {
	using namespace sf;

	enum class MovementDirection {
		LEFT,
		RIGHT,
		UP,
		DOWN,
	};

	class EnemyModel {
	private:
		MovementDirection moveDirection;

		Vector2f enemyStartRefPositon = Vector2f(960.0f, 540.0f);
		Vector2f enemyCurrentPositon;
		
	public:

		const Vector2f leftMostPosition = Vector2f(10.0f, 50.0f);
		const Vector2f rightMostPosition = Vector2f(1800.0f, 50.0f);
		const Vector2f topMostPosition = Vector2f(0.0f, 10.0f);
		const Vector2f bottomtMostPosition = Vector2f(0.0f, 800.0f);

		EnemyModel();
		~EnemyModel();

		void Initialize();

		Vector2f GetEnemyPositon();
		void SetEnemyPositon(Vector2f _posiiton);

		Enemy::MovementDirection GetMovementDirection();
		void SetMovementDirection(MovementDirection _direction);

	};
}