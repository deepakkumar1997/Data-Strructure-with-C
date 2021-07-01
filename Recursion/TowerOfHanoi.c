// Tower of Hanoi for three rods.

#include<stdio.h>
int c=0;
int towerOfHanoi(int n, char beg[], char aux[], char end[]){
    if(n>=1){
        c++;
        towerOfHanoi(n-1, beg, end, aux);
        printf("%s to %s\n",beg,end);
        towerOfHanoi(n-1, aux, beg, end);
    }
    return c;
}

int main(int argc, char const *argv[])
{
    
    int n;
    char rod1, rod2, rod3;
    printf("Input number of disk : ");
    scanf("%d",&n);
    //printf("Enter name of rods : ");
    //scanf("%c %c %c",&rod1,&rod2,&rod3);
    int count = towerOfHanoi(n,"SRC","Aux","DEST");
    printf("No. of moves : %d\n",count);
    return 0;
}
