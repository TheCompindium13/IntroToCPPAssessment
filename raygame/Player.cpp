#include "Player.h"
#include "Enemy.h"

/// <param name="health">How much points you need to be alive in the game.</param>
/// <param name="x">The player coordinate on the x-axis.</param>
/// <param name="y">The player coordinate on the y-axis.</param>
/// <param name="name">The name of the player.</param>
Player::Player(float health, float x, float y, const char* name) : Actor(x, y, name)
{
	health = m_health;
	x = position.x;
	y = position.y;
}

/// <summary>
/// Update the enemy while the game continues.
/// </summary>
/// <param name="deltaTime">The time it takes to complete a frame.</param>
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

/// <summary>
/// Draw the player to the screen.
/// </summary>
void Player::start()
{
	float radius = getTransform()->getScale().x;
	//Give the player a collider.
	m_playercollider = (CircleCollider*)(new CircleCollider(50, this));
	setCollider(m_playercollider);
    sprite = (SpriteComponent*)(this->addComponent(new SpriteComponent(this, "Images/player.png")));
	if (getCollider() != m_playercollider)
	{
		return;
	}
	//Let the player move.
	m_moveComponent = (MoveComponent*)(this->addComponent(new MoveComponent(500, this)));
	//Give the player input.
	m_inputComponent = (InputComponent*)(this->addComponent(new InputComponent(500, this)));
	input = (InputComponent*)(getComponent("InputComponent"));
	move = (MoveComponent*)(getComponent("MoveComponent"));
	Actor::start();
}

/// <summary>
/// Draw the player to the screen.
/// </summary>
void Player::draw()
{
	
	Actor::draw();
	MathLibrary::Vector2 Facing = getTransform()->getForward();
	//Below is commented out to not show the circles from the circle collider.
	//DrawLine(position.x, position.y, m_playercollider->getOwner()->getTransform()->getLocalPosition().x + Facing.x * 10, m_playercollider->getOwner()->getTransform()->getLocalPosition().y + Facing.y * 100, RED);
	position = getTransform()->getLocalPosition();


}


