#include <stdio.h>
#include <stdlib.h>

int* getMappedColumn(int key);
int* getMappedRow(int key);
int* fisherYates(int n);
void printRandom(int n);
void pop(int** array, int index);
void addZeros(int **array, int n);
void printArray(int* array, int length);
// void validateStart(int **array);
int hashFunctionColumn(int x);
int hashFunctionRow(int x);

typedef struct {
    int values[4];
} sudokuHash;

static sudokuHash columnMap[] = {
    {{0, 2, 8, 10}},
    {{1, 3, 9, 11}},
    {{4, 6, 12, 14}},
    {{5, 7, 13, 15}},
};

static sudokuHash rowMap[] = {
    {{0, 1, 4, 5}},
    {{2, 3, 6, 7}},
    {{8, 9, 12, 13}},
    {{10, 11, 14, 15}},
};

int main(int argc, char *argv[]) {
    srand(50);
    printRandom(4);
    return 0;
}

int* getMappedColumn(int value) {
    int index = hashFunctionColumn(value);
    return columnMap[index].values;
};

//Return the correct index based off f
int hashFunctionColumn(int x) {
    if( (x%4 == 0) || (x%4 == 2) ) {
        return ( ((x/4)%2) * 2);
    } else {
        return ( (((x/4)%2) * 2) + 1);
    }
    return -1;
}

int* getMappedRow(int value) {
    int index = hashFunctionRow(value);
    return rowMap[index].values;
}

int hashFunctionRow(int x) {
    return ((x / 4)%2)*2 + (x%4)/2;
}

//Print int array
void printArray(int* array, int length) {
    for(int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
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

void addZeros(int **array, int n) {
    int temp, probZero = 65;
    for(int i = 0; i < n; i++) {
        temp = rand()%100;
        if(temp > probZero) {
            (*array)[i] = 0;
        }
    }
}

//Create sudoku and print in a single line
void printRandom(int n) {
    for(int i = 0; i < n; i++) {
        //Random list of numbers between 1-4 (each 1/4 of puzzle)
        int* numbers = fisherYates(4);
        addZeros(&numbers, 4);
        //Make sure numbers valid

        printArray(numbers, 4);
        free(numbers);
    }
    printf("\n");
    return;
}

/*
    | [0]  [1] | [4]   [5] |
    | [2]  [3] | [6]   [7] |
    ------------------------
    | [8]  [9] | [12] [13] |
    | [10] [11]| [14] [15] |
*/
