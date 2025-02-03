#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "raylib.h"
#include "raymath.h"


typedef struct{
    Vector2 position;
    Vector2 size;
    float speed;
}snake_t;

int main (void){
    SetTargetFPS(60);
    InitWindow(800, 600, "SNAKE");
    float delta_time = GetFrameTime();

    snake_t snake = {100, 100, 20, 20, 5};

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("SNAKE", 50, 50, 20, WHITE);

        DrawRectangle(snake.position.x, snake.position.y, snake.size.x, snake.size.y, GRAY);

        Rectangle rec = {snake.position.x, snake.position.y, snake.size.x, snake.size.y};



    EndDrawing();
    }   
    CloseWindow();
    return 0;
}
