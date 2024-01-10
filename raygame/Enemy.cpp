#include "Enemy.h"
#include "raylib.h"
#include "Transform2D.h"


Enemy::Enemy(Actor* target)
{
	m_target = target;
}

void Enemy::start()
{
	m_moveComponent = (MoveComponent*)(this->addComponent(new MoveComponent(100, this)));



	Actor::start();
}

void Enemy::draw()
{
	Actor::draw();
	position = getTransform()->getLocalPosition();
	float radius = getTransform()->getScale().x;
	DrawCircle(position.x, position.y, 25, RED);
}

void Enemy::update(float deltaTime)
{
	Actor::update(deltaTime);
	MathLibrary::Vector2 enemytotarget = m_target->getTransform()->getLocalPosition() - getTransform()->getLocalPosition();
	MathLibrary::Vector2 direction = enemytotarget.getNormalized();
	m_moveComponent->setVelocity(direction * 100);
}
