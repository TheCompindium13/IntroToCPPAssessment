<<<<<<< Updated upstream
=======
#include "InputComponent.h"
#include "MoveComponent.h"

#include "Player.h"

//InputComponent::InputComponent(float maxspeed, Actor owner)
//{
//    maxspeed = m_maxSpeed;
//}

void InputComponent::update(float deltaTime)
{
    MathLibrary::Vector2 direction = MathLibrary::Vector2();

    if (RAYLIB_H::IsKeyDown(KeyboardKey::KEY_A))
    {
        direction = direction + MathLibrary::Vector2(-1, 0);
    }
    MoveComponent* playervelocity = (MoveComponent*)this->getOwner()->getComponent("MoveComponent");

    
}
>>>>>>> Stashed changes
