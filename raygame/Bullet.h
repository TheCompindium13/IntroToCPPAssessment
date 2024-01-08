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
    Bullet();

    //bullet(Actor* owner, float speed, MathLibrary::Vector2 direction, const char* name = "Bullet");

    void onCollision(Actor* other) override;

private:
    Actor* m_owner;
    float m_bulletSpeed;
    float m_currentTime;
    CircleCollider* m_bulletCollider;
    MathLibrary::Vector2 m_bulletDirection;
    MoveComponent* m_moveComponent;
    SpriteComponent* m_spriteComponent;
};

