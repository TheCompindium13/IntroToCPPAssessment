#include "Enemy.h"
#include "raylib.h"
#include "Transform2D.h"
#include "Engine.h"

/// <param name="target">The Actor/Player that the enemy is going to follow.</param>
/// <param name="x">The enemy coordinate on the x-axis.</param>
/// <param name="y">The enemy coordinate on the y-axis.</param>
Enemy::Enemy(Actor* target, float x, float y)
{
	m_target = target;
	m_position.x = x;
	m_position.y = y;
}

/// <summary>
/// Once the enemy is defeated, text will appear to signal game over. Then close the game by pressing the key it tells you to press.
/// </summary>
void Enemy::onDestroy()
{
	Actor::onDestroy();

	m_text = new TextBox("Game Over! Press escape to close the game.", 50, 50, "Game Over");
	
	Engine::CloseApplication();
}

/// <summary>
/// How the enemy will start off.
/// </summary>
void Enemy::start()
{
	//Create the enemy's image.
	float radius = getTransform()->getScale().x;
	sprite = (SpriteComponent*)(this->addComponent(new SpriteComponent(this, "Images/enemy.png")));

	//Make the enemy move.
	m_moveComponent = (MoveComponent*)(this->addComponent(new MoveComponent(radius, this)));
    //Give enemy a collider and set its size.
	m_enemycollider = (CircleCollider*)(new CircleCollider(50, this));
	setCollider(m_enemycollider);
	if (getCollider() != m_enemycollider)
	{
		return;
	}
	
	Actor::start();
}

/// <summary>
/// Draw the enemy to the screen.
/// </summary>
void Enemy::draw()
{
	Actor::draw();

}

/// <summary>
/// Update the enemy while the game continues.
/// </summary>
/// <param name="deltaTime">The time it takes to complete a frame.</param>
void Enemy::update(float deltaTime)
{
	Actor::update(deltaTime);
	//Make the enemy know where its target/player is.
	MathLibrary::Vector2 enemytotarget = m_target->getTransform()->getLocalPosition() - getTransform()->getLocalPosition();
	//Give the enemy direction.
	MathLibrary::Vector2 direction = enemytotarget.getNormalized();
	m_moveComponent->setVelocity(direction * 100);

	
}
