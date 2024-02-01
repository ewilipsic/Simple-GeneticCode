#include"horizontal_vibrator.hpp"
#include<cstdlib>
#include<iostream>
#include"raylib.h"

#define num_moves 500
class player{
    public:
    int HEIGHT,WIDTH;
    int spawnpoint_x,spawnpoint_y;
    float pos_x,pos_y;
    int cur_move = 0;
    //static const int num_moves = 100;
    bool dead = 0;
    CLITERAL(Color) color = BLACK;
    
    int moves[num_moves]; // 0 = u ,1 = r,2 =d,3 =l
    player(){};
    player(int seed){
        HEIGHT = 20;
        WIDTH = 20;
        spawnpoint_x = 80;
        spawnpoint_y = 450;
        pos_x = spawnpoint_x;
        pos_y = spawnpoint_y;
        for(int i = 0;i<num_moves;i++){
            int temp = std::rand()%4;
            moves[i] = temp;
        }
    }
    // player(player& p){
    //     HEIGHT = 20;
    //     WIDTH = 20;
    //     spawnpoint_x = 80;
    //     spawnpoint_y = 450;
    //     pos_x = spawnpoint_x;
    //     pos_y = spawnpoint_y;
    //     for(int i = 0;i<num_moves;i++){
    //         moves[i] =(p.moves)[i];
    //     }

    // }
    void move(float delta_time){
        if(dead == 1){
            color = BLACK;
            return;
        }
        if(moves[cur_move] == 0){
            pos_y -= 1.3;
        }
        if(moves[cur_move] == 1){
            pos_x += 1.3;
        }
        if(moves[cur_move] == 2){
            pos_y += 1.3;
        }
        if(moves[cur_move] == 3){
            pos_x -= 1.3;
        }
        cur_move+=1;
        if(cur_move>num_moves){
            dead = 1;
        }
    }

    Rectangle GiveRect(){
        return {(int)pos_x,(int)pos_y,WIDTH,HEIGHT};
    }

    void DrawPlayer(){
        DrawRectangle((int)pos_x,(int)pos_y,WIDTH,HEIGHT,color);
        std::cout<<"in draw "<<pos_x<<" "<<pos_y<<std::endl;
     
    }

    void mutate(){
        for(int i = 0;i<num_moves;i++){
            if(rand()%100 == 0){
                moves[i] = rand()%4;
            }
        }
        return;
    }
    
    void rejuv(){
        dead = 0;
        color = BLACK;
        pos_x = spawnpoint_x;
        pos_y = spawnpoint_y;
        cur_move = 0;
        return;
    }

};
