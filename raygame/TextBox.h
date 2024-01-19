#pragma once
#include "Actor.h"
class TextBox :
    
    public Actor
{

  
public:
    /// <param name="text">The words that appear when a textbox is added</param>
    /// <param name="x">the position of the textbox on the x-axis</param>
    /// <param name="y">the position of the textbox on the y-axis</param>
    /// <param name="name"> The name is used to identify the textbox on screen</param>
    TextBox(const char* text, float x, float y, const char* name);
    
    void draw() override;

private:
    const char* m_text;
};

