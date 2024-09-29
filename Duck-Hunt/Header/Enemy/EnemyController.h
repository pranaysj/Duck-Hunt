#pragma once
#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy {

	class EnemyModel;
	class EnemyView;

	class EnemyController {
	protected:
;
		const float moveInterval = 2.0f;
		float moveTimer;

		int directionX;
		int directionY;

		EnemyModel* enemyModel;
		EnemyView* enemyView;
		sf::RenderWindow* gameWindow;

		void UpdateMoveTimer();
		void ProcessMovement();

	public:

		EnemyController();
		~EnemyController();

		sf::Vector2f EnemyVelocity();

		int GetRandomPlusOrMinus();
		void Move();
		void MoveLeft();
		void MoveRight();
		void MoveUp();
		void MoveDown();

		void Initialize();
		void Update();
		void Render();

		sf::Vector2f GetEnemyPosition();
		sf::Sprite* GetEnemySprite();
	};
}