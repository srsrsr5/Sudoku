#include <stdio.h>
#include <stdlib.h>

void outputGrid(int* arr);

int main(int argc, char *argv[]) { 

   if(argc != 17) {
    printf("Not correct number of arguments\n");
    return 1;
   }
   int* array = calloc(16, sizeof(int));
   for(int i = 0; i < 16; i++) {
    array[i] = *argv[i+1] - 48;
   }    
    outputGrid(array);
    printf("\n");
    return 0;
}

void outputGrid(int *arr) {
    for(int i = 0; i < 16; i+=4) {
        printf("|%d%d|%d%d|\n", arr[i], arr[i+1], arr[i+2], arr[i+3]);
    }
    return;
}

