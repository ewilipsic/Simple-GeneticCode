#include"horizontal_vibrator.hpp"
#include"population.hpp"
#include"wall.hpp"
#include<vector>
class LEVEL{
    public:
    horizontal_vibrator obstacles[2] = {horizontal_vibrator(),horizontal_vibrator(20,20,440,3,220,180,430)};
    Rectangle playarea[3] = {{180,300,440,200},{80,450,100,50},{620,300,100,50}};
    Vector2 goal = {620,300};
    CLITERAL(Color)color[3] = {RAYWHITE,GREEN,GREEN};
    POPULATION population;

    LEVEL(){}

    void DrawLevel(){
      ClearBackground(BLUE);
      for(int i = 0;i<3;i++){
        DrawRectangleRec(playarea[i],color[i]);
      }
      for(int i = 0;i<2;i++){
        obstacles[i].Draw(RED);
      }
      population.DrawPopulation();
    }

    void update(float delta_time){
      for(int i = 0;i<2;i++){
        obstacles[i].update(delta_time);
      }
      if(population.update_population(delta_time,obstacles,playarea)){
        std::cout<<"generation "<<population.gen<<std::endl;                         
        population.refresh(goal);
      }
      

    }
};
