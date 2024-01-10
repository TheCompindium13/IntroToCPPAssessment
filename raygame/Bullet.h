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
    Bullet(MathLibrary::Vector2 position, Actor* owner, MathLibrary::Vector2 velocity);

    void update(float deltaTime) override;

    void onCollision(Actor* other) override;

private:
    Actor* m_owner;
    float m_bulletSpeed;
    float m_currentTime;
    CircleCollider* m_bulletCollider;
    MathLibrary::Vector2 m_bulletDirection;
    MathLibrary::Vector2 m_velocity;
    MoveComponent* m_moveComponent;
    SpriteComponent* m_spriteComponent;
};

