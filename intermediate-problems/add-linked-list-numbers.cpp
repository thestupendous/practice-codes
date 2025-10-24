#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to print a linked list
void printList(struct ListNode* head) {
    printf("[");
    while (head) {
        printf("%d", head->val);
        if (head->next) printf(",");
        head = head->next;
    }
    printf("]\n");
}

// Function to free a linked list
void freeList(struct ListNode* head) {
    struct ListNode* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to add two numbers represented by linked lists
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // TODO: Implement this function
	  printf("Log : in start\n");
		struct ListNode *result = NULL; 

		struct ListNode *ptr = result;

		bool carry=false;
		int resDigit,digit1,digit2;
	  printf("Log : going while\n");
		while (l1!=NULL || l2!=NULL ) {
			digit1 = (l1!=NULL) ? (l1->val) : (0) ;
			digit2 = (l2!=NULL) ? (l2->val) : (0) ;
			resDigit = digit1 + digit2;
	    printf("Log : got : %d+%d=%d\n",digit1,digit2,resDigit);
			if (carry) {
				resDigit++;
				carry=false;
	      printf("Log             : carry \n");

			}

			if(resDigit>=10) {
				resDigit%=10;
				carry = true;
	      printf("Log:    : result= %d,carry yes\n",resDigit);
			}

			struct ListNode *node = createNode(resDigit);
	    printf("Log : created 1 node, for %d\n",resDigit);


			if(result==NULL) {
				result=node;
				ptr=result;
			}else {
				ptr->next = node;
				ptr = ptr->next;
			}
			if (l1) l1=l1->next;
			if (l2) l2=l2->next;
			// if(l1->next) {
			// 	l1 = l1->next;
			// }
			// if(l2->next) {
			// 	l2 = l2->next;
			// }

			}

		
		if(carry) {
			// add new node with 1 value
			ptr->next = createNode(1);
		}

		return result;
}

int main() {
    // Example 1
    struct ListNode* l1 = createNode(2);
    l1->next = createNode(4);
    l1->next->next = createNode(3);
    
    struct ListNode* l2 = createNode(5);
    l2->next = createNode(6);
    l2->next->next = createNode(4);
    
    printf("Example 1:\n");
    printf("Input: l1 = ");
    printList(l1);
    printf("       l2 = ");
    printList(l2);
    
    struct ListNode* result1 = addTwoNumbers(l1, l2);
    printf("Output: ");
    printList(result1);
    
    // Clean up memory
    freeList(l1);
    freeList(l2);
    freeList(result1);
    
    // Example 2
    l1 = createNode(5);
    l2 = createNode(6);
		// l2->next = createNode(2);
    
    printf("\nExample 2:\n");
    printf("Input: l1 = ");
    printList(l1);
    printf("       l2 = ");
    printList(l2);
    
    struct ListNode* result2 = addTwoNumbers(l1, l2);
    printf("Output: ");
    printList(result2);
    
    // Clean up memory
    freeList(l1);
    freeList(l2);
    freeList(result2);
    
    return 0;
}
