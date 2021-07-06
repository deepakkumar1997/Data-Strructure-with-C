// Create a linkde list and reverse it then print it.

#include<stdlib.h>
#include<stdio.h>

struct node
{
    char name[20];
    struct node *next;
};

struct node *start = NULL;

struct node* createNode(){
    return (struct node*)malloc(sizeof(struct node));
}

void insertNodeAtEnd(){
    struct node *new, *temp;
    new = createNode();
    printf("Input name : ");
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
    scanf("%[^\n]%*c",new->name);
    new->next = NULL;
    if(start==NULL)
        start = new;
    else{
        temp = start;
        while (temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
    }
}

void deleteAt1st(){
    struct node *delNode;
    if(start==NULL)
        printf("List is already empty.");
    else{
        delNode = start;
        start = start->next;
        free(delNode);
    }
}

void viewList(){
    struct node *currNode;
    currNode = start;
    if(start==NULL)
        printf("List is empty.");
    else{
        printf("List of name is [ ");
        while (currNode!=NULL)
        {
            printf("%s, ",currNode->name);
            currNode = currNode -> next;
        }
        printf("\b\b ] \n");  
    }  
}

struct node* reverseLinkedList(){
    struct node* temp1, *temp2;
    if(start==NULL)
        return NULL;
    else{
        temp1 = temp2 = NULL;
        while (start!=NULL)
        {
            temp2 = start->next;
            start->next = temp1;
            temp1 = start;
            start = temp2;
        }
    }
    return temp1;
}

int menu(){
    int choice;
    printf("\n1.Insert a node at the end\n");
    printf("2.Delete first node\n");
    printf("3.View list\n");
    printf("4.Reverse Linked List\n");
    printf("5.exit\n");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    return choice;
}

int main(){
    struct node *reverseStart;
    while (1)
    {
        system("clear");
        switch (menu())
        {
        case 1:
            insertNodeAtEnd();
            break;
        case 2:
            deleteAt1st();
            break;
        case 3:
            viewList();
            break;
        case 4:
            reverseStart = reverseLinkedList();
            if(reverseStart==NULL)
                printf("List is empty. Nothing to reverse here!\n");
            else{
                start = reverseStart;
                printf("Linked List is reversed.\n");
            }
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