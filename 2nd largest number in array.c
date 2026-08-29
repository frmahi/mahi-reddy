#include <stdio.h>
int main(){
    int arr[]={10,20,30,50,40};
    int largest=arr[0];
    int second= arr[0];

    for (int i=1;i<5;i++){
        if (arr[i]>largest){
            second = largest;
            largest = arr[i];
        }
        else if(arr[i]>second){
            second=arr[i];
        }
    }
    printf("second largest number%d\n",second);

    return 0;

}