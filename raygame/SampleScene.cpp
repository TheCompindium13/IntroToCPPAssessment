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
	MathLibrary::Vector2 wallstartLocation = MathLibrary::Vector2(30, 110);


	player = new Player(100, startLocation.x, startLocation.y, "Jim");

	Player* body = new Player(100, startLocation.x, startLocation.y, "body");
	body->getTransform()->setScale(scale);
	player->getTransform()->setScale(scale);
	player->getTransform()->addChild(body->getTransform());

	addActor(body);
	addActor(player);
	enemy = new Enemy(player, enemystartLocation.x, enemystartLocation.y);
	
	
	enemy->getTransform()->setScale({ 30,30 });


	addActor(enemy);
	
	
}

void SampleScene::update(float deltaTime)
{
	Scene::update(deltaTime);
}




