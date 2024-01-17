#pragma once
#include "Component.h"
#include "MoveComponent.h"
#include "raylib.h"
#include "Transform2D.h"

class ProjectileSpawnerComponent;

class InputComponent :
    public Component
{
public:
    float getSpeed() { return m_maxSpeed; }
    InputComponent(float maxspeed, Actor* owner);
    void update(float deltaTime) override;

private:
    float m_maxSpeed = 100;
    ProjectileSpawnerComponent* m_gun;
    MoveComponent* playerVelocity;

};

