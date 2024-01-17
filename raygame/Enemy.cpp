#include "Enemy.h"
#include "raylib.h"
#include "Transform2D.h"


Enemy::Enemy(Actor* target, float x, float y)
{
	m_target = target;
	m_position.x = x;
	m_position.y = y;
}
void Enemy::start()
{

	m_moveComponent = (MoveComponent*)(this->addComponent(new MoveComponent(100, this)));
	m_enemycollider = (CircleCollider*)(new CircleCollider(100, this));
	setCollider(m_enemycollider);

	
	Actor::start();
}
Enemy::Enemy()
{

}
void Enemy::draw()
{
	Actor::draw();
	sprite = (SpriteComponent*)(this->addComponent(new SpriteComponent(this, "Images/enemy.png")));

}

void Enemy::update(float deltaTime)
{
	Actor::update(deltaTime);
	MathLibrary::Vector2 enemytotarget = m_target->getTransform()->getLocalPosition() - getTransform()->getLocalPosition();
	MathLibrary::Vector2 direction = enemytotarget.getNormalized();
	m_moveComponent->setVelocity(direction * 100);

}
