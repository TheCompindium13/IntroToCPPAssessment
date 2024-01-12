#include "Player.h"



Player::Player(float health, float x, float y, const char* name) : Actor(x, y, name)
{
	health = m_health;
	x = position.x;
	y = position.y;
}

void Player::start()
{
	m_moveComponent = (MoveComponent*)(this->addComponent(new MoveComponent(500, this)));
	m_inputComponent = (InputComponent*)(this->addComponent(new InputComponent(500, this)));
	input = (InputComponent*)(getComponent("InputComponent"));
	move = (MoveComponent*)(getComponent("MoveComponent"));
	Actor::start();
}

void Player::draw()
{
	Actor::draw();
	MathLibrary::Vector2 Facing = getTransform()->getForward();
	
	DrawLine(position.x, position.y, position.x + Facing.x * 2, position.y + Facing.y * 2, RED);
	position = getTransform()->getLocalPosition();
	float radius = getTransform()->getScale().x;
	DrawCircle(position.x, position.y, radius, GREEN);
}


