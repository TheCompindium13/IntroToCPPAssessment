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
    Bullet(float x, float y, Actor* owner, MathLibrary::Vector2 velocity, const char* name);

    void update(float deltaTime) override;

    void Draw();

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
    MathLibrary::Vector2 m_position;
};

