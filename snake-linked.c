#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "raylib.h"
#include "raymath.h"

typedef struct snake_body{
    Vector2 position;
    Vector2 size;
    Vector2 velocity;
    float speed;
    struct snake_body* next;
}snake_body;

typedef struct eatable_t{
    Vector2 position;
    Vector2 size;
    struct eatable_t* next;
} eatable_t;

void draw_node(snake_body* head) {
    snake_body* current = head;

    while (current != NULL) {
        DrawRectangle(current->position.x, current->position.y, current->size.x, current->size.y, GRAY);
        current = current->next;
    }
}

snake_body* add_node(snake_body* head) {
    snake_body* new_node = (snake_body*)malloc(sizeof(snake_body));
    
    snake_body* last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    
    new_node->position.x = last->position.x - last->size.x;
    new_node->position.y = last->position.y;
    new_node->size.x = last->size.x;
    new_node->size.y = last->size.y;
    new_node->next = NULL;
    
    last->next = new_node;
    
    return head;
}

void update_nodes(snake_body* head, Vector2 snake_pos) {
    if (head == NULL) return;
    
    snake_body* current = head;
    Vector2 prev_pos = current->position;
    
    current->position = Vector2Lerp(current->position, snake_pos, 0.1f);
    current = current->next;
    
    while (current != NULL) {
        Vector2 current_pos = current->position;
        current->position = Vector2Lerp(current->position, prev_pos, 0.1f);
        prev_pos = current_pos;
        current = current->next;
    }
}

int main (void){
    SetTargetFPS(60);
    InitWindow(800, 600, "SNAKE");
    
    snake_body snake = {{100, 100}, {20, 20}, {10, 0}, 100};
    eatable_t box = {400, 400, 20, 20};
    
    snake_body* head = NULL;

    eatable_t* box_head = NULL;
    box_head = (eatable_t*) malloc(sizeof(eatable_t));
    box_head->position.x = 300;
    box_head->position.y = 300;
    box_head->size.x = 20;
    box_head->size.y = 20;

    while (!WindowShouldClose()) {

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
        Rectangle box_rec = {box_head->position.x, box_head->position.y, box_head->size.x, box_head->size.y};

        if (CheckCollisionRecs(snake_rec, box_rec)) {
            if (head == NULL) {
                // Create first node
                head = (snake_body*) malloc(sizeof(snake_body));
                head->position = snake.position;
                head->size = snake.size;
                head->next = NULL;
            } else {
                // Add subsequent nodes
                head = add_node(head);
                snake.speed = snake.speed + 10;
            }
            // Reposition the box
            box_head->position.x = GetRandomValue(0, GetScreenWidth() - box_head->size.x);
            box_head->position.y = GetRandomValue(0, GetScreenHeight() - box_head->size.y);
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

        
        if (head != NULL) {
            update_nodes(head, snake.position);
        }

        // In drawing section:
        DrawRectangleRec(snake_rec, GRAY);
        if (head != NULL) {
            draw_node(head);
        }
        DrawRectangleRec(box_rec, WHITE);

    EndDrawing();
    }   
    CloseWindow();
    return 0;
}