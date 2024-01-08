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
    void update(float deltaTime) override;

private:
    float m_health;
    float m_startTime;
    float m_currentTime;
    InputComponent* m_inputComponent;
    MoveComponent* m_moveComponent;
};

