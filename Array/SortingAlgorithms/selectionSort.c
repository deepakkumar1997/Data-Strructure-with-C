// Tale some elements and sort using selection sort algorithm

#include<stdio.h>

int min(int *arr, int k, int n){
    int index;
    int min = arr[k];
    index = k;
    while(k<n){
        if(min > arr[k]){
            min = arr[k];
            index = k ;
        }
        ++k;
    }
    return index;
}

void selectionSort(int *arr, int n){
    int k,temp;
    for(int i=0; i<n-1; ++i){
        k = min(arr, i, n);
        temp = arr[k];
        arr[k] = arr[i];
        arr[i] = temp;
    }
}

int main(int argc, char const *argv[])
{
    int arr[6] = {2,56,0,3,7,-1}, n=6;
    //printf("%d \n",min(arr,0,n));
    selectionSort(arr,n);
    for(int i=0; i<n; ++i)
        printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
