// Take a string input from user and print all permutation of that string

#include<stdio.h>
#include<string.h>

void swap(char *ch1, char *ch2){
    char temp = *ch1;
    *ch1 = *ch2;
    *ch2 = temp;
}

void permutationStr(char *str, int i, int n){
    static int count;
    int j;
    if(i==n){
        ++count;
        printf("(%d) ~ %s, ",count,str);
    }
    else
        for(j=i; j<=n; ++j){
            swap((str+i),(str+j));
            permutationStr(str, i+1, n);
            swap((str+i),(str+j));//Backtracking
        }
}

int main(int argc, char const *argv[])
{
    
    char str[10];
    printf("Input a string to find its permutation : ");
    scanf("%[^\n]%*c",str);
    permutationStr(str, 0, strlen(str)-1);
    printf("\b\b \n");
    return 0;
}