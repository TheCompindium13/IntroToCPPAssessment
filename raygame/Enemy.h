#pragma once
#include "Actor.h"
#include "MoveComponent.h"
class Enemy :
    public Actor
{
public:
    Enemy(Actor* target);
    Enemy();
    void start() override;
    void draw() override;
    void update(float deltaTime) override;
private:
    Actor* m_target;
    MathLibrary::Vector2 position;
    MoveComponent* m_moveComponent;
};

