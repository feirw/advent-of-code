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
    }
    for (int i = 0; i < 1000; i++) {
        for(int m = 1;m >= 0;--m){
            int is_safe = 1;
            for(int k = 0; k < levels[i];k++){
                is_safe = 1;
                for (int j = 1; j < levels[i]; j++) {
                    int tm = 0;
                    if(k == 0 && j == 1) continue;
                    else if(k == j){
                        if (j == levels[i] - 1) continue;
                        tm = ((array[i][j+1] < array[i][j - 1]) && m)
                        || ((array[i][j+1] > array[i][j - 1]) && !m);
                        sub = labs(array[i][j+1] - array[i][j - 1]);
                        ++j;
                    }
                    else {
                        tm = ((array[i][j] < array[i][j - 1]) && m)
                        || ((array[i][j] > array[i][j - 1]) && !m);
                        sub = labs(array[i][j] - array[i][j - 1]);
                    }
                    if (!tm || sub < 1 || sub > 3) {
                        is_safe = 0;
                        break;
                    }

                }
                if(is_safe){
                    break;
                }
            }
            if (is_safe) {
                safe_reports += 1;
                break;
            }
        }
    }
    printf("%d\n", safe_reports);
    return 0;
}