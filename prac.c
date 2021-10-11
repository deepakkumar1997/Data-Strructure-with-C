#include<stdio.h>
#include<stdlib.h>

struct node* reverseLL(struct node *head){
    struct node *temp1,*temp2;
    if(head==NULL)
        return NULL;
    else{
        temp1 = temp2 = NULL;
        while(head!=NULL){
            temp2 = head->next;
            head->next = temp1;
            temp1 = head; 
            head = temp2;
        }
    }
}