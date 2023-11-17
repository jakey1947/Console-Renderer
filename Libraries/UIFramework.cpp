#include <math.h>
#include <iostream>
#include <vector>



#include "UIFramework.h"


namespace UIframework
{
  using namespace UIframework;
  using namespace CustomTypes;
  using std::string;



    bool TextBuffer::UpdateValue(Vector2 position, char newChar)
    {
      if(position < 0 || position >= Vector2(buffer.size(), buffer[0].size())) return false;

      buffer[position.y][position.x] = newChar;
      return true;
    }



  void UIElement::SetPosition(Vector2 newPosition)
  {
    position = newPosition;
  }  

  void Canvas::AddElement(UIElement* element)
  {
    elements.push_back(element);
  }

  void Canvas::Render()
  {
    for (int i = 0; i  < elements.size(); i++)
    {
      elements[i]->Render(&buffer);
    }

    string outString = "";

    for (size_t i = 0; i < buffer.GetSize().x; i++)
    {
      outString += buffer.buffer[i] + "\n";
    }
    
    std::cout << outString;
  }

  void CardinalLine::Render(TextBuffer* buffer) 
  {
    if(this->length == 0 || !isActive)
      return;

    Vector2 dir = Vector2
    (
      isVertical ? 0 : sgn(length),
      !isVertical ? 0 : sgn(length)
    );

    for (int i = 0; i < std::abs(length); i++)
    {
      Vector2 nextPos = position + dir * i;    
      if( !buffer->UpdateValue(nextPos, lineCharacter) ) break;        
    }
  }

  void Line::Render(TextBuffer* buffer) 
  {
    Vector2 slope = position - pointB;
    int length = slope.GetMaximum();

    if(length == 0 || !isActive)
      return;

    for (size_t i = 0; i < length; i++)
    {
      if( !buffer->UpdateValue(position + slope * i, lineChar) ) break;
    }
    
  };

  void Box::UpdateLines()
  {
    lines[0].SetPosition(position);
    lines[1].SetPosition(position + Vector2(size.x, size.y) );
    lines[2].SetPosition(position + Vector2(0, size.y) );
    lines[3].SetPosition(position + Vector2(size.x, 0) );

    lines[0].length = size.x;
    lines[1].length = -size.x;
    lines[2].length = -size.y;
    lines[3].length = size.y;
  }

  void Box::Render(TextBuffer* buffer)
  {
    if (!isActive) 
      return;

    for (size_t i = 0; i < 4; i++)
    {
      lines[i].Render(buffer);
    }
    for (size_t i = 0; i < 4; i++)
    {
      buffer->UpdateValue(lines[i].position, corner);
    }

  }

  class TextBox : public UIElement
  {
    public:
    Vector2 size;
    string text;
    bool wrap;

    TextBox(Vector2 position = Vector2(0,0), Vector2 size = Vector2(1,0))
    {
      this->position = position;
      this->size = size;
    }

    void Render(TextBuffer* buffer) override 
    {
      Vector2 cursorPos = position;

      for (size_t i = 0; i < text.length(); i++)
      {
        if(!buffer->UpdateValue(position, text[i]) || cursorPos.x > position.x + size.x)
        {
          cursorPos = Vector2(position.x, cursorPos.y+1);
          buffer->UpdateValue(position, text[i]);
        }
      }      
    }
  };


  void renderer::render(){}

};
