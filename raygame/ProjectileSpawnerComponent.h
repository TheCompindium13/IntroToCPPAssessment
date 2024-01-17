#pragma once
#include "Component.h"
class ProjectileSpawnerComponent :
    public Component
{
public:
    ProjectileSpawnerComponent(Actor* owner, float damage, float speed);

    void fire();

private:
    Actor* m_owner;
    float m_damage;
    float m_speed;
};

