#pragma once
#include<SFML/Graphics.hpp>
#include"../../Header/Enemy/EnemyService.h"
#include"../../Header/Level/LevelService.h"

namespace Player {

	class EnemyService;

	class PlayerService {
	private:
		 
		sf::RenderWindow* gameWindow;
		Enemy::EnemyService* enemyService;
		Level::LevelService* levelService;

	public:
		PlayerService();
		~PlayerService();

		void Initialize();
		void Update();
		void Render();

		void ProcessButtonInteractions();
		bool Fire(sf::Sprite*, sf::Vector2f);
		bool MissFire();

	};
}