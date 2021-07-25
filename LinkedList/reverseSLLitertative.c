// Take an list from user and reverse it using iterative method

#include<stdio.h>
#include<stdlib.h>

// create new data type name node with data and a pointer to node in this
struct node{
    int data;
    struct node *next;// Pointer to node for pointin  to next block
};

// Function for creating a new node and return address of new node
struct node* createNode(){
    return (struct node*)malloc(sizeof(struct node));
}

struct node* insertAtPosition(struct node *head, int pos, int count){
    struct node *temp, *newNode;
    // call creteNode function and insert data in newNode
    newNode = createNode();
    printf("Enter data : ");
    scanf("%d",&newNode->data);
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
        printf("Inserted as head node");
    }
    else if(pos==1){
        temp
    }
}