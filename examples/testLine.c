#include "../turtlec.h"
#include <math.h>
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
    fractal_tree(t, length*0.7, depth -1);
    turtleRight(t, 20.0);
    turtleBackward(t, length);
}

void fractal_tree_reto_final(Turtle *t, float length , int depth){
    if(depth == 0){
        return;
    }
  
    
    turtleForward(t , length);
    
    turtleRight(t, 20.0);
    fractal_tree_reto_final(t, length*0.5, depth -1);
    turtleLeft(t, 20.0);
    fractal_tree_reto_final(t, length*0.5, depth -1);
    turtleLeft(t, 20.0);

    fractal_tree_reto_final(t, length*0.5, depth -1);
    turtleRight(t, 20.0);
    turtleBackward(t, length);
}
void Levy(Turtle *t, float length, float depth){
    if(depth == 0){
        turtleForward ( t , length ) ;
        return;
    }
    turtleLeft(t, 45);
    Levy(t, length/sqrt(2), depth - 1);
    turtleRight(t, 90);
    Levy(t, length/sqrt(2), depth - 1);

    turtleLeft(t, 45);
}


int main(void){
  TurtleApp *app = turtleAppCreate(900, 900, "Test Line");

  if(app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  turtlePenUp(t);
  turtleGoTo(t, 200.0f,400.0f);
  turtlePenDown(t);

  turtleSetColor(t, 255, 100, 0);
  turtleSetSpeed(t, 5.0f);
  fractal_tree(t, 200, 5);
  //fractal_tree_reto_final(t, 200, 5);
  //Levy(t, 200 , 9);
  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}
