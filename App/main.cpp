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
  Canvas canvas = Canvas(Vector2(80,26));

  Box box1 = Box(0, Vector2(60,20) );
  Box box2 = Box(Vector2(60,0), Vector2(19,20) );
  Box box3 = Box(Vector2(0,20), Vector2(79,5) );
  Line line1 = Line(Vector2(1,21), Vector2(79, 25));
  TextBox textBox1 = TextBox(Vector2(1,1), Vector2(60,20), 
  "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");

  std::vector<UIElement*> elements = 
  {
    &box1 , &box2, &box3, &line1, &textBox1
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
