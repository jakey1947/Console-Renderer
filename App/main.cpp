#include <cstdlib>
#include <iostream>
#include <time.h>
#include <vector>
//#include <stdlib.h>

#include "../Libraries/UIFramework.h"

using namespace UIframework;
using namespace CustomTypes;

bool BuildUI(Canvas* canvas, std::vector<UIElement*> elements)
{
  if(canvas->size <= 2) return false;
  for (int i = 0; i < elements.size(); i++) 
  {
    canvas->AddElement(elements[i]);
  }

  return true;
}

int main()
{
  std::cout << "Program Started" << "\n\n";
  Canvas canvas = Canvas(Vector2(80,80));

  Box box1 = Box(0, Vector2(10,5) );

  std::vector<UIElement*> elements = 
  {
    &box1
  };

  BuildUI(&canvas, elements);

  //generate random #s in the buffer
  // for (size_t i = 0; i < 10; i++)
  // {
  // Vector2 v1 = Vector2(abs(rand()) % 10, abs(rand()) % 10);

  // canvas.buffer.UpdateValue(v1, '#');
  // }

  canvas.Render();
  
  
  if(getchar())
  {
    system("clear");
    std::cout << "end\n";

    return 0; 
  }
}
