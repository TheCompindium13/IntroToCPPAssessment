#pragma once
#include "Component.h"
class ProjectileSpawnerComponent :
    public Component
{
public:

    /// <param name="owner">Is the shooter/player that the projectile comes from.</param>
    /// <param name="damage">The amount dealt to take away from health.</param>
    /// <param name="speed">How fast a projectile goes.</param>
    ProjectileSpawnerComponent(Actor* owner, float damage, float speed);

    /// <summary>
    /// This function should hold logic that makes the bullets fire from the player.
    /// </summary>
    void fire();

private:
    Actor* m_owner;
    float m_damage;
    float m_speed;
};

