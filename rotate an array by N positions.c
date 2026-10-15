#include <stdio.h>
int main(){
    int arr[]={1,2,3,4,5};
    int n =5, N = 2;
    int i,temp;

    N = N % n;

    for (i=0; i<n; i++){
        temp = arr[n-1];
         
        for (int j=n-1; j>0; j--){
            arr[j] = arr[j - 1];
        }

        arr[0] = temp;
    }

    printf("Rotated array:");
    for (i=0; i<n; i++){
        printf("%d",arr[i]);
    }

    return 0;
}