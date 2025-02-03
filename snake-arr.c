#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "raylib.h"
#include "raymath.h"


int main (void){
    SetTargetFPS(60);
    InitWindow(800, 600, "SNAKE");

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("SNAKE", 200, 350, 20, WHITE);



    EndDrawing();
    }   
    CloseWindow();
    return 0;
}
