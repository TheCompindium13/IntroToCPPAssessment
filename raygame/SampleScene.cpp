#include "SampleScene.h"
#include "SpriteComponent.h"
#include "Enemy.h"
#include "Transform2D.h"

#include "Player.h"

void SampleScene::start()
{

	//This is a better comment
	Scene::start();
    MathLibrary::Vector2 scale = MathLibrary::Vector2(50, 50);
	
	MathLibrary::Vector2 startLocatiom = MathLibrary::Vector2(500, 500);
	Player* player = new Player(100, startLocatiom.x, startLocatiom.y, "Jim");


	player->getTransform()->setScale(scale);
	addActor(player);
	Enemy* enemy = new Enemy(player);
	enemy->getTransform()->setScale(scale);
	addActor(enemy);
	
	
}
