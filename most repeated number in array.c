#include <stdio.h>
int main(){
    int arr[]={10,20,30,10,40,10};
    int maxcount=0;
    int mostrepeated;

    for (int i=0;i<6;i++){
        int count=0;

        for (int j=0;j<6;j++){
            if (arr[i]=arr[j]){
                count =count+1;
            }
        }

        if(count>maxcount){
            maxcount=count;
            mostrepeated=arr[i];
        }
    }
    printf("most repeated number is %d",mostrepeated);
    return 0;

}