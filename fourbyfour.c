#include <stdio.h>
#include <stdlib.h>

void outputGrid(int* arr);

int main(int argc, char *argv[]) { 
    int* array = calloc(16, sizeof(int));
    outputGrid(array);
    free(array);
    printf("\n");
    return 0;
}


void outputGrid(int *arr) {
    for(int i = 0; i < 16; i+=4) {
        printf("|%d%d|%d%d|\n", arr[i], arr[i+1], arr[i+2], arr[i+3]);
    }
    return;
}