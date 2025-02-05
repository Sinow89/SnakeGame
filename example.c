// 1. get a pointer to the first element in the list
// 2. while we havent found the data
// 3. check if this node has the data
// 4. if it has, return it or break out of the loop
// 5. else update the pointer to the next pointer

// typedef struct SnakeElement {
//     Vector2 position;
//     Vector2 size;
// };

// SnakeElement snake;
// snake.position;

// SnakeElement* snake_ptr = &snake;
// *snake.position;

// snake->position;

// typedef struct Node {
//     SnakeElement data;
//     struct Node *next;
// } Node;

// typedef struct {
//     Node* head;
//     Node* tail;
//     int num_elements;
// } List;

// Node *current_node = snake_list.head;
// while (current_node->next != NULL) {
//     current_node = current_node->next;
// };

#include <stdio.h>
#include <stdlib.h>

typedef struct snake_body {
    int data;
    struct snake_body* next;
} snake_body;

void print_list(snake_body* head) {
    snake_body* current = head;

    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main() {

snake_body* head = NULL;

head = (snake_body*) malloc(sizeof(snake_body));
head->data = 2;

head->next = (snake_body*) malloc(sizeof(snake_body));
head->next->data = 3;

print_list(head);


}

