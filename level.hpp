#include"horizontal_vibrator.hpp"
#include"population.hpp"

horizontal_vibrator one;
horizontal_vibrator two(20,20,440,3,220);
POPULATION population;

void DrawLevel(float delta_time){
  ClearBackground(BLUE);
  DrawRectangle(180,300,440,200,RAYWHITE);
  DrawRectangle(80,450,100,50,GREEN);
  DrawRectangle(620,300,100,50,GREEN);
  one.update(delta_time);
  one.Draw(180,350,RED);
  two.update(delta_time);
  two.Draw(180,430,RED);
  population.DrawPopulation();
  population.update_population(delta_time);

}

