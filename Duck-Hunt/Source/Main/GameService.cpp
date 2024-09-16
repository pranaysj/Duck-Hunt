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

	void GameService::Destory()
	{
		
	}

	void GameService::Initialize()
	{
	}

	void GameService::InitializeVariable()
	{
	}



}