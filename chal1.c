#include <stdio.h>

int main(){
    int temp,i,j;
    int list2[1000];
    int list1[1000];
    for(i = 0;i < 1000;i++){
        scanf("%d %d", &list1[i], &list2[i]);
    }

    for(i = 1;i < 1000;i++){
        for(j = 1000;i > i ;i--){
            if(list1[j] < list1[j-1]){
                temp = list1[j];
                list1[j] = list1[j-1];
                list1[j-1] = temp;
            }
        }
    }
    for(i = 1;i < 1000;i++){
        for(j = 1000;i > i ;i--){
            if(list2[j] < list2[j-1]){
                temp = list2[j];
                list2[j] = list2[j-1];
                list2[j-1] = temp;
            }
        }
    }
    long long int s = 0;
    int d[1000];
    for(i = 0;i < 1000;i++){
        d[i] = list1[i] + list2[i];
        s = s + d[i];
    }
    printf("%lld\n", s);
    return 0;
}