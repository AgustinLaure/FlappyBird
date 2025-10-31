#include "raylib.h"

#include "Game/Screen/Screen.h"

int main(void)
{

  

    InitWindow(screen::screenWidth, screen::screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);              

    
    while (!WindowShouldClose())   
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();      

    return 0;
}
