#include <stdio.h>
int main(){
    char arr[]={'a','b','c','d','a','b'};

    for (int i=0;i<6;i++){
        for (int j=j+1;j<6;j++){
            if (arr[i]==arr[j]){
                printf("first repated char=%c",arr[i]);
                return 0;
            }
        }
    }
    return 0;
}