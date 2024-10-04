#pragma once
#include "../../Header/Global/ServiceLocator.h"

namespace Global {
	ServiceLocator::ServiceLocator()
	{
		graphicsService = nullptr;
		eventService = nullptr;
		timeService = nullptr;
		levelService = nullptr;
		enemySevice = nullptr;
		playerService = nullptr;
		CreateService();
	}

	void ServiceLocator::CreateService()
	{
		graphicsService = new Graphics::GraphicService();
		eventService = new Event::EventsService();
		timeService = new Time::TimeService();
		levelService = new Level::LevelService();
		enemySevice = new Enemy::EnemyService();
		playerService = new Player::PlayerService();
	}

	ServiceLocator::~ServiceLocator()
	{
	}

	ServiceLocator* ServiceLocator::GetInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	void ServiceLocator::ClearAllService()
	{
	}

	void ServiceLocator::Initialize()
	{
		graphicsService->Initialize();
		eventService->Initialize();
		timeService->Initialize();
		levelService->Initialize();
		enemySevice->Initialize();
		playerService->Initialize();
	}

	void ServiceLocator::Update()
	{
		graphicsService->Update();
		eventService->Update();
		timeService->Update();
		levelService->Update();
		enemySevice->Update();
		playerService->Update();
	}

	void ServiceLocator::Render()
	{
		graphicsService->Render();
		eventService->Render();
		levelService->Render();
		enemySevice->Render();
		playerService->Render();
	}

	Graphics::GraphicService* ServiceLocator::GetGraphicsService()
	{
		return graphicsService;
	}

	Event::EventsService* ServiceLocator::GetEventService()
	{
		return eventService;
	}
	Time::TimeService* ServiceLocator::GetTimeService()
	{
		return timeService;
	}
	Enemy::EnemyService* ServiceLocator::GetEnemyService()
	{
		return enemySevice;
	}
	Level::LevelService* ServiceLocator::GetLevelService()
	{
		return levelService;
	}
	Player::PlayerService* ServiceLocator::GetPlayerService()
	{
		return playerService;
	}
}
