#include "SampleScene.h"
#include "SpriteComponent.h"
#include "Enemy.h"
#include "Transform2D.h"
#include "MoveComponent.h"
#include <iostream>

void SampleScene::start()
{

	//This is a better comment
	Scene::start();
	Enemy* enemy = new Enemy();
	MoveComponent* enemyMove = (MoveComponent*)enemy->addComponent(new MoveComponent(100, enemy));
	MathLibrary::Vector2 scale = MathLibrary::Vector2(50, 50);
	enemy->getTransform()->setScale(scale);
	addActor(enemy);
}

void SampleScene::end()
{
	{
		std::cout << "Congratulations! You Win!" << std::endl;
	}

	{
		std::cout << "You Lose!" << std::endl;
	}
}
