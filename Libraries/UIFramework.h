#include <iostream>
#include <vector>
#include <string>
#include "CustomTypes.h"

namespace UIframework
{
  using namespace CustomTypes;
  class UIElement
  {
  public:
    Vector2 position;
    bool isActive;
    virtual void render(){}

    void SetPosition(Vector2 newPosition){};
  };

  struct TextBuffer
  {
    std::vector<std::string> buffer;

    public:

    TextBuffer(){};

    bool UpdateValue(Vector2 position, char newChar);
  };
  
  struct Canvas
  {
  public:
    CustomTypes::Vector2 size;
    std::vector<UIElement> elements;
    TextBuffer buffer;

    Canvas(Vector2 size = Vector2(80,80)){std::cout << "only header was read";};

    void AddElement(UIElement element){};

    void Render(){};
  };


  class CardinalLine: public UIElement
  {
  public: 
    CardinalLine(){};

    void Render(){};
  };

  class Box: public UIElement
  {
    private:
    CardinalLine lines[4];

    public:
    Vector2 size;
    char corner, xChar, yChar;
    Box(){};

    void Render(){};
  };


  class renderer
  {

    void render(){};

  };
}

