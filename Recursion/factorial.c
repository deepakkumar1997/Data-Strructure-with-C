/* Take a integer as an input from user and print factorial of that integer number. */

#include<stdio.h>

unsigned long long factorial(int n){
    if(n==1)
        return 1;
    else 
        return n*factorial(n-1);
}

int main(int argc, char const *argv[])
{
    
    int n;
    printf("Input an integer number to find its factorial : ");
    scanf("%d",&n);
    printf("Factorial of %d is %llu\n",n,factorial(n));
    return 0;
}