#pragma once
#include "Actor.h"
#include <Vector2.h>

class ProjectileSpawner :
    public Actor
{
public:
    ProjectileSpawner(Actor owner, MathLibrary::Vector2 position, float projectileSpeed, const char* projectileSpritePath);

    void spawnProjectile();

private:
    Actor m_owner;
    float m_projectileSpeed;
    const char* m_projectileSpritePath;
};

