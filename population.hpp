#include"player.hpp"
#include<ctime>
#include<iostream>
class POPULATION
{
    static const int pop = 30;
    public:
    player generation[pop];
    
    POPULATION(){
        std::srand(6878);
        for(int i = 0;i<pop;i++){
            int r = rand();
            std::cout << r << std::endl;
            generation[i] = player(r);
        }

    
    }
    void DrawPopulation(){
        for(int i = 0;i<pop;i++){
            generation[i].DrawPlayer();
        }
    }
    void update_population(float delta_time){
        for(int i = 0;i<pop;i++){
            generation[i].move(delta_time);
        }
    }
    
};
