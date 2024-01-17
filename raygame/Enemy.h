#pragma once
#include "Actor.h"
#include "MoveComponent.h"
#include "CircleCollider.h"
#include "SpriteComponent.h"
class Enemy :
    public Actor
{

/// <param name="target">Who the enemy follows</param>
/// <param name="position">enemies starting x and y position</param>
public:
    Enemy(Actor* target, float x,float y);
    Enemy();
    Enemy(MathLibrary::Vector2 position);

    void start() override;
    void draw() override;
    void update(float deltaTime) override;
private:
    Actor* m_target;
    MathLibrary::Vector2 m_position;
    MoveComponent* m_moveComponent;
    CircleCollider* m_enemycollider;
    SpriteComponent* sprite;

};

