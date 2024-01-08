#pragma once
#include "Component.h"
#include <Vector2.h>

class InputComponent :
    public Component
{
public:
    
    MathLibrary::Vector2 getMoveAxis();

    bool getSpacePress();

    void Update(float deltaTime);

private:
    
    
};

