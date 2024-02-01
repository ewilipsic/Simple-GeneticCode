#include"level.hpp"
using namespace std;

int main(){
        
    int WIDTH = 800 ,HEIGHT = 800;
    InitWindow(WIDTH,HEIGHT,"Window");
    SetTargetFPS(60);
    LEVEL level;
    int count = 0;
    while (!WindowShouldClose()){
        
        
        float deltaTime = GetFrameTime();
        if(count == 10){
        BeginDrawing();
        level.DrawLevel();   // background and level
        EndDrawing();
        count = 0;
        }
        level.update(deltaTime);
        
        count+=1;
    }
    CloseWindow();
    return 0;
}