#include <stdio.h>
#include <stdlib.h>

int main() {
    int result,sub,ch;
    int array[1000][8], levels[1000];
    int plithos, count, safe_reports = 0;
    
    // read and count of elements
    for (int i = 0; i < 1000; i++) {
        count = 0; 
        for (int j = 0; j < 8; j++) {
            result = scanf("%d", &array[i][j]);
            if (result != 1) {
                break;
            }
            ch = getchar();
            count++;
            if(ch == '\n'){
                break;
            }
        }
        levels[i] = count; 
        // counting the number of elements in each line
    }
    for(int i = 0;i < 1000;i++){
        for(int j = 0;j < levels[i];j++){
            printf("%d%s", array[i][j],j == levels[i]-1?"":" ");
        }
        printf("\n");
    }
    for (int i = 0; i < 1000; i++) {
        plithos = 0;
        for (int j = 1; j < levels[i]; j++) {
            if (array[i][j] < array[i][j - 1]) {
                plithos++; // checking if it is in Descending order
            }
        }
        
        // checking if it is in descending or ascending order
        if (plithos == 0 || plithos == levels[i] - 1) {
            int is_safe = 1;
            for (int j = 1; j < levels[i]; j++) {
                sub = labs(array[i][j] - array[i][j - 1]);
                if (sub < 1 || sub > 3) {
                    is_safe = 0;
                    break;
                }
            }
            if (is_safe) {
                safe_reports += 1;
            }
        }
    }
    printf("%d\n", safe_reports);
    return 0;
}