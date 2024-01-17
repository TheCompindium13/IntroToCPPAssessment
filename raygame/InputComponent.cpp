#include "InputComponent.h"
#include "Player.h"
#include "ProjectileSpawnerComponent.h"


InputComponent::InputComponent(float maxspeed, Actor* owner) : Component(owner,"InputComponent")
{
    maxspeed = m_maxSpeed;

    m_gun = new ProjectileSpawnerComponent(owner, 12, 50);
    this->getOwner()->addComponent(m_gun);
}

void InputComponent::update(float deltaTime)
{
    Component::update(deltaTime);

    MathLibrary::Vector2 direction = MathLibrary::Vector2();
    Transform2D* jim = getOwner()->getTransform();

    //------------------------------------------------------------------------------------\\
    //Adds the new vector of to direction you want to go when you press the corrasponding key.
    //------------------------------------------------------------------------------------\\

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
        
        getOwner()->getTransform()->rotate(50);

    }
    else if (RAYLIB_H::IsKeyDown(KeyboardKey::KEY_E))
    {

        getOwner()->getTransform()->rotate(.50);
    }
    //A value that can keep track of the direction to scale in. 
    float scaleDirection = 1;
    
    //If we have recieved input from the mouse wheel...
    if (RAYLIB_H::GetMouseWheelMove() != 0)
    {
        //...normalize the input to get direction.
        scaleDirection = RAYLIB_H::GetMouseWheelMove() / abs(RAYLIB_H::GetMouseWheelMove());

        //Increase the scale amount using the scale direction.
        MathLibrary::Vector2 scale = getOwner()->getTransform()->getScale() + MathLibrary::Vector2(1, 1) * scaleDirection;
        getOwner()->getTransform()->setScale(scale);
    }
    //------------------------------------------------------------------------------------\\
    //Checks the size of the player and if it is within the set paramaters increases/decreases he size of the player
    //------------------------------------------------------------------------------------\\
    

    if (RAYLIB_H::IsMouseButtonPressed(0))
    {
        m_gun->fire();
    }


    playerVelocity = (MoveComponent*)(getOwner()->getComponent("MoveComponent"));

    playerVelocity->setVelocity(direction.getNormalized() * 1000);
}