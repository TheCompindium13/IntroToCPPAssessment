#include "SampleScene.h"
#include "SpriteComponent.h"
#include "Enemy.h"
#include "Transform2D.h"
#include "MoveComponent.h"

void SampleScene::start()
{
	//This is a better comment
	Scene::start();
	/*Enemy* enemy = new Enemy();
	MoveComponent* enemyMove = (MoveComponent*)enemy->addComponent(new MoveComponent(100, enemy));
	MathLibrary::Vector2 scale = MathLibrary::Vector2(50, 50);
	enemy->getTransform()->setScale(scale);
	addActor(enemy);*/
}
