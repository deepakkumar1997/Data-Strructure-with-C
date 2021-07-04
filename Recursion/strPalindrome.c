// Take a string from user and find it is palindrome or not using recursion.

#include<stdio.h>
#include<string.h>

typedef enum{
    false, true
}bool;

bool strPalindrome(char *str, int i, int l){
    if(i>=l)
        return true;
    else if(str[i]!=str[l])
        return false;
    else
        return strPalindrome(str, i+1, l-1);
}

int main(int argc, char const *argv[])
{
    char s[20];
    printf("Input a string to check palindrome : ");
    scanf("%[^\n]%*c",s);
    if(strPalindrome(s, 0, strlen(s)-1))
        printf("It is a palindrome.\n");
    else printf("It is not a palindrome.\n");
    return 0;
}