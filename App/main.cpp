#include <cstdlib>
#include <iostream>
#include <time.h>
//#include <stdlib.h>

#include "../Libraries/UIFramework.h"

using namespace UIframework;
using namespace CustomTypes;


int main()
{
  std::cout << "Hello World" << "\n\n";
  Canvas canvas = Canvas(Vector2(80,80));
  std::cout << "egg";

  for (size_t i = 0; i < 10; i++)
  {
  Vector2 v1 = Vector2(abs(rand()) % 10, abs(rand()) % 10);

  canvas.buffer.UpdateValue(v1, '#');
  }

  canvas.Render();
  
  
  if(getchar())
  {
    system("clear");
    std::cout << "end\n";

    return 0; 
  }
}