#include <math.h>
#include <iostream>
#include <string>
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

    bool TextBuffer::WriteString(CustomTypes::Vector2 position, std::string text)
    {
      CustomTypes::Vector2 cursorPos = position;

      if(text.length() + cursorPos.x >= size.y)
        return false;

      for (size_t i = 0; i < text.length(); i++) 
      {
        if(!UpdateValue(cursorPos, text[i]))
          return false;
        cursorPos += Vector2(1,0);
      }
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
      elements[i]->WriteToBuffer(&buffer);
    }

    string outString = "";

    for (size_t i = 0; i < buffer.GetSize().x; i++)
    {
      outString += buffer.buffer[i] + "\n";
    }
    
    std::cout << outString;
  }

  void CardinalLine::WriteToBuffer(TextBuffer* buffer) 
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

  float Line::Length()
  {
    return (position - pointB).abs().Magnitude();
  }

  void Line::WriteToBuffer(TextBuffer* buffer) 
  {
    Vector2 slope = (position - pointB).Normalize();

    if(Length() == 0 || !isActive)
      return;

    for (size_t i = 0; i < Length(); i++)
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

  void Box::WriteToBuffer(TextBuffer* buffer)
  {
    if (!isActive) 
      return;

    for (size_t i = 0; i < 4; i++)
    {
      lines[i].WriteToBuffer(buffer);
    }
    for (size_t i = 0; i < 4; i++)
    {
      buffer->UpdateValue(lines[i].position, corner);
    }

  }


  void TextBox::WriteToBuffer(TextBuffer* buffer) 
  {
    Vector2 cursorPos = position;
    std::string temp = text;
    std::vector<std::string> splitString;

    size_t pos = 0;
    std::string token;
    //split the string into individual words
    while ((pos = temp.find(' ')) != std::string::npos) 
    {
        token = temp.substr(0, pos);
        splitString.push_back(token);
        temp.erase(0, pos + 1);
    }
    splitString.push_back(temp);

    int xBound = position.x + size.x;

    for (size_t i = 0; i < splitString.size(); i++)
    {

      if(cursorPos.x + splitString[i].length() >= xBound || !buffer->WriteString(cursorPos, splitString[i]))
      {
        cursorPos = Vector2(position.x, cursorPos.y+1);
        buffer->WriteString(cursorPos, splitString[i] + " ");
        cursorPos.x += splitString[i].length() + 1;
        continue;
      } 

      cursorPos.x += splitString[i].length() + 1;
    }
    return;      
  };
};