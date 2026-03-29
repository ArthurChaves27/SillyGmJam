#include <raylib.h>
#include <deque>

#define MAX_OBS 8

 struct Obstacle{
    Vector2 pos;
    Vector2 size;
    int speed;
    bool active;
};


/*
    I'm going to initialize a lot o obstacles and if one is active he is going to shown, else he can become an active one.
    So it's just a loop and if one is not active and the condition to be active is true than he will become active.
*/

int main(){

    const int screenW = 1280;
    const int screenH = 720;

    InitWindow(screenW, screenH, "Silly");
    SetTargetFPS(60);

    Vector2 carPos = {screenW/4.0f, screenH/4.0f - 80};
    Vector2 carSize = {120, 80}; 

    Vector2 floorSpos = {0, 0};
    Vector2 floorEpos = {1280, 0};

    Obstacle obstacles[MAX_OBS];

    for(int i = 0; i < MAX_OBS; i++){

        obstacles[i].pos = {1330, 0};
        obstacles[i].size = {50, 50};
        obstacles[i].speed = -300;
        obstacles[i].active = false;

    }
    
    obstacles[0].pos = {1024, 130};
    obstacles[0].active = true;

    while(!WindowShouldClose()){

        float dt = GetFrameTime();

        if((IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) && carPos.y != screenH/4.0f - 80){
                
            carPos.y -= 180;  

        }else if((IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) && carPos.y != screenH - 80.0f){
                
            carPos.y += 180;  

        }

        for(int i = 0; i < MAX_OBS; i++){
            
            if(obstacles[i].active){
                obstacles[i].pos.x += obstacles[i].speed*dt;

                if(obstacles[i + 1].pos.x - (obstacles[i].pos.x + obstacles[i].size.x) >= 256){
                    obstacles[i + 1].active = true;
                }

                if(obstacles[i].pos.x <= 0){

                    obstacles[i].pos = {1330, 0};
                    obstacles[i].active = false;

                }
            }
            
        }

        BeginDrawing();
        ClearBackground(WHITE);

        for(int i = 1; i <= 4; i++){

            floorSpos.y = 180*i;
            floorEpos.y = 180*i;

            DrawLineV(floorSpos, floorEpos, BLACK);

        }
        
        for(int i = 0; i < MAX_OBS; i++){
            
            if(obstacles[i].active) 
                DrawRectangleV(obstacles[i].pos, obstacles[i].size, RED);

        }
        DrawRectangleV(carPos, carSize, BLACK);

        EndDrawing();

    }
    CloseWindow();

return 0;
}