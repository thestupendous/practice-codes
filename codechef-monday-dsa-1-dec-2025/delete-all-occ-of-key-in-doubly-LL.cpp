#include <iostream>
// TODO solve this
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) : data(x), next(NULL), prev(NULL) {}
}

Node* deleteAllOccurrences(Node* head, int X) {
    //write code here...
    Node *ptr{head}, *temp{NULL};
    
    while(ptr->next != NULL ) {
        if(ptr->data == X) {
            temp = ptr;
            if (ptr->prev!=NULL)
            ptr->prev->next = ptr->next;
            else head=ptr->next;
            ptr->next->prev = ptr->prev;
            ptr = ptr->next;
            delete temp;
            continue;
        }
        if(ptr!=NULL) ptr=ptr->next;
    }
    if (ptr->val==X) {
        temp = ptr;
        ptr->prev = NULL;
        delete temp;
    }
    return head;
}

