// Take two numbers from user and find gcd, gcf, hcf, hcm;

#include<stdio.h>

int GCD(int num1, int num2){
    if(num1==num2 || num2%num1==0)
        return num1;
    else if(num1%num2==0)
        return num2;
    else if(num1>num2)
        return GCD(num1%num2, num2);
    else return GCD(num1, num2%num1);
}

int main(int argc, char const *argv[])
{
    
    int n1,n2;
    printf("Input two numbers to find GCD : ");
    scanf("%d%d",&n1,&n2);
    printf("GCD(%d,%d) is %d\n",n1,n2,GCD(n1,n2));
    return 0;
}
