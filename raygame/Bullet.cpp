#include "Bullet.h"
#include "Transform2D.h"
#include "raylib.h"
#include "Engine.h"
#include "MoveComponent.h"

/// <param name="x">One of bullet's coordinates on the x-axis.</param>
/// <param name="y">One of bullet's coordinates on the y-axis.</param>
/// <param name="owner">Set the owner of the bullets.</param>
/// <param name="velocity">The speed in which the bullet goes.</param>
/// <param name="name">The name of the bullet.</param>
Bullet::Bullet(Actor* shooter, float damage, MathLibrary::Vector2 velocity, MathLibrary::Vector2 position)
{
    m_shooter = shooter;
    m_damage = damage;

    MoveComponent* moveComponent = new MoveComponent(100, this);
    addComponent(moveComponent);

    SpriteComponent* sprite = new SpriteComponent(this, "Images/bullet.png");
    addComponent(sprite);

    moveComponent->setVelocity(velocity);
    getTransform()->setLocalPosition(position);
    getTransform()->setScale({ 50,50 });
    CircleCollider* m_bulletcollider = (CircleCollider*)(new CircleCollider(23, this));
    setCollider(m_bulletcollider);

}

/// <summary>
/// The screen updates to destroy a bullet at a certain amount of time.
/// </summary>
/// <param name="deltaTime">The time it takes to complete a frame.</param>
void Bullet::update(float deltaTime)
{
    Actor::update(deltaTime);

    m_currentTime += deltaTime;

    if (m_currentTime >= m_despawnDelay)
    {
        Engine::destroy(this);
    }
}

/// <summary>
/// Should be collision with any actor.
/// </summary>
/// <param name="other">As in other game objects/actors.</param>
void Bullet::onCollision(Actor* other)
{
    //The player doesn't defeat himself.
    if (other == m_shooter)
    {
        return;
    }

    Engine::destroy(other);
}
