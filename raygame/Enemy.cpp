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
	float radius = getTransform()->getScale().x;

	m_moveComponent = (MoveComponent*)(this->addComponent(new MoveComponent(radius, this)));
	m_enemycollider = (CircleCollider*)(new CircleCollider(50, this));
	setCollider(m_enemycollider);
	if (getCollider() != m_enemycollider)
	{
		return;
	}
	
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
