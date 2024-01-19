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
	//----------------------------------------------------------------------
	//The Base scale for Actors
	//----------------------------------------------------------------------
    MathLibrary::Vector2 scale = MathLibrary::Vector2(50, 50);
	//----------------------------------------------------------------------
	///The positions in the scene where each Actor begins
	//----------------------------------------------------------------------
	MathLibrary::Vector2 startLocation = MathLibrary::Vector2(500, 500);
	MathLibrary::Vector2 enemystartLocation = MathLibrary::Vector2(100, 10);
	MathLibrary::Vector2 teststartLocation = MathLibrary::Vector2(2, 2);
	//----------------------------------------------------------------------
	//Where each actor is fully declared
	//----------------------------------------------------------------------
	Player* player = new Player(100, startLocation.x, startLocation.y, "Jim");
	Enemy* enemy = new Enemy(player, enemystartLocation.x, enemystartLocation.y);
    Actor* test = new Actor(teststartLocation.x, teststartLocation.y, "test");
	//----------------------------------------------------------------------
	//Where any extra operations for the actors are run such as childing or scaling
	//----------------------------------------------------------------------
	test->getTransform()->setScale({1,1});
	test->addComponent(new SpriteComponent(test, "Images/player.png"));
	player->getTransform()->addChild(test->getTransform());
	player->getTransform()->setScale(scale);
	enemy->getTransform()->setScale({ 30,30 });
	//----------------------------------------------------------------------
	//This is where each actor is added directly in the scene
	//----------------------------------------------------------------------
	addActor(player);
	addActor(enemy);
	//----------------------------------------------------------------------
}

void SampleScene::update(float deltaTime)
{
	Scene::update(deltaTime);

	
}

