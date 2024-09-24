#pragma once
#include<SFML/Graphics.hpp>

namespace Enemy {
	using namespace sf;

	class EnemyController;

	class EnemyView {
	private:

		const String enemyTexturePath = "Assets/Texture/bird.jpg";
		const float enemySpriteWidth = 70.0f;
		const float enemySpriteHeigh = 70.0f;

		EnemyController* enemyController;
		RenderWindow* gameWindow;

		Texture enemyTexture;
		Sprite enemySprite;

		void InitializeImage();

	public:
		EnemyView();
		~EnemyView();

		void Initialize(EnemyController* _controller);
		void Update();
		void Render();

		Sprite* GetEnemySprite();
	};
}