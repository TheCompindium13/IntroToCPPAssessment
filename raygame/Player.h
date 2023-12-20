#pragma once
#include "Actor.h"

class Player :
    public Actor
{
    float m_health;   

public:
    void draw() override;
    
};

