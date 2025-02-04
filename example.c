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




int main() {


    // Structure to represent the singly linked list
struct Node {
  
  // Data field - can be of any type and count
  int data;
  
  // Pointer to the next node
  Node* next;
};

    int a = 99;
    int b = 1;
    
    printf("Sum of %d and %d is %d", a, b,
           a + b);
}

