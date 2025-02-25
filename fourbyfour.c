#include <stdio.h>

int main(int argc, char *argv[]) { 
    int* array = calloc(16, sizeof(int));
    outputGrid(array);
    free(array);
    return 0;
}


void outputGrid(int *arr) {
    for(int i = 0; i < 16; i++) {
        if((i%2)==0) {
            printf("|");
        }
        if((i%4)==0) {
            printf("\n");
        }
        printf("%d", arr[i]);
    }
    return;
}