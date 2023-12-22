#pragma once
#include "Component.h"
#include <Vector2.h>
#include "Transform2D.h"
#include "Actor.h"

class FollowComponent :
    public Component
{
public:
    void update(float deltaTime);

    MathLibrary::Vector2 GetIntendedPosition();
    void setChasee(Actor* newChasee);
private:
    Actor* m_chasee = nullptr;
};

