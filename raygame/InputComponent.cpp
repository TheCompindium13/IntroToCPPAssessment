
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
    if (RAYLIB_H::IsKeyPressed(KeyboardKey::KEY_Q))
    {
        
        //getOwner()->getTransform()->scale({2,2});
        getOwner()->getTransform()->rotate(50);
    }
    else if (RAYLIB_H::IsKeyPressed(KeyboardKey::KEY_E))
    {
        getOwner()->getTransform()->scale({ .5,.5 });
    }


    playerVelocity = (MoveComponent*)(getOwner()->getComponent("MoveComponent"));

    playerVelocity->setVelocity(direction.getNormalized() * 1000);
}