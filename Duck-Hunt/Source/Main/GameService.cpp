#pragma once
#include"../../Header/Main/GameService.h"
#include<iostream>

namespace Main {
	GameState GameService::currentState = GameState::GAMEPLAY;

	GameService::GameService()
	{
		serviceLocator = nullptr;
		gameWindow = nullptr;
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
		serviceLocator->GetEventService()->ProcessEvent();
		serviceLocator->Update();
	}

	void GameService::Render()
	{
		gameWindow->clear(sf::Color(1, 116, 178, 255));
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
		return currentState;
	}

	void GameService::Destory()
	{
		
	}





}