#include <stdio.h>

int main(){
    //initializing arrays
    int plithos[1000],i,j,result,sim[1000],list2[1000],list1[1000];
    int s = 0;

    //getting the numbers
    for(i = 0;i < 1000;i++){
        result = scanf("%d %d", &list1[i], &list2[i]);
        if(result != 2){
            return 1;
        }
    }
    for(i = 0;i < 1000;i++){
        plithos[i] = 0;
    }
    for(i = 0;i < 1000;i++){
        //finding how many times one element of list1 appears to list2
        for(j = 0;j < 1000;j++){
            if(list1[i] == list2[j]){
                plithos[i] +=1;
            }
        }
        //calculating similarity
        sim[i] = list1[i]*plithos[i];
    }
    //calculating the sum of all similarities
    for(i = 0;i < 1000;i++){
        s += sim[i];
    }
    printf("%d\n", s);
    return 0;
}