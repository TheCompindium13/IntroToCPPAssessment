
#pragma once
#include "Component.h"
#include "MoveComponent.h"
#include "raylib.h"
#include "Transform2D.h"
#include <iostream>
class InputComponent :
    public Component
{
public:
    /// <param name="maxspeed">How fast ehstever is inputed will move</param>
    /// <param name="owner">the actor that uses InputComponent</param>
    InputComponent(float maxspeed, Actor* owner);
    float getSpeed() { return m_maxSpeed; }
;
    void update(float deltaTime) override;

private:
    float m_maxSpeed = 100;
    MoveComponent* playerVelocity;

};

