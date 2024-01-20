#include"player.hpp"
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
    void update_population(float delta_time,horizontal_vibrator* const& obstacles){
        for(int i = 0;i<pop;i++){
            generation[i].move(delta_time);
        }
        for(int i = 0;i<pop;i++){
            int collision = 0;
            for(int j = 0;j<2;j++){
                collision += CheckCollisionRecs(obstacles[j].GiveRect(),generation[i].GiveRect());
            }
            if(collision>0){
                generation[i].dead = 1;
            }
        }
        
    }
    
};
