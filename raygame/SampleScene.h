#pragma once
#include "Scene.h"
#include "Player.h"
#include "Enemy.h"
class SampleScene :
    public Scene
{
public:
    void start() override;
    void update(float deltaTime) override;

private:
    Player* player;
    Enemy* enemy;

};

