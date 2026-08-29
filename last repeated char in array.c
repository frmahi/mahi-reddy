#include <stdio.h>
int main(){
    char arr[]={'d','c','b','a','d','b'};

    for (int i=5;i>0;i--){
        for (int j=i-1;j>0;j--){
            if (arr[i]==arr[j]){
                printf("last repeated char=%c",arr[i]);
                return 0;
            }
        }
    }
    return 0;
}