#include "MoveComponent.h"



MoveComponent::MoveComponent(float maxspeed, Actor* owner) : Component(owner, "MoveComponent")
{
	m_maxSpeed = maxspeed;
}


void MoveComponent::update(float deltaTime)
{
	//Store what the current position is
	MathLibrary::Vector2 position = getOwner()->getTransform()->getLocalPosition();

	//if the velocity is over the maximimum speed... 
	if (getVelocity().getMagnitude() > getMaxSpeed())
	{
		//...normalize the velocity and scale it by the max speed to clamp it.
		MathLibrary::Vector2 newVelocity = getVelocity().getNormalized() * getMaxSpeed();
		setVelocity(newVelocity);
	}
	//Increase the current position by the velocity to get the new position
	position = position + getVelocity() * deltaTime;
	//Set the transforms position to the new position
	getOwner()->getTransform()->setLocalPosition(position);
}
