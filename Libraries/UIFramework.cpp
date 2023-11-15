#include <math.h>
#include <iostream>
#include <vector>
#include "UIFramework.h"


namespace Uiframework
{
  using namespace CustomTypes;
  using std::vector;
  using std::string;

  struct TextBuffer
  {
    Vector2 size;
    vector<string> buffer;

    public:

    TextBuffer(Vector2 size = Vector2(80,80))
    {
      this->size = size;
      for (int x = 0; x < size.x; x++) 
      {
        buffer[x] = string(size.y, ' ');
      }
    }

    Vector2 GetSize()
    {
      return Vector2(buffer.size(), buffer[0].size());
    }

    bool UpdateValue(Vector2 position, char newChar)
    {
      if(position < 0 || position >= Vector2(buffer.size(), buffer[0].size())) return false;

      buffer[position.y][position.x] = newChar;
      return true;
    }
  };

  class UIElement
  { 
    public :
    Vector2 position;
    bool isActive;

    UIElement(){}

    void SetPosition(Vector2 newPosition)
    {
      position = newPosition;
    }

    virtual void Render(TextBuffer* buffer){}
  };

  struct Canvas
  {
    CustomTypes::Vector2 size;
    std::vector<UIElement> elements;
    TextBuffer buffer;

    Canvas(Vector2 size = Vector2(80,80))
    {
      this -> size = size;
      buffer = TextBuffer(size);
      std::cout << "Canvas Created";
    }

    void AddElement(UIElement element)
    {
      elements.push_back(element);
    }

    void Render()
    {
      for (int i = 0; i  < elements.size(); i++)
      {
        elements[i].Render(&buffer);
      }

      string outString = "";

      for (size_t i = 0; i < buffer.GetSize().x; i++)
      {
        outString += buffer.buffer[i] + "\n";
      }
      
      std::cout << outString;
    }
  };



  class CardinalLine: public UIElement
  {
    public:
    int length;
    bool isVertical;
    char lineCharacter = '#';

    CardinalLine(Vector2 Position = Vector2(0,0), int newLength = 3, bool isVertical = false)
    {
      length = newLength;
      position = Position;
      this->isVertical = isVertical;
    }

    void Render(TextBuffer* buffer) override 
    {
      if(length == 0 || !isActive)
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
  };

  class Line : public UIElement
  {
    public:
    Vector2 pointB;
    char lineChar = 'o';

    Line(Vector2 pointA = Vector2(0,0), Vector2 pointB = Vector2(1,0))
    {
      position = pointA;
    }

    void Render(TextBuffer* buffer) override 
    {
      Vector2 slope = position - pointB;
      int length = slope.GetMaximum();

      if(length == 0 || !isActive)
        return;

      for (size_t i = 0; i < length; i++)
      {
        if( !buffer->UpdateValue(position + slope * i, lineChar) ) break;
      }
      
    }
  };

  class Box: public UIElement
  {
    public:
    Vector2 size;
    CardinalLine lines[4]  = {CardinalLine(), CardinalLine(), CardinalLine(), CardinalLine()};
    char corner, xChar, yChar;

    Box(Vector2 position = Vector2(0,0), Vector2 size = Vector2(5,5), char xChar = '-', char yChar = '|', char corner = 'O')
    {
      this->position = position;
      this->corner = corner;
      this->xChar = xChar;
      this->yChar = yChar;
      this->size = size;

      lines[0].isVertical = false;
      lines[1].isVertical = false;
      lines[2].isVertical = true;
      lines[3].isVertical = true;

      UpDateLines();

    }

    void UpDateLines()
    {
      lines[0].SetPosition(position);
      lines[1].SetPosition(position + Vector2(0, size.y) );
      lines[2].SetPosition(position + Vector2(0, size.y) );
      lines[3].SetPosition(position + Vector2(size.x, 0) );

      lines[0].length = size.x;
      lines[1].length = size.x;
      lines[2].length = size.y;
      lines[3].length = size.y;
    }

    void render(TextBuffer* buffer)
    {
      if (!isActive) return;

      for (size_t i = 0; i < 4; i++)
      {
        lines[i].Render(buffer);
      }

    }
  };

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

  class renderer
  {

    void Render(TextBuffer* buffer){}

  };
};
