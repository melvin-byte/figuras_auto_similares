#include "../turtlec.h"
void fractal_tree(Turtle *t, float length , int depth){
    if(depth == 0){
        return;
    }
    if (depth > 5){
        turtleSetColor(t, 120 , 70 , 20);
    }else{
        turtleSetColor(t, 0 , 200 , 0);
    }
    
    turtleForward(t , length);
    
    turtleRight(t, 20.0);
    fractal_tree(t, length*0.5, depth -1);
    turtleLeft(t, 40.0);
    fractal_tree(t, length*0.5, depth -1);
    turtleRight(t, 20.0);
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
  fractal_tree(t, 200, 7);
  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}
