#pragma once
#include<SFML/Graphics.hpp>
#include"../../Header/Enemy/EnemyService.h"

namespace Player {

	class EnemyService;

	class PlayerService {
	private:
		 
		sf::RenderWindow* gameWindow;
		Enemy::EnemyService* enemyService;

	public:
		PlayerService();
		~PlayerService();

		void Initialize();
		void Update();
		void Render();

		void ProcessButtonInteractions();
		bool FireButton(sf::Sprite*, sf::Vector2f);
		bool MissFireButton(sf::Sprite*, sf::Vector2f);
	};
}