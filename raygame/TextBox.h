#pragma once
#include "Actor.h"
class TextBox :
    public Actor
{
public:
    TextBox(const char* text, float x, float y, const char* name);

    void draw() override;

private:
    const char* m_text;
};

