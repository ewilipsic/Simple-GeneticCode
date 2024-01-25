#pragma once
#include"player.hpp"
class POPULATION
{
    public:
    static const int pop = 31;
    player generation[pop];
    int dead_count = 0;
    int gen = 2;
    
    POPULATION(){
        std::srand(6878);
        for(int i = 0;i<pop-1;i++){
            generation[i] = player(rand());
        }
        generation[pop-1] = player(rand());
        for(int i = 0;i<30;i++){
            (generation[pop-1].moves)[i] = 1;

        }

    
    }
    
    void DrawPopulation(){
        for(int i = 0;i<pop;i++){
            generation[i].DrawPlayer();
        }
        return;
    }
   
    int update_population(float delta_time,horizontal_vibrator* const& obstacles,Rectangle* const& playarea){
        for(int i = 0;i<pop;i++){
            generation[i].move(delta_time);
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
            int stay_alive = 0;
            for(int j = 0;j<3;j++){
                stay_alive += CheckCollisionRecs(playarea[j],generation[i].GiveRect());
            }
            // if(!stay_alive){
            //     generation[i].dead = 1;
            // }
        }
        return 0;
    }
    
    float fitness(player& p,Vector2 goal){
        return ((p.spawnpoint_x-goal.x)*(p.spawnpoint_x-goal.x) + (p.spawnpoint_y - goal.y)*(p.spawnpoint_y - goal.y) - (p.pos_x-goal.x)*(p.pos_x-goal.x) + (p.pos_y - goal.y)*(p.pos_y - goal.y));
    }

    void refresh(Vector2 goal){
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

        for(int  i = 0;i<pop;i++) std::cout<<fitness_sums[i]<<std::endl;

        player next_generation[pop];
        for(int i  = 0;i<pop-1;i++){
            int dice = (rand()*100)%((int)sum);
            for(int j = 0;j<pop;j++){
                if(dice<fitness_sums[j]){
                    //std::cout<<j<<"\n";
                    next_generation[i] = generation[j];
                    break;
                }
            }
        }
        for(int i = 0;i<pop-1;i++){
            next_generation[i].mutate();
            next_generation[i].rejuv();
        }
        //std::cout<<maxi<< "  maxi "<<std::endl;
        next_generation[pop-1] = generation[maxi];
        next_generation[pop-1].rejuv();

        //for(int i = 0;i<num_moves;i++) std::cout<<(next_generation[pop-1].moves)[i];
        //std::cout<<"\n";
        for(int i = 0;i<pop;i++){
            generation[i] = next_generation[i];
        }
        return;
    }  
};
