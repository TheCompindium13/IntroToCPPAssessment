#include "SampleScene.h"
#include "SpriteComponent.h"
#include "Enemy.h"
#include "Transform2D.h"
#include "CircleCollider.h"
#include "Engine.h"
#include "Bullet.h"


void SampleScene::start()
{

	//This is a better comment
	Scene::start();
    MathLibrary::Vector2 scale = MathLibrary::Vector2(50, 50);
	
	MathLibrary::Vector2 startLocation = MathLibrary::Vector2(500, 500);
	MathLibrary::Vector2 enemystartLocation = MathLibrary::Vector2(100, 10);
	MathLibrary::Vector2 teststartLocation = MathLibrary::Vector2(2, 2);


	player = new Player(100, startLocation.x, startLocation.y, "Jim");

	Actor* test = new Actor(teststartLocation.x, teststartLocation.y, "test");
	test->getTransform()->setScale({1,1});
	player->getTransform()->setScale(scale);
	test->addComponent(new SpriteComponent(test, "Images/player.png"));
	player->getTransform()->addChild(test->getTransform());

	addActor(player);
	enemy = new Enemy(player, enemystartLocation.x, enemystartLocation.y);
	
	
	enemy->getTransform()->setScale({ 30,30 });


	addActor(enemy);

}

void SampleScene::update(float deltaTime)
{
	Scene::update(deltaTime);

	
}

