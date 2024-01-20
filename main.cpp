#include"level.hpp"
using namespace std;

int main(){
        
    int WIDTH = 800 ,HEIGHT = 800;
    InitWindow(WIDTH,HEIGHT,"Window");
    SetTargetFPS(60);
    LEVEL level;


    while (!WindowShouldClose()){
        
        BeginDrawing();
        float deltaTime = GetFrameTime();
        level.DrawLevel();   // background and level
        level.update(deltaTime);
            
        EndDrawing();
    }
    CloseWindow();
    return 0;
}