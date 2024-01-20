#include"level.hpp"
using namespace std;

int main(){
    int WIDTH = 800 ,HEIGHT = 800;
    InitWindow(WIDTH,HEIGHT,"Window");
    SetTargetFPS(60);


    while (!WindowShouldClose()){
        
        BeginDrawing();
        float deltaTime = GetFrameTime();
        DrawLevel(deltaTime);   // background and level
            
        EndDrawing();
    }
    CloseWindow();
    return 0;
}