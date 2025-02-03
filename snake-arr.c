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

typedef struct{
    Vector2 position;
    Vector2 size;
    Vector2 velocity;
    float speed;
    bool active;
}body_t;

typedef struct{
    Vector2 position;
    Vector2 size;
    bool active;
} eatable_t;

int main (void){
    SetTargetFPS(60);
    InitWindow(800, 600, "SNAKE");
    
    snake_t snake = {{100, 100}, {20, 20}, {10, 0}, 100};
    body_t body = {snake.position.x, snake.position.y, snake.size.x, snake.size.y, snake.velocity.x, snake.velocity.y, snake.speed, false};

    eatable_t box = {300, 300, 20, 20, true};

    while (!WindowShouldClose()) {

        float followSpeed = 0.1f;  // Adjust this to change the speed of following
        body.position = Vector2Lerp(body.position, snake.position, followSpeed);

        float delta_time = GetFrameTime();

        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("SNAKE", 50, 50, 20, WHITE);

        snake.velocity = Vector2Scale(Vector2Normalize(snake.velocity), snake.speed);
        snake.position = Vector2Add(snake.position, Vector2Scale(snake.velocity, delta_time));

        /*-------------------------------------------------------*/
        /*----------------------Game-logic-----------------------*/
        /*-------------------------------------------------------*/

        Rectangle snake_rec = {snake.position.x, snake.position.y, snake.size.x, snake.size.y};

        if(box.active == true){
            Rectangle box_rec = {box.position.x, box.position.y, box.size.x, box.size.y};
            if(CheckCollisionRecs(snake_rec, box_rec)){
                body.active = true;
                box.active = false;
            }
        }

        /*-------------------------------------------------------*/
        /*----------------------Controls-------------------------*/
        /*-------------------------------------------------------*/

        if(IsKeyDown(KEY_W) && snake.velocity.y < 9)
        {
            snake.velocity.y = -10;
            snake.velocity.x = 0;
        }

        if(IsKeyDown(KEY_A) && snake.velocity.x < 9)
        {
            snake.velocity.y = 0;
            snake.velocity.x = -10;
        }

        if(IsKeyDown(KEY_S) && snake.velocity.y > -9)
        {
            snake.velocity.y = 10;
            snake.velocity.x = 0;
        }

        if(IsKeyDown(KEY_D) && snake.velocity.x > -9)
        {
            snake.velocity.y = 0;
            snake.velocity.x = 10;
        }

        /*-------------------------------------------------------*/
        /*----------------------Drawing--------------------------*/
        /*-------------------------------------------------------*/

        DrawRectangle(snake.position.x, snake.position.y, snake.size.x, snake.size.y, GRAY);

        if(box.active == true){
        DrawRectangle(box.position.x, box.position.y, box.size.x, box.size.y, WHITE);
        }

        if(body.active == true){
            DrawRectangle(body.position.x, body.position.y, body.size.x, body.size.y, GRAY);
        }

    EndDrawing();
    }   
    CloseWindow();
    return 0;
}