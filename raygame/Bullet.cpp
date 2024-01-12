#include "Bullet.h"
#include "Transform2D.h"
#include "raylib.h"
#include "Engine.h"

Bullet::Bullet(float x, float y, Actor* owner, MathLibrary::Vector2 velocity, const char* name) : Actor(owner, "Bullet")
{
    m_owner = owner;
    m_velocity = velocity;
    m_position.x = x;
    m_position.y = y;

    m_bulletCollider = new CircleCollider(20, this);
}

void Bullet::update(float deltaTime)
{
    Actor::update(deltaTime);
    this->getTransform()->setLocalPosition(m_velocity * deltaTime);
    m_currentTime = m_currentTime + deltaTime;

    if (m_currentTime >= 5)
    {
        Engine::destroy(m_owner);
    }
}

void Bullet::Draw()
{
    Actor::draw();
    m_position = getTransform()->getLocalPosition();
    float radius = getTransform()->getScale().x;
    DrawCircle(m_position.x, m_position.y, 25, BLUE);
}

void Bullet::onCollision(Actor* other)
{
    if (other == m_owner)
    {
        return;
    }

    Actor::onCollision(other);
}
