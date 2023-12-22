#include "SampleScene.h"
#include "SpriteComponent.h"
#include "Enemy.h"
#include "Transform2D.h"
#include "MoveComponent.h"


void SampleScene::start()
{
	//This is a better comment
	Scene::start();
	Enemy* enemy = new Enemy();
	MoveComponent* enemyMove = (MoveComponent*)enemy->addComponent(new MoveComponent(100, enemy));
	Enemy* minion = new Enemy();
	MoveComponent* minionMove = (MoveComponent*)minion->addComponent(new MoveComponent(enemyMove->getMaxSpeed(), minion));
	MathLibrary::Vector2 minionLocation = MathLibrary::Vector2(enemy->getTransform()->getWorldPosition().x+10, enemy->getTransform()->getWorldPosition().y + 10);

	MathLibrary::Vector2 scale = MathLibrary::Vector2(50, 50);
	minion->getTransform()->setLocalPosition(minionLocation);
	enemy->getTransform()->setScale(scale);
	minion->getTransform()->setScale(scale);
	enemy->getTransform()->addChild(minion->getTransform());
	addActor(minion);
	addActor(enemy);
	
}
