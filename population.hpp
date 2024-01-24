#pragma once
#include"player.hpp"
class POPULATION
{
    public:
    static const int pop = 30;
    player generation[pop];
    int dead_count = 0;
    int gen = 2;
    
    POPULATION(){
        std::srand(6878);
        for(int i = 0;i<pop;i++){
            generation[i] = player(rand());
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
        // if(generation[1].cur_move == 1){
        //     std::cout<<"first move ";
        // }
        // std::cout<<generation[1].pos_x<<"\n";
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
        return ((p.spawnpoint_x-goal.x)*(p.spawnpoint_x-goal.x) + (p.spawnpoint_y - goal.y)*(p.spawnpoint_y - goal.y) - (p.pos_x-goal.x)*(p.pos_x-goal.x) + (p.pos_y - goal.y)*(p.pos_y - goal.y))*1000;
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
        std::cout<<"max fit "<<max<<"\n";


        player next_generation[pop];
       // std::cout<<next_generation[1].pos_x<<"a\n";
        for(int i  = 0;i<pop-1;i++){
            int dice = rand()%((int)sum);
            for(int j = 0;j<pop;j++){
                if(dice<fitness_sums[j]){
                    next_generation[i] = generation[j];
                    break;
                }
            }
        }


        //std::cout<<next_generation[1].pos_x<<"b\n";
        for(int i = 0;i<pop-1;i++){
            next_generation[i].mutate();
            next_generation[i].rejuv();
        }
        std::cout<<maxi<< "  maxi "<<std::endl;
        next_generation[pop-1] = generation[maxi];
        next_generation[pop-1].rejuv();


        for(int i = 0;i<num_moves;i++){
            std::cout<<(next_generation[pop-1].moves)[i];
        }
        std::cout<<"\n";
        for(int i = 0;i<num_moves;i++){
            std::cout<<(generation[maxi].moves)[i];
        }
        std::cout<<"\n";
        for(int i = 0;i<pop;i++){
            generation[i] = next_generation[i];
        }
        //std::cout<<generation[1].pos_x<<"c\n";
        return;
    }  
};
