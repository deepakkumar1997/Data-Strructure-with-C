/* Take an list of array from user and sort it in ascending order using bubble sort. */

#include<stdio.h>

void bubbleSortConventional(int *arr, int n){
    int temp;
    for(int i =0; i<n-1; ++i)
        for(int j=0; j<n-1; ++j){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;                
            }
        }
}

int main(int argc, char const *argv[])
{
    int arr[5] = {5,4,3,2,1};
    int n=5;
    bubbleSortConventional(arr,n);
    for(int i=0; i<n; ++i)
        printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
