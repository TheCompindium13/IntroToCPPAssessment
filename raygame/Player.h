#pragma once
#include "Actor.h"
#include "CircleCollider.h"
#include "MoveComponent.h"
#include "InputComponent.h"
#include "SpriteComponent.h"
class Player :
    public Actor
    
{

public:

    /// <param name="health">How much points you need to be alive in the game.</param>
    /// <param name="x">The player coordinate on the x-axis.</param>
    /// <param name="y">The player coordinate on the y-axis.</param>
    /// <param name="name">The name of the player.</param>
    Player(float health, float x, float y, const char* name);

    /// <summary>
    /// How the player will start off.
    /// </summary>
    void start() override;

    /// <summary>
    /// Draw the player to the screen.
    /// </summary>
    void draw() override;

    /// <summary>
    /// Update the player while the game continues.
    /// </summary>
    /// <param name="deltaTime">The time it takes to complete a frame.</param>
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

