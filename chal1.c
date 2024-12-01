#include <stdio.h>
#include <stdlib.h>

int main(){
    int temp,i,j,result;
    int list2[1000];
    int list1[1000];
    for(i = 0;i < 1000;i++){
        result = scanf("%d %d", &list1[i], &list2[i]);
        if(result != 2){
            return 1;
        }
    }
    for(i = 1;i < 1000;i++){
        for(j = 999;j > 0 ;j--){
            if(list1[j] < list1[j-1]){
                temp = list1[j];
                list1[j] = list1[j-1];
                list1[j-1] = temp;
            }
        }
    }
    for(i = 1;i < 1000;i++){
        for(j = 999;j > 0 ;j--){
            if(list2[j] < list2[j-1]){
                temp = list2[j];
                list2[j] = list2[j-1];
                list2[j-1] = temp;
            }
        }
    }
    long long int s = 0;
    for(i = 0;i < 1000;i++){
        s = s + labs(list1[i] - list2[i]);
    }
    printf("%lld\n", s);
    return 0;
}