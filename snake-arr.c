#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "raylib.h"
#include "raymath.h"


typedef struct{
    Vector2 position;
    Vector2 size;
    Vector2 velocity;
    float speed;
}snake_t;

int main (void){
    SetTargetFPS(60);
    InitWindow(800, 600, "SNAKE");
    

    snake_t snake = {{100, 100}, {20, 20}, {10, 0}, 100};
    Rectangle rec = {snake.position.x, snake.position.y, snake.size.x, snake.size.y};

    while (!WindowShouldClose()) {

        float delta_time = GetFrameTime();

        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("SNAKE", 50, 50, 20, WHITE);

        
        snake.velocity = Vector2Scale(Vector2Normalize(snake.velocity), snake.speed);
        snake.position = Vector2Add(snake.position, Vector2Scale(snake.velocity, delta_time));


        /*-------------------------------------------------------*/
        /*----------------------Controls-------------------------*/
        /*-------------------------------------------------------*/


        if(IsKeyDown(KEY_W) && snake.position.y)
        {
            snake.position.y = snake.position.y - snake.speed*delta_time;
        }

        if(IsKeyDown(KEY_A) && snake.position.x)
        {
            snake.position.x = snake.position.x - snake.speed*delta_time;
        }

        if(IsKeyDown(KEY_S) && snake.position.y)
        {
            snake.position.y = snake.position.y + snake.speed*delta_time;
        }

        if(IsKeyDown(KEY_D) && snake.position.x)
        {
            snake.position.x = snake.position.x + snake.speed*delta_time;
        }

        /*-------------------------------------------------------*/
        /*----------------------Drawing--------------------------*/
        /*-------------------------------------------------------*/

        DrawRectangle(snake.position.x, snake.position.y, snake.size.x, snake.size.y, GRAY);


    EndDrawing();
    }   
    CloseWindow();
    return 0;
}
