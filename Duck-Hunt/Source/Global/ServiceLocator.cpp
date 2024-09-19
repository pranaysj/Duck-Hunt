#pragma once
#include "../../Header/Global/ServiceLocator.h"

namespace Global {
	ServiceLocator::ServiceLocator()
	{
		graphicsService = nullptr;
		eventService = nullptr;
		timeService = nullptr;
		enemySevice = nullptr;
		CreateService();
	}

	void ServiceLocator::CreateService()
	{
		graphicsService = new Graphics::GraphicService();
		eventService = new Event::EventService();
		timeService = new Time::TimeService();
		enemySevice = new Enemy::EnemyService();
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
		enemySevice->Initialize();
	}

	void ServiceLocator::Update()
	{
		graphicsService->Update();
		eventService->Update();
		timeService->Update();
		enemySevice->Update();
	}

	void ServiceLocator::Render()
	{
		graphicsService->Render();
		eventService->Render();
		enemySevice->Render();
	}

	Graphics::GraphicService* ServiceLocator::GetGraphicsService()
	{
		return graphicsService;
	}

	Event::EventService* ServiceLocator::GetEventService()
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
}
