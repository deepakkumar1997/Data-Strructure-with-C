#include<stdio.h>
#include<stdlib.h>

// Making node of list
struct node{
    int data;
    struct node *next;
};

// creation of a new node
struct node* createNode(){
    return (struct node*)malloc(sizeof(struct node));
}

// Insert a node at the end of list
struct node* insertAtTail(struct node *head){
    struct node *new , *temp;
    // call createNode for 
    new = createNode();
    printf("Enter an integer : ");
    scanf("%d",&new->data);
    new->next = NULL;
    if(head==NULL){
        head = new;
        return head;
    }
    else{
        temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = new;
        return head;
    }
}

// Display the list
void displayList(struct node *head){
    if(head==NULL)
        printf("List is empty\n");
    else{
        struct node *temp = head;
        printf("List is : ");
        while(temp!=NULL){
            printf("%d->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

//Reverse linked list iteratively
struct node* reverseSLL(struct node *head){
    struct node *prevPtr, *nextPtr, *currPtr=head;
    if(currPtr==NULL)
        return currPtr;
    else{
        prevPtr = nextPtr = NULL;
        while(currPtr!=NULL){
            nextPtr = currPtr->next;
            currPtr->next = prevPtr;
            prevPtr = currPtr;
            currPtr = nextPtr;
        }
        return prevPtr;
    }
}

// Reverse linked list recursively
struct node* reverseSLLrecur(struct node *currPtr){
    if(currPtr==NULL||currPtr->next==NULL)
        return currPtr;
    struct node *newHead;
    newHead = reverseSLLrecur(currPtr->next);
    currPtr->next->next = currPtr;
    currPtr->next = NULL;
    return newHead;
    
}

int menu(){
    int choice;
    printf("\n1.Insert a node at the end\n");
    printf("2.Reverse Linked List Iteratively\n");
    printf("3.Reverse Linked List Recursively\n");
    printf("4.View list\n");
    printf("5.exit\n");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    return choice;
}

int main(int argc, char const *argv[])
{
    struct node *head=NULL;
    while (1)
    {
        system("clear");
        switch (menu())
        {
        case 1:
            head = insertAtTail(head);
            printf("Node inserted");
            break;
        case 2:
            head = reverseSLL(head);
            if(head==NULL) printf("List is empty\n");
            else printf("List reversed iteratively");
            break;
        case 3:
            head = reverseSLLrecur(head);
            if(head==NULL) printf("List is empty\n");
            else printf("List reversed Recursively");
            break;
        case 4:
            displayList(head);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice! Please select a valid choice!");
        }
        getchar();
        getchar();
    }
    
    return 0;
}