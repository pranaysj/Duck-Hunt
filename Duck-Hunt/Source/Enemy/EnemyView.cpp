#pragma once
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Enemy {
	EnemyView::EnemyView() { }

	EnemyView::~EnemyView() { }

	void EnemyView::Initialize(EnemyController* _controller)
	{
		enemyController = _controller;
		gameWindow = Global::ServiceLocator::GetInstance()->GetGraphicsService()->GetGameWindow();
		InitializeImage();
	}

	void EnemyView::InitializeImage()
	{
		if (enemyTexture.loadFromFile(enemyTexturePath)) {
			enemySprite.setTexture(enemyTexture);
		}
	}

	void EnemyView::Update()
	{
		enemySprite.setPosition(enemyController->GetEnemyPosition());
	}

	void EnemyView::Render()
	{
		gameWindow->draw(enemySprite);
	}
}