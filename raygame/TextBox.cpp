#include "TextBox.h"
#include "Engine.h"
#include "Scene.h"
#include "raylib.h"
#include "Actor.h"
#include "Transform2D.h"

TextBox::TextBox(const char* text, float x, float y, const char* name)
{
	m_text = text;

	Engine::getCurrentScene()->addUIElement(this);
}

void TextBox::draw()
{
	RAYLIB_H::DrawText(m_text, getTransform()->getWorldPosition().x, getTransform()->getWorldPosition().y, 25, RED);
}
