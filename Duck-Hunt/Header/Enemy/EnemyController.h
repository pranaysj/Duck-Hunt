#pragma once
#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy {

	class EnemyModel;
	class EnemyView;

	class EnemyController {
	protected:

		//float rateOfFire = 2.f; //we want to fire the bullet every 3 seconds
		//float elapsedFireDuration = 0.f;

		//void UpdateFireTimer();
		//void ProcessBulletFire();

		EnemyModel* enemyModel;
		EnemyView* enemyView;

		void Move();

		sf::Vector2f GetRandomInitialPosition();
		virtual void Destroy();

	public:

		EnemyController();
		~EnemyController();

		void Initialize();
		void Update();
		void Render();

		sf::Vector2f GetEnemyPosition();

	};
}