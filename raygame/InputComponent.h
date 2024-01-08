<<<<<<< Updated upstream
=======
#pragma once
#include "Component.h"
#include "MoveComponent.h"
#include "raylib.h"

class InputComponent :
    public Component
{
public:
    //InputComponent(float maxspeed, Actor owner);
    float getSpeed() { return m_maxSpeed; }
    void update(float deltaTime) override;

private:
    float m_maxSpeed;
};

>>>>>>> Stashed changes
