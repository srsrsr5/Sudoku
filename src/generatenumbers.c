#include <stdio.h>
#include <stdlib.h>

int* fisherYates(int n);
void printRandom(int n);
void pop(int** array, int index);
void printArray(int* array, int length);

int main(int argc, char *argv[]) {
    printRandom(4);
    return 0;
}

int* fisherYates(int n) {
    int k, len = n;
    int* numbers = calloc(4, sizeof(int));
    int* shuffled = calloc(4, sizeof(int));
    for(int i = 0; i < 4; i++) {
        numbers[i] = (i+1);
    }
    for(int i = 0; i < n; i++) {
        //Need to pop k index to remove from next selection
        k = rand()%len;
        shuffled[i] = numbers[k];
        pop(&numbers, k);
        len--;
    }
    free(numbers);
    return shuffled;
}

//Pop specific index to shift rest down one
void pop(int** array, int index) {
    int temp = (*array)[index];
    for(int i = index; i < 3; i++) {
        (*array)[i] = (*array)[i+1];
    }
    //Add temp onto end
    (*array)[3] = temp;
}


void printRandom(int n) {
    for(int i = 0; i < n; i++) {
        //Random list of numbers between 1-4 (each 1/4 of puzzle)
        int* numbers = fisherYates(4);
        for(int j = 0; j < n; j++) {
            printf("%d ", numbers[j]);
        }
        free(numbers);
    }
    printf("\n");
    return;
}


void printArray(int* array, int length) {
    for(int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}