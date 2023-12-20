#pragma once
#include "Actor.h"
#include "CircleCollider.h"
#include <Vector2.h>
#include "SpriteComponent.h"

class Bullet
{
public:
    

private:
    Actor* m_owner;
    float m_bulletSpeed;
    float m_currentTime;
    CircleCollider* m_bulletCollider;
    MathLibrary::Vector2 m_bulletDirection;
    SpriteComponent* m_spriteComponent;
};

