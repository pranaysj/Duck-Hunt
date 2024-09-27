#pragma once
#include<iostream>
#include "../../Header/Level/LevelService.h"

namespace Level {
	LevelService::LevelService() {
		
	}

	LevelService::~LevelService()
	{

	}

	void LevelService::Initialize() {
		levels = 1;
		rounds = 3;
		wave = GetRound();
		ducks = 3;
		bullets = 3;
		score = 0;  

		std::cout << "level : " << levels << "\n";
		std::cout << "round : " << rounds << "\n";
		std::cout << "wave : " << wave << "\n";
		std::cout << "ducks : " << ducks << "\n";
		std::cout << "bullets : " << bullets << "\n";
		std::cout << "score : " << score << "\n";
	}

	void LevelService::Update() {
	}

	void LevelService::Render() {

	}

	void LevelService::SetLevel(int _level)
	{
		levels = _level;
	}
	int LevelService::GetLevel()
	{
		return levels;
	}

	void LevelService::SetRound(int _round)
	{
		rounds = _round;
	}
	int LevelService::GetRound()
	{
		return rounds;
	}

	void LevelService::SetDuck(int _duck)
	{
		ducks = _duck;
	}
	int LevelService::GetDuck()
	{
		return ducks;
	}

	void LevelService::SetBullet(int _bullet)
	{
		bullets = _bullet;
	}
	int LevelService::GetBullet()
	{
		return bullets;
	}

	void LevelService::SetScore(int _duck)
	{
		score = _duck;
	}
	int LevelService::GetScore()
	{
		return score;;
	}

	void LevelService::SetWave(int _wave)
	{
		wave = _wave;
	}
	int LevelService::GetWave()
	{
		return wave;
	}
}