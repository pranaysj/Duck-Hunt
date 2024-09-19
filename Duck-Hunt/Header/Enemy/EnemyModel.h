#pragma once
#include<SFML/Graphics.hpp>

namespace Enemy {
	using namespace sf;

	enum class MovementDirection {
		LEFT,
		RIGHT,
		DOWN,
		LEFT_DOWN,
		RIGHT_DOWN,
	};

	class EnemyModel {
	private:

		Vector2f enemyStartRefPositon = Vector2f(0.0f, 0.0f);

	public:
		Vector2f enemyCurrentPositon;
		const Vector2f leftMostPosition = Vector2f(10.0f, 50.0f);
		const Vector2f rightMostPosition = Vector2f(1800.0f, 50.0f);

		//const float verticalTravelDistance = 100.f;

		EnemyModel();
		~EnemyModel();

		void Initialize();

		Vector2f GetEnemyPositon();
		void SetEnemyPositon(Vector2f _posiiton);

		Vector2f GetRefPositon();
		void SetRefPositon(Vector2f _posiiton);

		/*MovementDirection GetMovementDirection();
		void SetMovementDirection(MovementDirection _direction);*/
	};
}