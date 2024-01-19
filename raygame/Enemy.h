#pragma once
#include "Actor.h"
#include "MoveComponent.h"
#include "CircleCollider.h"
#include "SpriteComponent.h"
#include "TextBox.h"
class Enemy :
    public Actor
{


public:
    /// <param name="target">The Actor/Player that the enemy is going to follow.</param>
    /// <param name="x">The enemy coordinate on the x-axis.</param>
    /// <param name="y">The enemy coordinate on the y-axis.</param>
    Enemy(Actor* target, float x,float y);

    /// <summary>
    /// Destroy the enemy once collision with the bullet happens.
    /// </summary>
    void onDestroy() override;

    /// <summary>
    /// How the enemy will start off.
    /// </summary>
    void start() override;

    /// <summary>
    /// Draw the enemy to the screen.
    /// </summary>
    void draw() override;

    /// <summary>
    /// Update the enemy while the game continues.
    /// </summary>
    /// <param name="deltaTime">The time it takes to complete a frame.</param>
    void update(float deltaTime) override;
private:
    TextBox* m_text;
    Actor* m_target;
    MathLibrary::Vector2 m_position;
    MoveComponent* m_moveComponent;
    CircleCollider* m_enemycollider;
    SpriteComponent* sprite;

};

