// Create a linked list and perform insert at end and delete at first. And traverse as well.

#include<stdio.h>
#include<stdlib.h>

struct node{
    int marks;
    struct node *link;
};

struct node *start = NULL;

struct node* creteNode(){
    return (struct node*)malloc(sizeof(struct node));
}

void insetNodeatEnd(){
    struct node *temp, *t;
    temp = creteNode();
    printf("Input your mark : ");
    scanf("%d",&temp->marks);
    temp->link = NULL;
    if(start==NULL)
        start = temp;
    else{
        t = start;
        while(t->link!=NULL)
            t = t->link;
        t->link = temp;
    }
}

void deleteAt1st(){
    struct node *del;
    if(start==NULL)
        printf("List is already empty.");
    else{
        del = start;
        start = start->link;
        free(del);
    }
}

void viewList(){
    struct node *visit;
    if(start==NULL)
        printf("List is empty.");
    else{
        printf("Your marks list is [ ");
        visit = start;
        while (visit!=NULL)
        {
            printf("%d, ",visit->marks);
            visit = visit->link;
        }
        printf("\b\b ] \n"); 
    }
}

int menu(){
    int choice;
    printf("\n1.Insert a node at the end\n");
    printf("2.Delete first node\n");
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
            insetNodeatEnd();
            break;
        case 2:
            deleteAt1st();
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
