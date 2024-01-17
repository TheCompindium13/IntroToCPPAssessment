#include "ProjectileSpawnerComponent.h"
#include "Bullet.h"
#include "Transform2D.h"
#include "Engine.h"
#include "Scene.h"

/// <param name="owner">Is the shooter/player that the projectile comes from.</param>
/// <param name="damage">The amount dealt to take away from health.</param>
/// <param name="speed">How fast a projectile goes.</param>
ProjectileSpawnerComponent::ProjectileSpawnerComponent(Actor* owner, float damage, float speed) : Component(owner, "ProjectileSpawner")
{
	m_owner = owner;
	m_damage = damage;
	m_speed = speed;
}

/// <summary>
/// With this logic, we are able to fire bullets and get their velocity/position.
/// </summary>
void ProjectileSpawnerComponent::fire()
{
	MathLibrary::Vector2 velocity = m_owner->getTransform()->getForward() * m_speed;
	MathLibrary::Vector2 position = m_owner->getTransform()->getWorldPosition() + m_owner->getTransform()->getForward() * 25;

	//Adds bullets to the current scene you are in.
	Bullet* bulletInstance = new Bullet(m_owner, m_damage, velocity, position);
	Engine::getCurrentScene()->addActor(bulletInstance);
}
