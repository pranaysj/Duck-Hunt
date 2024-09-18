#pragma once
#include"../../Header/Main/GameService.h"

namespace Main {
	GameState GameService::currentState = GameState::GAMEPLAY;

	GameService::GameService()
	{
		serviceLocator = nullptr;
	}

	GameService::~GameService()
	{
		Destory();
	}

	void GameService::Ignite()
	{
		serviceLocator = Global::ServiceLocator::GetInstance();
		Initialize();
	}

	void GameService::Initialize()
	{
		serviceLocator->Initialize();
		InitializeVariable();
	}

	void GameService::InitializeVariable()
	{
		gameWindow = serviceLocator->GetGraphicsService()->GetGameWindow();
	}

	void GameService::Update()
	{
		serviceLocator->Update();
	}

	void GameService::Render()
	{
		gameWindow->clear();
		serviceLocator->Render();
		gameWindow->display();
	}

	bool GameService::IsRunning()
	{
		return serviceLocator->GetGraphicsService()->IsGameWindowOpen();
	}

	void GameService::SetGameState(GameState _state)
	{
	}

	GameState GameService::GetGameState()
	{
		return GameState();
	}

	void GameService::Destory()
	{
		
	}





}