#include "ProjectileSpawner.h"
#include "Bullet.h"
#include "Transform2D.h"
#include "ActorArray.h"

ProjectileSpawner::ProjectileSpawner(Actor owner, MathLibrary::Vector2 position, float projectileSpeed, const char* projectileSpritePath)
{
	m_owner = owner;	
	m_projectileSpeed = projectileSpeed;
	m_projectileSpritePath = projectileSpritePath;
}

void ProjectileSpawner::spawnProjectile()
{
	
}
