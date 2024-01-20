#include<cstdlib>
#include<iostream>
#include"raylib.h"
class player{
    public:
    int HEIGHT,WIDTH;
    int spawnpoint_x,spawnpoint_y;
    float pos_x,pos_y;
    int cur_move = 0;
    static const int num_moves = 1000;
    bool dead = 0;
    CLITERAL(Color) color = YELLOW;
    
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
        //int a=0,b=0,c=0,d= 0;
        // for(int x : moves){
        //      if(x == 1){
        //         a+=1;
        //      }
        //      if(x == 2){
        //         b+=1;
        //      }
        //     if(x == 3){
        //        c+=1;
        //     }
        //     if(x == 0){
        //        d+=1;
        //     }
             
             
        // }
        // std::cout<<a<<" "<<b<<" "<<c<<" "<<d;
    }
    void move(float delta_time){
        if(dead == 1){
            color = BLACK;
            return;
        }
        if(moves[cur_move] == 0){
            pos_y -= 500*delta_time;
        }
        if(moves[cur_move] == 1){
            (*(&pos_x)) += 500*delta_time;
        }
        if(moves[cur_move] == 2){
            (*(&pos_y)) += 500*delta_time;
        }
        if(moves[cur_move] == 3){
            pos_x -= 500*delta_time;
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
     //   std::cout<<"in draw"<<&pos_x<<" "<<&pos_y<<std::endl;
    }

};