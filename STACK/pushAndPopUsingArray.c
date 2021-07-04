// Take some elements from user and push into stack then pop it.

#include<stdio.h>
#include<stdlib.h>

typedef enum{
    false, true
}bool;

struct stackArray
{
    int top;
    unsigned int capacity;
    int *array;
};

struct stackArray* createStack(int sizeofArray){
    struct stackArray *stack = (struct stackArray*)malloc(sizeof(struct stackArray));
    stack->top = -1;
    stack->capacity =  sizeofArray;
    stack->array = (int*)malloc(sizeofArray*sizeof(int));
    return stack;
}

bool isFull(struct stackArray *stack){
    if(stack->top==(stack->capacity-1))
        return true;
    else
        return false;
}

bool isEmpty(struct stackArray *stack){
    if(stack->top==-1)
        return true;
    else return false;
}

bool push(struct stackArray *stack, int item){
    // First we will check if stack is full or not if it is full then return false else inset it
    if(!isFull(stack)){
        stack->top++;
        stack->array[stack->top] = item;
        return true;
    }
    else return false;
}

bool pop(struct stackArray *stack){
    if(isEmpty(stack))
        return false;
    else{
        stack->top--;
        return true;
    }
}

void displayCurrentStack(struct stackArray *stack){
    if(!isEmpty(stack)){
        printf("\nElement in stack : ");
        for(int i=0; i<=stack->top; ++i){
            printf("%d ",stack->array[i]);
        }
    }
    else printf("Stack is Empty.");
    printf("\n");
}

int main(int argc, char const *argv[])
{
    
    struct stackArray *stack;
    int numberOfItem,ch,item;
    printf("How many elements do you want to enter in the stack : ");
    scanf("%d",&numberOfItem);
    stack = createStack(numberOfItem);
    while(1){
        system("clear");
        printf("\n1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter an element : ");
            scanf("%d",&item);
            if(push(stack,item)){
                printf("Element %d is inserted.\n",item);
            }
            else printf("Stack is full. You can't insert any element now.\n");
            break;
        
        case 2:
            if(pop(stack)){
                printf("Element %d is popped out.\n",stack->array[stack->top+1]);
                printf("Element %d is popped out.\n",stack->top[stack->array+1]);//Magic
            }
            else printf("Stack is already empty.\n");
            break;
        
        case 3:
            displayCurrentStack(stack);
            break;
        case 4:
            exit(0);
        
        default:
            printf("Wrong Choice! Please choose a correct choice.\n");
            break;
        }
        getchar();
        getchar();
    }
    return 0;
}