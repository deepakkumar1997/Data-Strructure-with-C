// Create a doubly linked list and insert node at start and traverse through node

#include<stdio.h>
#include<stdlib.h>

// Doubly link node
struct node{
    int data;
    struct node *prev, *next;
};

// New node creation
struct node* createNode(){
    return (struct node*)malloc(sizeof(struct node));
}

// insert at start
void insertAtStart(struct node **start, int data){
    struct node *new;
    new = createNode();
    new->data = data;
    new->prev = NULL;
    new->next = *start;
    *start = new;
}

// Display list
void displayList(struct node *start){
    if(start==NULL)
        printf("List is empty\n");
    else{
        printf("NULL");
        struct node *temp = start;
        while (temp!=NULL)  
        {
            printf("<-%d->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Reverse doubly linked list
struct node* reverseDLL(struct node *start){
    if(start==NULL){
        printf("List is empty\n");
        return start;
    }
    struct node *currPtr, *nextPtr;  
    currPtr = start;
    while (currPtr!=NULL)
    {
        nextPtr = currPtr->next;
        currPtr->next = currPtr->prev;
        currPtr->prev = nextPtr;
        if(nextPtr==NULL)
            return currPtr;
        currPtr = nextPtr;
    }

}

int main(int argc, char const *argv[])
{
    struct node *start = NULL;
    start = reverseDLL(start);
    insertAtStart(&start,1);
    insertAtStart(&start,2);
    insertAtStart(&start,3);
    insertAtStart(&start,4);
    insertAtStart(&start,5);
    displayList(start);
    start = reverseDLL(start);
    displayList(start);
    return 0;
}
