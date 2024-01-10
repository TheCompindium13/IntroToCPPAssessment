
#include "InputComponent.h"



InputComponent::InputComponent(float maxspeed, Actor* owner) : Component(owner,"InputComponent")
{
    maxspeed = m_maxSpeed;

}

void InputComponent::update(float deltaTime)
{
    Component::update(deltaTime);

    MathLibrary::Vector2 direction = MathLibrary::Vector2();
    Transform2D* jim = getOwner()->getTransform();

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
    if (RAYLIB_H::IsKeyDown(KeyboardKey::KEY_Q))
    {
        
        jim->rotate(345);
    }
    else if (RAYLIB_H::IsKeyDown(KeyboardKey::KEY_E))
    {
        jim->rotate(-345);
    }


    playerVelocity = (MoveComponent*)(getOwner()->getComponent("MoveComponent"));

    playerVelocity->setVelocity(direction.getNormalized() * 1000);
}