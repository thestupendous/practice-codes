#include<stdio.h>
#include <stdlib.h>

// Define a structure for a Node in a singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* newNode(int data) {
    // Allocate memory for a new node
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    // Set the data for the new node
    node->data = data;
    // Set the next pointer of the new node to NULL
    node->next = NULL;
    return node;
}

// Function to display the elements of a linked list
void displayList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to add two linked lists
struct Node* add_Lists(struct Node* list1, struct Node* list2) {
    struct Node* res = NULL;
    struct Node* temp, * prev = NULL;
    int carry = 0, sum;

    // Traverse both lists and perform addition
    while (list1 != NULL || list2 != NULL) {
        sum = carry + (list1 ? list1->data : 0) + (list2 ? list2->data : 0);

        // Calculate carry for next calculation
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;

        // Create a new node with the sum as data
        temp = newNode(sum);

        // If the result list is empty, set the result as the new node
        if (res == NULL)
            res = temp;
        else
            prev->next = temp;

        prev = temp;

        // Move to the next nodes in the lists
        if (list1) list1 = list1->next;
        if (list2) list2 = list2->next;
    }

    // If there is a remaining carry, add a new node to the result
    if (carry > 0)
        temp->next = newNode(carry);

    return res; // Return the head of the resulting list
}

// Main function where the execution starts
int main() {
    // Creating two linked lists
    struct Node* list1 = newNode(8);
    list1->next = newNode(7);
    list1->next->next = newNode(9);
    list1->next->next->next = newNode(2);
    printf("List-1\n");
    displayList(list1); // Display the first list

    struct Node* list2 = newNode(2);
    list2->next = newNode(1);
    list2->next->next = newNode(2);
    list2->next->next->next = newNode(3);
    printf("List-2\n");
    displayList(list2); // Display the second list

    // Add the two lists
    struct Node* result = add_Lists(list1, list2);
    printf("\nAdding said two lists:\n");
    displayList(result); // Display the result of addition

    return 0; // Indicates successful completion of the program
}

