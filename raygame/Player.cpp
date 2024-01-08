#include "Player.h"



Player::Player(float health, float x, float y, const char* name) : Actor(x, y, name)
{

}

void Player::start()
{
	m_moveComponent = (MoveComponent*)this->addComponent(new MoveComponent(100, this));
	//m_inputComponent = (InputComponent*)this->addComponent(new InputComponent(100, this));
	

}

void Player::draw()
{
}

void Player::update(float deltaTime)
{

}
