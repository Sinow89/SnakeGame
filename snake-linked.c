#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "raylib.h"
#include "raymath.h"

#define MAX_BODIES 10

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

typedef struct eatable_t{
    Vector2 position;
    Vector2 size;
    struct eatable_t* next;
} eatable_t;

typedef struct snake_body {
    Vector2 position;
    Vector2 size;
    struct snake_body* next;
} snake_body;


void draw_node(snake_body* head) {
    snake_body* current = head;

    while (current != NULL) {
        DrawRectangle(current->position.x, current->position.y, current->size.x, current->size.y, GRAY);
        current = current->next;
    }
}

int main (void){
    SetTargetFPS(60);
    InitWindow(800, 600, "SNAKE");
    int body_number = 0;
    int box_amount = 10;
    
    snake_t snake = {{100, 100}, {20, 20}, {10, 0}, 100};
    eatable_t box = {400, 400, 20, 20};
    
    snake_body* head = NULL;
    head = (snake_body*) malloc(sizeof(snake_body));
    head->position.x = snake.position.x;
    head->position.y = snake.position.y;
    head->size.x = snake.size.x;
    head->size.y = snake.size.y;
    head->next = NULL;

    eatable_t* box_head = NULL;
    box_head = (eatable_t*) malloc(sizeof(eatable_t));
    box_head->position.x = 300;
    box_head->position.y = 300;
    box_head->size.x = 20;
    box_head->size.y = 20;





    // body_t bodies[MAX_BODIES];

    // eatable_t box[box_amount];

    // for (int i = 0; i < box_amount; i++) {
    //     box[i].position.x = 200 + i * 50;
    //     box[i].position.y = 200 + i * 25;
    //     box[i].size.x = 15;
    //     box[i].size.y = 15;      
    //     box[i].active = true;
    // }

    // Initialize first body at snake's position and the rest behind it
    // for (int i = 0; i < MAX_BODIES; i++) {
    //     bodies[i].position = (Vector2){snake.position.x - (i * 20), snake.position.y};
    //     bodies[i].size = snake.size;
    //     bodies[i].speed = snake.speed;
    //     bodies[i].active = false;
    // }

    while (!WindowShouldClose()) {

        // Update each body
        // for (int i = 0; i < MAX_BODIES; i++) {
        //     if (i == 0) {
        //         // First body follows the snake directly
        //         bodies[i].position = Vector2Lerp(bodies[i].position, snake.position, 0.1f);
        //     } else {
        //         // Subsequent bodies follow the body in front of them
        //         bodies[i].position = Vector2Lerp(bodies[i].position, bodies[i-1].position, 0.1f);
        //     }
        // }


        head->position = Vector2Lerp(head->position, snake.position, 0.1f);

        float delta_time = GetFrameTime();

        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("SNAKE", 50, 50, 20, WHITE);

        // draw_node(head);

        snake.velocity = Vector2Scale(Vector2Normalize(snake.velocity), snake.speed);
        snake.position = Vector2Add(snake.position, Vector2Scale(snake.velocity, delta_time));

        /*-------------------------------------------------------*/
        /*----------------------Game-logic-----------------------*/
        /*-------------------------------------------------------*/

        Rectangle snake_rec = {snake.position.x, snake.position.y, snake.size.x, snake.size.y};
        Rectangle box_rec = {box_head->position.x, box_head->position.y, box_head->size.x, box_head->size.y};

        if(CheckCollisionRecs(snake_rec, box_rec)){
                    draw_node(head);            
        }

    
        // for (int i = 0; i < box_amount; i++) {
        //     if(box[i].active == true){
        //         Rectangle box_rec = {box[i].position.x, box[i].position.y, box[i].size.x, box[i].size.y};
        //         if(CheckCollisionRecs(snake_rec, box_rec)){
        //             if (body_number < MAX_BODIES) {
        //             bodies[body_number].active = true;
        //             body_number++;  // Move to the next body for the next box collision
        //             }
        //             box[i].active = false;
        //         }
        //     }
        // }

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


        DrawRectangle(box_head->position.x, box_head->position.y, box_head->size.x, box_head->size.y, WHITE);

   

        //Drawing of active Rectangles
        // for (int i = 0; i < box_amount; i++){
        //     if (box[i].active == true){
        //         DrawRectangle(box[i].position.x, box[i].position.y, box[i].size.x, box[i].size.y, WHITE);
        //     }
        // }

        // for (int i = 0; i < MAX_BODIES; i++) {
        //     if(bodies[i].active == true){
        //     DrawRectangleV(bodies[i].position, bodies[i].size, GRAY);
        //     }
        // }

    EndDrawing();
    }   
    CloseWindow();
    return 0;
}