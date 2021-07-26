// Improverd bubble sort where in best case it will take only theta(N^2) but with less comparisions
// time complexity but in previous one it is taking theta(N^2) in best case also.

#include<stdio.h>

int* bubbleSortImproved(int arr[], int n){
    int temp;
    
    for(int i=0; i<n-1; ++i){
        for(int j=0; j<n-1-i; ++j)
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp; 
            }
    }
    return arr;
}
int main(int argc, char const *argv[])
{
    int arr[5] = {1,2,4,5,3};
    int n=5,*ar;
    ar = bubbleSortImproved(arr,n);
    for(int i=0; i<n; ++i)
        printf("%d ",*(arr+i));
    printf("\n");
    return 0;
}
