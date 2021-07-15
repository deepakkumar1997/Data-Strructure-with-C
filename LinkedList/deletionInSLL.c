// Take a linked list and perform delete operation at begining, end and after a node

#include<stdio.h>
#include<stdlib.h>

//create node data type with the help of structure
struct node{
    int data;
    struct node *next;
};

// function for creating node and returning address of that node
struct node* createNode(){
    return (struct node*)malloc(sizeof(struct node));
}

// Insertion operations
struct node* insertDataAndLink(struct node *head){
    struct node *newNode;
    static struct node *temp;
    // Crrate a node
    newNode = createNode();
    //insert data into node
    printf("Input data : ");
    scanf("%d",&newNode->data);
    newNode->next = NULL;
    // Link node to the list
    if(head==NULL)
        head = temp = newNode;
    else{
        temp->next = newNode;
        temp = newNode;
    }
    return head;
}

// Delete node at begining
struct node* deleteAtBegining(struct node *head){
    struct node *delNode;
    if(head==NULL){
        printf("List is empty.");
        return NULL;
    }
    else{
        // First store 1st node address to the delNode(pointer to node)
        delNode = head;
        // Now head pointing to 1st node so now take head pointer to 2nd node or increment head by one node
        head = head->next;
        // Now you can free 1st node which address is stored in delNode(pointer to node)
        printf("First node with data [%d] is freed.",delNode->data);
        free(delNode);
    return head;
    }
}

// Delete last node
struct node* deleteLastNode(struct node *head){
    struct node *delLast, *temp = head;
    if(head == NULL){
        printf("List is already empty.");
        return NULL;
    }
    else{
        // Traverse through list and reach till last node
        while(temp->next!=NULL){
            delLast = temp;// delLast will point 2nd last node
            temp = temp->next;
        }
        if(temp==head){
            printf("First node with data [%d] is freed.",temp->data);
            head = NULL;
        }
        else{
            printf("Last node with data [%d] is freed",temp->data);
            delLast->next = NULL;
        }
        free(temp);
    }
    return head;
}

// Delete node after a position
struct node* deleteAtPosition(struct node *head, int count, int pos){
    if(pos==1)
        return deleteAtBegining(head);
    else if(pos==count)
        return deleteLastNode(head);
    else{
        struct node *delNode, *temp = head;
        int i=1;
        while(i<pos-1){
            temp = temp->next;
            ++i;
        }
        delNode = temp->next;
        temp->next = delNode->next;
        printf("Node %d with data[%d] is freed.",pos,delNode->data);
        free(delNode);
        return head;
    }
}

// Count nodes and return no. of nodes
int countNodes(struct node *head){
    int count=0;
    struct node *temp = head;
    if(head==NULL)
        count=0;
    else{
        while(temp!=NULL){
            ++count;
            temp = temp->next;
        }
    }
    return count;
}

void displayList(struct node *start){
    struct node *temp = start;
    if(temp == NULL)
        printf("List is empty.");
    else{
        printf("Data list is [ ");
        while (temp != NULL){
            printf("%d, ",(temp->data));
            temp = temp->next;
        }
        printf("\b\b ]\n");
    }
}

int menu(){
    int choice;
    printf("\n1.Create a node and link it to list\n");
    printf("2.Delete first node\n");
    printf("3.Delete last node\n");
    printf("4.Delete at a position\n");
    printf("5.Count Nodes\n");
    printf("6.Display list\n");
    printf("7.Exit\n");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    return choice;
}

int main(int argc, char const *argv[])
{
    struct node *start = NULL;
    int count,pos;
    while (1){
        system("clear");
        switch (menu()){
        case 1:
            start = insertDataAndLink(start);
            printf("Node is linked to list.");
            break;
        case 2:
            start = deleteAtBegining(start);
            break;
        case 3:
            start = deleteLastNode(start);
            break;
        case 4:
            if(start==NULL)
                printf("List is empty.");
            else{
                printf("Input position to delete node : ");
                scanf("%d",&pos);
                count = countNodes(start);
                if(pos<1 || pos>count)
                    printf("Invalid Position! Please, try again!");
                else start = deleteAtPosition(start, count, pos);
            }
            break;
        case 5:
            count = countNodes(start);
            if(count==0) printf("List is empty.");
            else printf("Number of node : %d",count);
            break;
        case 6:
            displayList(start);
            break;
        case 7:
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
