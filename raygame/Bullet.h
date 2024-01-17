#pragma once
#include "Actor.h"
#include "CircleCollider.h"
#include <Vector2.h>
#include "SpriteComponent.h"
#include "MoveComponent.h"

class Bullet :
    public Actor
{
public:

    /// <param name="x">One of bullet's coordinates on the x-axis.</param>
    /// <param name="y">One of bullet's coordinates on the y-axis.</param>
    /// <param name="owner">Set the owner of the bullets.</param>
    /// <param name="velocity">The speed in which the bullet goes.</param>
    /// <param name="name">The name of the bullet.</param>
    Bullet(Actor* owner, float damage, MathLibrary::Vector2 velocity, MathLibrary::Vector2 position);

    /// <summary>
    /// Makes the screen update with bullets and destroy in a certain amount of time.
    /// </summary>
    /// <param name="deltaTime">The time it takes to complete a frame.</param>
    void update(float deltaTime) override;

    /// <summary>
    /// Should be collision with any actor.
    /// </summary>
    /// <param name="other">As in other game objects/actors.</param>
    void onCollision(Actor* other) override;

private:
    Actor* m_shooter;
    float m_damage;
    float m_despawnDelay = 3.0f;
    float m_currentTime;
};

