// Create node of lists and insert at begining, end & after a node and display the list

#include<stdio.h>
#include<stdlib.h>

// Creating node data type with the help of structure
struct node{
    int data;
    struct node *next;
};

// Function for creating node which returns address of newly created node
struct node* createNode(){
    return (struct node*)malloc(sizeof(struct node));
}

// Creating a new node and inseting them at begining and returning address of head node
struct node* insertAtBegining(struct node *start){
    
    struct node *newNode, *temp = start;
    
    // Create a new node
    newNode = createNode();// A node is created and address of that node stored in newNode

    // insert data in newly created node
    printf("Enter data : ");
    scanf("%d",&newNode->data);
    newNode->next = NULL;// For safe execution

    // Now check is head is null
    if(start==NULL){
        start = newNode;
        printf("Node is linked to list as first node.");
    }
    //Now check if head is not null means list have some nodes
    else{
        newNode->next = start;
        start = newNode;
        printf("Node is linked to list as first node.");
    }
    return start;
}

// Create a function for inserting a node at end of list and return address of head
struct node* insertAtEnd(struct node* start){
    struct node *temp = start;
    if(temp == NULL)
        return insertAtBegining(start);
    else{
        struct node *newNode;
        
        // create new node and insert data into it.
        newNode = createNode();
        printf("Enter data : ");
        scanf("%d",&newNode->data);
        newNode->next = NULL;

        //link newNode at the end of the list.
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        printf("Node is linked to list as last node.");
        return start;
    }
}

// Insert after a postion
struct node* insertAfterNode(struct node *start, int pos,int count){
    // Insert node
    if(pos==0)
        return insertAtBegining(start);
    else if(pos == count)
        return insertAtEnd(start);
    else{
        struct node *newNode, *temp = start;
        int i=1;
        newNode = createNode();
        printf("Enter data : ");
        scanf("%d",&newNode->data);
        while(i<pos){
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        printf("This node is inserted after node %d",pos);
        return start;
    }
}

// function for counting number of nodes
int countNodes(struct node *start){
    struct node *temp = start;
    int c=0;
    if(temp==NULL)
        return 0;
    else{
        while (temp!=NULL){
            c++;
            temp = temp->next;
        }
        return c;
    }
}

// Display the list to stdout
void displayList(struct node *start){
    struct node *temp = start;
    if(temp == NULL)
        printf("List is empty.");
    else{
        printf("List of data [ ");
        while(temp != NULL){
            printf("%d, ",temp->data);
            temp = temp->next;
        }
        printf("\b\b ]\n");
    }
}

int menu(){
    int choice;
    printf("\n1.Insert at start\n");
    printf("2.Insert at End\n");
    printf("3.Insert after a node\n");
    printf("4.Number of nodes in the list.\n");
    printf("5.Display list\n");
    printf("6.Exit\n");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    return choice;
}

int main(int argc, char const *argv[])
{
    struct node *start = NULL;
    int count,position;
    
    while (1){
        system("clear");
        switch (menu()){
        case 1:
            start = insertAtBegining(start);
            break;
        case 2:
            start = insertAtEnd(start);
            break;
        case 3:
            printf("Enter postion to insert a node : ");
            scanf("%d",&position);
            count = countNodes(start);
            if(position<0 || position>count){
                printf("Invalid position! Please, try again!");
            }
            else{
                start = insertAfterNode(start,position,count);
            }
            break;
        case 4:
            count = countNodes(start);
            if(count!=0)
                printf("Number of node : %d",count);
            else printf("List is empty.");
            break;
        case 5:
            displayList(start);
            break;
        case 6:
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