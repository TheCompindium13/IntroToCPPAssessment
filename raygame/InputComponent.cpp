#include "InputComponent.h"
#include "MoveComponent.h"
#include "raylib.h"


void InputComponent::Update(float deltaTime)
{
    MathLibrary::Vector2* direction = new MathLibrary::Vector2();
    
    if (RAYLIB_H::IsKeyDown(KeyboardKey::KEY_A))
    {
        direction =+ new MathLibrary::Vector2(-1, 0);
    }

    
}
