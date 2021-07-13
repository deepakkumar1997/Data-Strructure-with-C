// Create a singly linked list till user adding new node and add 5 in the data and display

#include<stdio.h>
#include<stdlib.h>

struct node{
    int mark;
    struct node *next;
};

struct node* createNode(){
    return (struct node*)malloc(sizeof(struct node));
}

struct node* linkNodes(struct node *start){
    struct node *newNode;
    static struct node *temp;
    // Creating a new node
    newNode = createNode();
    // Storing data in new node
    printf("Input mark : ");
    scanf("%d",&newNode->mark);
    newNode->next = NULL;
    if(start==NULL)
        start = temp = newNode;
    else{
        temp->next = newNode;
        temp = newNode;
    }
    return start;
}

void displayList(struct node *start){
    struct node *temp = start;
    if(temp == NULL)
        printf("List is empty.");
    else{
        printf("Final list of marks is [ ");
        while (temp != NULL){
            printf("%d, ",(temp->mark+5));
            temp = temp->next;
        }
        printf("\b\b ]\n");
    }
}

int menu(){
    int choice;
    printf("\n1.Create a node and link it to list\n");
    printf("2.Display list\n");
    printf("3.Exit\n");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    return choice;
}

int main(int argc, char const *argv[])
{
    struct node *start = NULL;

    while (1){
        system("clear");
        switch (menu()){
        case 1:
            start = linkNodes(start);
            printf("Node is linked to list.");
            break;
        case 2:
            displayList(start);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice! Please enter a valid choice!");
            break;
        }
        getchar();
        getchar();
    }   
    return 0;
}