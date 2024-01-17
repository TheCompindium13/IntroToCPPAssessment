#include "ProjectileSpawnerComponent.h"
#include "Bullet.h"
#include "Transform2D.h"
#include "Engine.h"
#include "Scene.h"

ProjectileSpawnerComponent::ProjectileSpawnerComponent(Actor* owner, float damage, float speed) : Component(owner, "ProjectileSpawner")
{
	m_owner = owner;
	m_damage = damage;
	m_speed = speed;
}

void ProjectileSpawnerComponent::fire()
{
	MathLibrary::Vector2 velocity = m_owner->getTransform()->getForward() * m_speed;
	MathLibrary::Vector2 position = m_owner->getTransform()->getWorldPosition() + m_owner->getTransform()->getForward() * 25;

	Bullet* bulletInstance = new Bullet(m_owner, m_damage, velocity, position);
	Engine::getCurrentScene()->addActor(bulletInstance);
}
