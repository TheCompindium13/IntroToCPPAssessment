#include "Bullet.h"
#include "Transform2D.h"

void Bullet::update(float deltaTime)
{
    
}

void Bullet::onCollision(Actor* other)
{
    if (other == m_owner)
    {
        return;
    }
}
