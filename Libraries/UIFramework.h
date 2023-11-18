#include <cstddef>
#include <iostream>
#include <vector>
#include <string>
#include "CustomTypes.h"

namespace UIframework
{

  struct TextBuffer
  {
    std::vector<std::string> buffer;
    CustomTypes::Vector2 size;

    public:

    TextBuffer(CustomTypes::Vector2 size = CustomTypes::Vector2(80,80))
    {
      this->size = size;
      for (int x = 0; x < size.x; x++) 
      {
        buffer.push_back(std::string(size.y, ' '));
      }
    }

    bool WriteString(CustomTypes::Vector2 position, std::string text);

    CustomTypes::Vector2 GetSize()
    {
      return CustomTypes::Vector2(buffer.size(), buffer[0].size());
    }

    bool UpdateValue(CustomTypes::Vector2 position, char newChar);
  };

  class UIElement
  {
    public:
    CustomTypes::Vector2 position;
    bool isActive = true;

    void SetPosition(CustomTypes::Vector2 newPosition);
  
    virtual void Render(TextBuffer* buffer){std::cout << "virtual Render method called";}
  }; 
  
  struct Canvas
  {
  public:
    CustomTypes::Vector2 size;
    std::vector<UIElement*> elements;
    TextBuffer buffer;

        Canvas(CustomTypes::Vector2 size = CustomTypes::Vector2(80,80))
    {
      this -> size = size;
      buffer = TextBuffer(CustomTypes::Vector2(size.y, size.x));
      std::cout << "Canvas Created \n";
    };

    void AddElement(UIElement* element);

    void Render();
  };


  class CardinalLine: public UIElement
  {
  public: 
    int length;
    bool isVertical;
    char lineCharacter;

  CardinalLine(CustomTypes::Vector2 Position = CustomTypes::Vector2(0,0), int newLength = 3, bool isVertical = false)
  {
    length = newLength;
    position = Position;
    this->isVertical = isVertical;
  };

    void Render(TextBuffer* buffer) override;
  };

  class Line: public UIElement
  {
        public:
    CustomTypes::Vector2 pointB;
    char lineChar = 'o';

    Line(CustomTypes::Vector2 pointA = CustomTypes::Vector2(0,0), CustomTypes::Vector2 pointB = CustomTypes::Vector2(1,0), char lineChar = 'o')
    {
      position = pointA;
      this->pointB = pointB;
      this->lineChar = lineChar;
    }

      float Length();

    void Render(TextBuffer* buffer) override;
  };

  class Box: public UIElement
  {
    private:
    CardinalLine lines[4]  = {CardinalLine(), CardinalLine(), CardinalLine(), CardinalLine()};

    public:
    CustomTypes::Vector2 size;
    char corner, xChar, yChar;

    Box(CustomTypes::Vector2 position = CustomTypes::Vector2(0,0), CustomTypes::Vector2 size = CustomTypes::Vector2(5,5), char xChar = '-', char yChar = '|', char corner = 'O')
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

      lines[0].lineCharacter = '-';
      lines[1].lineCharacter = '-';
      lines[2].lineCharacter = '|';
      lines[3].lineCharacter = '|';

      UpdateLines();

    }
    void UpdateLines();
    void Render(TextBuffer* buffer) override;


  };


  class TextBox : public UIElement
  {
    public:
    CustomTypes::Vector2 size;
    std::string text;
    bool wrap;

    TextBox(CustomTypes::Vector2 position = CustomTypes::Vector2(0,0), CustomTypes::Vector2 size = CustomTypes::Vector2(1,0), std::string contents = "")
    {
      this->position = position;
      this->size = size;
      this->text = contents;
    }

    void Render(TextBuffer* buffer) override;

  };


  class renderer
  {

    void render();

  };
}

