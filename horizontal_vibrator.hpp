#include"raylib.h"
#include<iostream>
class horizontal_vibrator{
    public:
    int HEIGHT,WIDTH;
    int horizontal_span,time_period;
    float horizontal_position = 0;
    int h_start,v_start;
    int dir = 1,r =1,l =0;

    horizontal_vibrator(int height=20,int width = 20,int horspan = 440,int tperiod = 3,int h_position = 0,int hor_start = 180,int vert_start = 350){
        HEIGHT = height;
        WIDTH = width;
        horizontal_span= horspan;
        time_period = tperiod;
        horizontal_position = h_position;
        h_start = hor_start;
        v_start = vert_start;

    }
    void update(float delta_time){
        if(dir == l){
            if(horizontal_position <= 0){
                dir = r;
                horizontal_position = 0;
            }
            else{
                horizontal_position -= (((float)horizontal_span - WIDTH)/time_period) * delta_time;
                
            }
        }
        else{
            if(horizontal_position >= horizontal_span - WIDTH){
                dir = l;
                horizontal_position = horizontal_span - WIDTH;
            }
            else{
                horizontal_position += (((float)horizontal_span - WIDTH)/time_period) * delta_time;
            }
        }
        

    }

    Rectangle GiveRect(){
        return {h_start+(int)horizontal_position,v_start,WIDTH,HEIGHT};
    }

    void Draw(CLITERAL(Color) Color){
        DrawRectangle(h_start+(int)horizontal_position,v_start,WIDTH,HEIGHT,Color);
    }


};