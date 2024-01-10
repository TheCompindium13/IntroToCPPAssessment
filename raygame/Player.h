#pragma once
#include "Actor.h"
#include "MoveComponent.h"
#include "InputComponent.h"
class Player :
    public Actor
{
public:

    Player(float health, float x, float y, const char* name);

    void start() override;
    void draw() override;


private:
    float m_health;
    float m_startTime;
    float m_currentTime;
    MathLibrary::Vector2 position;
    InputComponent* input;
    InputComponent* m_inputComponent;
    MoveComponent* m_moveComponent;
    MoveComponent* move;

};

