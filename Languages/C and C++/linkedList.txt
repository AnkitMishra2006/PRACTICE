// implementing a Linked list that contains Students data name and Roll no. with functionalities of creating a node Insertion and deletion at specific place and reversal

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a node in the linked list
struct StudentNode {
    int roll_number;          // Student roll number
    char name[50];            // Student name
    struct StudentNode* next; // Pointer to the next node
};

// Function to create a new node
struct StudentNode* create_node(int roll_number, char name[]) {
    struct StudentNode* new_node = (struct StudentNode*)malloc(sizeof(struct StudentNode));
    new_node->roll_number = roll_number;
    strcpy(new_node->name, name);
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at a specified position
void insert_at_position(struct StudentNode** head, int position, int roll_number, char name[]) {
    struct StudentNode* new_node = create_node(roll_number, name);
    
    if (position == 0) { // Insert at the head
        new_node->next = *head;
        *head = new_node;
        return;
    }
    
    struct StudentNode* current = *head;
    for (int i = 0; i < position - 1; i++) {
        if (current == NULL) {
            printf("Position out of bounds\n");
            free(new_node);
            return;
        }
        current = current->next;
    }
    
    new_node->next = current->next;
    current->next = new_node;
}

// Function to delete a node with a specified roll number
void delete_by_roll_number(struct StudentNode** head, int roll_number) {
    struct StudentNode* current = *head;
    struct StudentNode* previous = NULL;

    // If the node to be deleted is the head
    if (current != NULL && current->roll_number == roll_number) {
        *head = current->next;
        free(current);
        return;
    }

    // Search for the node to delete
    while (current != NULL && current->roll_number != roll_number) {
        previous = current;
        current = current->next;
    }

    // If the roll number is not found
    if (current == NULL) {
        printf("Roll number %d not found\n", roll_number);
        return;
    }

    // Unlink the node and free it
    previous->next = current->next;
    free(current);
}

// Function to reverse the linked list
void reverse(struct StudentNode** head) {
    struct StudentNode* previous = NULL;
    struct StudentNode* current = *head;
    struct StudentNode* next_node = NULL;

    while (current != NULL) {
        next_node = current->next;  // Store the next node
        current->next = previous;   // Reverse the current node's pointer
        previous = current;         // Move pointers ahead
        current = next_node;
    }
    *head = previous;  // Update the head to the new front
}

// Function to display the linked list
void display(struct StudentNode* head) {
    struct StudentNode* current = head;

    if (current == NULL) {
        printf("The list is empty.\n");
        return;
    }

    while (current != NULL) {
        printf("Roll Number: %d, Name: %s\n", current->roll_number, current->name);
        current = current->next;
    }
}

int main() {
    struct StudentNode* student_list = NULL;

    // Inserting students at various positions
    insert_at_position(&student_list, 0, 101, "John");
    insert_at_position(&student_list, 1, 102, "Alice");
    insert_at_position(&student_list, 2, 103, "Bob");
    insert_at_position(&student_list, 1, 104, "Eve");

    printf("Linked List after insertion:\n");
    display(student_list);

    // Deleting a student by roll number
    delete_by_roll_number(&student_list, 102);
    printf("\nLinked List after deletion of roll number 102:\n");
    display(student_list);

    // Reversing the linked list
    reverse(&student_list);
    printf("\nLinked List after reversal:\n");
    display(student_list);

    return 0;
}

// ***---------OUTPUT----------***

// Linked List after insertion:
// Roll Number: 101, Name: John
// Roll Number: 104, Name: Eve
// Roll Number: 102, Name: Alice
// Roll Number: 103, Name: Bob

// Linked List after deletion of roll number 102:
// Roll Number: 101, Name: John
// Roll Number: 104, Name: Eve
// Roll Number: 103, Name: Bob

// Linked List after reversal:
// Roll Number: 103, Name: Bob
// Roll Number: 104, Name: Eve
// Roll Number: 101, Name: John
