//An optimized code for sorting elements like bubble in best case which is array is already 
//Sorted then it only take theta(N) time to sort the elements.

#include<stdio.h>

void optimizedBubbleSort(int arr[], int n){
    int temp,flag;
    for(int i=0; i<n-1; ++i){
        flag = 0;
        for(int j=0; j<n-i-1; ++j)
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag=1;
            }
        if(flag==0)
            break;
    }
    for(int i=0; i<n; ++i)
        printf("%d ",arr[i]);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int arr[5] = {1,1,3,3,5}, n=5;
    optimizedBubbleSort(arr,n);
    return 0;
}
