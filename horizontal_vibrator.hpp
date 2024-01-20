#include"raylib.h"
#include<iostream>
class horizontal_vibrator{
    public:
    int HEIGHT,WIDTH;
    int horizontal_span,time_period;
    float horizontal_position = 0;
    int dir = 1,r =1,l =0;
    int count = 0;

    horizontal_vibrator(int height=20,int width = 20,int horspan = 440,int tperiod = 3,int h_position = 0){
        HEIGHT = height;
        WIDTH = width;
        horizontal_span= horspan;
        time_period = tperiod;
        horizontal_position = h_position;
    }
    void update(float delta_time){
        count+=1;
        if(dir == l){
            if(horizontal_position <= 0){
                dir = r;
                horizontal_position = 0;
                std::cout<<count<<std::endl;
                count =0;
            }
            else{
                horizontal_position -= (((float)horizontal_span - WIDTH)/time_period) * delta_time;
                
            }
        }
        else{
            if(horizontal_position >= horizontal_span - WIDTH){
                dir = l;
                horizontal_position = horizontal_span - WIDTH;
                std::cout<<"-"<<count<<std::endl;
                count =0;
            }
            else{
                horizontal_position += (((float)horizontal_span - WIDTH)/time_period) * delta_time;
            }
        }
        

    }
    void Draw(int h_start,int v_start,CLITERAL(Color) Color){
        DrawRectangle(h_start+(int)horizontal_position,v_start,WIDTH,HEIGHT,Color);
    }


};