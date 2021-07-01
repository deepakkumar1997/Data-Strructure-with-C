// Take value of nth term from user and print the fibonacci number of that term-n;

#include<stdio.h>

long int fibonacci(int n){
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

int main(int argc, char const *argv[])
{
    
    int n;
    printf("Input value of n : ");
    scanf("%d",&n);
    printf("Fibonacci number at term %d is %ld\n",n,fibonacci(n));
    return 0;
}
