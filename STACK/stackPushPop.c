// In this program I'm going to implement operation of stack : push, pop and display the stack.
#include<stdio.h>
#include<stdlib.h>

//Making a new data type named arrayStack which is going to hold top of stack, capacity, and
// array pointing to data elements
struct arrayStack{
    int top;
    unsigned capacity;
    int *arr;
};

// creation of a stack
struct arrayStack* createStack(int cap){
    struct arrayStack *stack;
    stack = (struct arrayStack*)malloc(sizeof(struct arrayStack));
    stack->top = -1;
    stack->capacity = cap;
    stack->arr = (int*)malloc(sizeof(stack->arr)*stack->capacity);
    return stack;
}

// Now check is stack is full
int isFull(struct arrayStack *stack){
    if(stack->top==stack->capacity-1)
        return 1;
    else return 0;
}

// Now check is stack is empty
int isEmpty(struct arrayStack *stack){
    if(stack->top==-1)
        return 1;
    else return 0;
}

// Push the element into stack or insert the element into stack
void push(struct arrayStack *stack, int data){
    if(!isFull(stack)){
        stack->top++;
        stack->arr[stack->top] = data;
        printf("%d is pushed in stack",data);
    }
    else printf("Stack Overflow");
}

// delete operation or pop operation
void pop(struct arrayStack *stack){
    if(!isEmpty(stack)){
        int item = stack->arr[stack->top];
        stack->top--;
        printf("%d is popped out",item);
    }
    else printf("Stack Underflow");
}

void displayCurrentStack(struct arrayStack *stack){
    if(!isEmpty(stack)){
        printf("\nElement in stack : ");
        for(int i=0; i<=stack->top; ++i){
            printf("%d ",stack->arr[i]);
        }
    }
    else printf("Stack is Empty or stack underflow");
    printf("\n");
}

int main(int argc, char const *argv[])
{
    
    struct arrayStack *stack;
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
            push(stack,item);
            break;
        
        case 2:
            pop(stack);
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