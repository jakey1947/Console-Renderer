#include "project.hpp"
#include <vector>
#include <math.h>

namespace Uiframework
{
  using namespace CustomTypes;
  using std::vector;

  struct TextBuffer
  {
    vector<vector<char>> buffer;

    public:

    TextBuffer(){}

    bool UpdateValue(Vector2 position, char newChar)
    {
      if(position < 0 || position >= Vector2(buffer.size(), buffer[0].size())) return false;

      buffer[position.x][position.y] = newChar;
      return true;
    }
  };

  class UIElement
  { 
    public :
    Vector2 position;
    bool isActive;

    UIElement(){}

    virtual void Render(TextBuffer* buffer){}
  };

  struct Canvas
  {
    CustomTypes::Vector2 size;
    std::vector<UIElement> elements;
    TextBuffer buffer;

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

      
    }
  };



  class CardinalLine:UIElement
  {
    int length;
    bool isVertical;
    char lineCharacter = '#';

    CardinalLine(Vector2 Position = Vector2(0,0), int newLength = 3)
    {
      length = newLength;
      position = Position;
    }

    void Render(TextBuffer* buffer) override 
    {
      if(length == 0)
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

  class Line:UIElement
  {
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

      for (size_t i = 0; i < length; i++)
      {
        if( !buffer->UpdateValue(position + slope * i, lineChar) ) break;
      }
      
    }
  };

  class Box:UIElement
  {
    Vector2 position, size;
    char corner, xChar, yChar;

    void render(Canvas canvas)
    {
      
    }
  };

  class renderer
  {

    void Render(TextBuffer* buffer){}

  };
};
