#pragma once
#include "Actor.h"
#include "CircleCollider.h"
#include "MoveComponent.h"
#include "InputComponent.h"
#include "SpriteComponent.h"
class Player :
    public Actor
    
{

/// <param name="health">How many times the player can be shot</param>
/// <param name="x">the players position locally on the x-axis</param>
/// <param name="y">the players position locally on the y-axis</param>
/// <param name="name"> The name is used to identify the player on screen</param>
public:

    Player(float health, float x, float y, const char* name);


    void start() override;
    void draw() override;
    void update(float deltaTime) override;

private:
    float m_health;
    float m_startTime;
    float m_currentTime;
    CircleCollider* m_playercollider;
    MathLibrary::Vector2 position;
    InputComponent* input;
    InputComponent* m_inputComponent;
    MoveComponent* m_moveComponent;
    MoveComponent* move;
    SpriteComponent* sprite;

};

