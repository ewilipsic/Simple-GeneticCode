#pragma once
#include"player.hpp"
class POPULATION
{
    public:
    static const int pop = 31;
    player generation[pop];
    int dead_count = 0;
    int gen = 2;
    int stage = 0;
    
    POPULATION(){
        std::srand(6878);
        for(int i = 0;i<pop;i++){
            generation[i] = player();
        }
    }
    
    void DrawPopulation(){
        for(int i = 0;i<pop;i++){
            generation[i].DrawPlayer();
        }
        return;
    }
   
    int update_population(horizontal_vibrator* const& obstacles,Rectangle* const& walls){
        for(int i = 0;i<pop;i++){
            generation[i].move();
            if(generation[i].dead == 1){
                dead_count +=1;
            }
        }

        if(dead_count == pop){
            dead_count = 0;
            return 1;
        }
        dead_count = 0;
        for(int i = 0;i<pop;i++){
            int collision = 0;
            for(int j = 0;j<2;j++){
                collision += CheckCollisionRecs(obstacles[j].GiveRect(),generation[i].GiveRect());
            }
            if(collision>0){
                generation[i].dead = 1;
            }
            int stay_alive = 1;
            for(int j = 0;j<6;j++){
                stay_alive -= CheckCollisionRecs(walls[j],generation[i].GiveRect());
            }
            if(!stay_alive){
                generation[i].dead = 1;
            }
        }
        return 0;
    }
    
    float fitness(player& p,Vector2 goal){
        return ((p.spawnpoint_x-goal.x)*(p.spawnpoint_x-goal.x) + 2*(p.spawnpoint_y - goal.y)*(p.spawnpoint_y - goal.y) - (p.pos_x-goal.x)*(p.pos_x-goal.x) - 2*(p.pos_y - goal.y)*(p.pos_y - goal.y));
    }

    void refresh(Vector2 goal,horizontal_vibrator* obstacles){

        for(int i = 0;i<2;i++){
            (obstacles[i]).horizontal_position = obstacles[i].h_spawn;
        }
        gen += 1;

        float fitness_sums[pop] =  {0};
        float sum = 0;
        float max = 0;
        int maxi = 0;

        for(int i = 0;i<pop;i++){
            sum += fitness(generation[i],goal);
            if(max < fitness(generation[i],goal)){
                max = fitness(generation[i],goal);
                maxi = i;
            }
            fitness_sums[i] = sum;
        }

        player next_generation[pop];
        for(int i  = 0;i<pop-1;i++){
            int dice = (rand()*100)%((int)sum);
            for(int j = 0;j<pop;j++){
                if(dice<fitness_sums[j]){
                    next_generation[i] = generation[j];
                    break;
                }
            }
        }

        //get multiple decendants of the champion

        for(int i = 0;i<pop/3;i++){
            next_generation[i] = generation[maxi];
        }

        for(int i = 0;i<pop-1;i++){
            next_generation[i].mutate();
            next_generation[i].rejuv();
        }

        next_generation[pop-1] = generation[maxi];
        next_generation[pop-1].rejuv();

        for(int i = 0;i<pop;i++){
            generation[i] = next_generation[i];
        }
        return;
    }  
};
