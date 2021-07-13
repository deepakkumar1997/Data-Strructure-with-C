// Take a node as input and insert it at begining of list

#include<stdio.h>
#include<stdlib.h>

struct node{
    int mark;
    struct node *next;
};

struct node *start = NULL;

struct node* createNode(){
    return malloc(sizeof(struct node));
}

void insertAtBegin(){
    struct node *new, *temp;
    new = createNode();
    printf("Enter mark : ");
    scanf("%d",&new->mark);
    if(start == NULL){
        start = new;
        printf("%d is inserted as 1st node.",new->mark);
        new->next == NULL;
    }
    else{
        temp = start;
        start = new;
        printf("%d is inserted as 1st node.",new->mark);
        new->next = temp;
    }
}

void deleteAtEnd(){
    struct node *delNode = start,*temp = start;
    if(start==NULL)
        printf("List is already empty.");
    else if(start->next==NULL){
        start = NULL;
        printf("%d is deleted.",delNode->mark);
        free(delNode);
    }
    else{
        while (delNode->next!=NULL){
            temp = delNode;
            delNode = delNode->next;
        }
        temp->next = NULL;
        printf("%d is deleted.",delNode->mark);
        free(delNode);
    }
}

void viewList(){
    struct node *visit = start;
    if(visit==NULL)
        printf("List is empty.");
    else{
        printf("List of mark is { ");
    while(visit!=NULL){
        printf("%d, ",visit->mark);
        visit = visit->next;
    }
    printf("\b\b }");
    }
    
}

int menu(){
    int choice;
    printf("\n1.Insert a node at the begining\n");
    printf("2.Delete last node\n");
    printf("3.View list\n");
    printf("4.exit\n");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    return choice;
}

int main(int argc, char const *argv[])
{
    
    while (1)
    {
        system("clear");
        switch (menu())
        {
        case 1:
            insertAtBegin();
            break;
        case 2:
            deleteAtEnd();
            break;
        case 3:
            viewList();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice! Please select a valid choice!");
        }
        getchar();
        getchar();
    }
    return 0;
}
