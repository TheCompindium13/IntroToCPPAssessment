
#include "InputComponent.h"



InputComponent::InputComponent(float maxspeed, Actor* owner) : Component(owner,"InputComponent")
{
    maxspeed = m_maxSpeed;

}

void InputComponent::update(float deltaTime)
{
    MathLibrary::Vector2 direction = MathLibrary::Vector2();

    if (RAYLIB_H::IsKeyDown(KeyboardKey::KEY_W))
    {
        direction = direction + MathLibrary::Vector2(0, -1);
    }
    if (RAYLIB_H::IsKeyDown(KeyboardKey::KEY_S))
    {
        direction = direction + MathLibrary::Vector2(0, 1);

    }
    if (RAYLIB_H::IsKeyDown(KeyboardKey::KEY_A))
    {
        direction = direction + MathLibrary::Vector2(-1, 0);

    }
    if (RAYLIB_H::IsKeyDown(KeyboardKey::KEY_D))
    {
        direction = direction + MathLibrary::Vector2(1, 0);

    }
    if (RAYLIB_H::IsKeyDown(KeyboardKey::KEY_LEFT_SHIFT))
    {
        m_maxSpeed = 1000;
    }
    if (RAYLIB_H::IsKeyDown(KeyboardKey::KEY_Q))
    {
        getOwner()->getTransform()->rotate(10);
    }
    else if (RAYLIB_H::IsKeyDown(KeyboardKey::KEY_E))
    {
        getOwner()->getTransform()->rotate(-10);
    }
    else
    {
        m_maxSpeed = 100;
    }

    playerVelocity = (MoveComponent*)(getOwner()->getComponent("MoveComponent"));

    playerVelocity->setVelocity(direction.getNormalized() * 100);
}