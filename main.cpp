#include <raylib.h>
#include <deque>

struct obstacle{
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

    std::deque<obstacle> obstacles = {};
    

    while(!WindowShouldClose()){

        int dt = GetFrameTime();

        if((IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) && carPos.y != screenH/4.0f - 80){
                
            carPos.y -= 180;  

        }else if((IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) && carPos.y != screenH - 80){
                
            carPos.y += 180;  

        }

        for(int i = 0; i < obstacles.size(); i++){


        }        

        BeginDrawing();
        ClearBackground(WHITE);

        for(int i = 1; i <= 4; i++){

            floorSpos.y = 180*i;
            floorEpos.y = 180*i;

            DrawLineV(floorSpos, floorEpos, BLACK);

        }
        
        //for(int i = 0; i < obstacles.size(); i++) DrawRectangleV(obstacles[i], Vector2{50, 50}, RED);

              DrawRectangleV(carPos, carSize, BLACK);

        EndDrawing();

    }
    CloseWindow();

return 0;
}