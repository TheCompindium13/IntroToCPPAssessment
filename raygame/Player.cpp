#include "Player.h"
#include "Enemy.h"


Player::Player(float health, float x, float y, const char* name) : Actor(x, y, name)
{
	health = m_health;
	x = position.x;
	y = position.y;
}
void Player::update(float deltaTime)
{
	Actor::update(deltaTime);
	//This set of if statements wraps the player icon around to the other side
    //------------------------------------------------------------------------
	if (this->getTransform()->getLocalPosition().x >= 800)
	{
		this->getTransform()->setLocalPosition(MathLibrary::Vector2(50, this->getTransform()->getLocalPosition().y));
	}
	else if (this->getTransform()->getLocalPosition().x <= 0)
	{
		this->getTransform()->setLocalPosition(MathLibrary::Vector2(799, this->getTransform()->getLocalPosition().y));
	}
	if (this->getTransform()->getLocalPosition().y >= 700)
	{
		this->getTransform()->setLocalPosition(MathLibrary::Vector2(this->getTransform()->getLocalPosition().x, 50));
	}
	else if (this->getTransform()->getLocalPosition().y <= 0)
	{
		this->getTransform()->setLocalPosition(MathLibrary::Vector2(this->getTransform()->getLocalPosition().x, 699));
	}
	//------------------------------------------------------------------------
}
void Player::start()
{
	float radius = getTransform()->getScale().x;
	m_playercollider = (CircleCollider*)(new CircleCollider(50, this));
	setCollider(m_playercollider);
    sprite = (SpriteComponent*)(this->addComponent(new SpriteComponent(this, "Images/player.png")));
	if (getCollider() != m_playercollider)
	{
		return;
	}
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
	//DrawLine(position.x, position.y, m_playercollider->getOwner()->getTransform()->getLocalPosition().x + Facing.x * 10, m_playercollider->getOwner()->getTransform()->getLocalPosition().y + Facing.y * 100, RED);
	position = getTransform()->getLocalPosition();


}


