#include "TextBox.h"
#include "Engine.h"
#include "Scene.h"
#include "raylib.h"
#include "Actor.h"
#include "Transform2D.h"

/// <param name="text">The words that appear when a textbox is added</param>
/// <param name="x">the position of the textbox on the x-axis</param>
/// <param name="y">the position of the textbox on the y-axis</param>
/// <param name="name"> The name is used to identify the textbox on screen</param>
TextBox::TextBox(const char* text, float x, float y, const char* name)
{
	m_text = text;

	Engine::getCurrentScene()->addUIElement(this);
}

void TextBox::draw()
{
	RAYLIB_H::DrawText(m_text, getTransform()->getWorldPosition().x, getTransform()->getWorldPosition().y, 25, RED);
}
