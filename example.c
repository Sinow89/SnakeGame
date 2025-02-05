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

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void print_list(Node* head) {
    Node * current = head;

    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main() {


Node* head = NULL;

head = (Node*) malloc(sizeof(Node));
head->data = 2;

head->next = (Node *) malloc(sizeof(Node));
head->next->data = 3;

print_list(head);


}

