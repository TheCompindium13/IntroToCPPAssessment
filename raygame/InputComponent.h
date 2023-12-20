#pragma once
#include "Component.h"
#include <Vector2.h>
#include <Raylib.h>

class InputComponent :
    public Component
{
public:
    
    MathLibrary::Vector2 getMoveAxis();

    bool getSpacePress();

    void Update(float deltaTime);

private:
    
};

