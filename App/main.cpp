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
  "The FitnessGram Pacer Test is a multistage aerobic capacity test that progressively gets more difficult as it continues. The 20 meter pacer test will begin in 30 seconds. Line up at the start. The running speed starts slowly but gets faster each minute after you hear this signal bodeboop. A sing lap should be completed every time you hear this sound. ding Remember to run in a straight line and run as long as possible. The second time you fail to complete a lap before the sound, your test is over. The test will begin on the word start. On your mark. Get ready!… Start. Or don't. I don't really care.");

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
