// Take some elements from user and sort the element using insetion sort.

#include<stdio.h>

void insertionSort(int *arr, int n){
    int temp;
    int i=1;
    while(i<n){
        temp = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = temp;
        ++i;
    }
}

int main(int argc, char const *argv[])
{
    int arr[6] = {45,67,23,7,2,87}, n = 6;
    insertionSort(arr,n);
    for(int i=0; i<n; ++i)
        printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
