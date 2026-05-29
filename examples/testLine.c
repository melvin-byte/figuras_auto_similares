#include "../turtlec.h"
void fractal_tree(Turtle *t, float length , int depth){
    if(depth == 0){
        return;
    }
    
    turtleForward(t , length);
    
    turtleRight(t, 30.0);
    fractal_tree(t, length*0.7, depth -1);
    turtleLeft(t, 60.0);
    fractal_tree(t, length*0.7, depth -1);
    turtleRight(t, 30.0);
    turtleBackward(t, length);
}




int main(void){
  TurtleApp *app = turtleAppCreate(900, 900, "Test Line");

  if(app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  turtlePenUp(t);
  turtleGoTo(t, 0.0f,400.0f);
  turtlePenDown(t);

  turtleSetColor(t, 255, 100, 0);
  turtleSetSpeed(t, 5.0f);
  fractal_tree(t, 200, 4);
  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}
