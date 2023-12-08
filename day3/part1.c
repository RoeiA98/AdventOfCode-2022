#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

char findCommon(char* first, char* second, int size) {

    int i, j;

    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            if (first[i] == second[j]) {
                return first[i];
            }
        }
    }

    return 0;
}

int calcSum(char c) {
    if (islower(c)) {
        return c - 96;
    } 
    return c - 38;
}

int main(void) {

    FILE* input = fopen("input.txt", "r");

    if (input == NULL) {
        printf("error opening the file.\n");
        exit(0);
    }

    char buffer[200], *firstHalf, *secondHalf, common;
    int sum = 0, size;

    while(fgets(buffer, sizeof buffer, input)) {

        size = (strlen(buffer) - 1) / 2;

        firstHalf = (char*)malloc(sizeof(char)*(size_t)size);
        secondHalf = (char*)malloc(sizeof(char)*(size_t)size);

        memcpy(firstHalf, buffer, size);
        memcpy(secondHalf, buffer+size, size);

        common = findCommon(firstHalf, secondHalf, size);
        sum += calcSum(common);
        
    }

    printf("sum %d\n", sum);
    free(firstHalf);
    free(secondHalf);
    fclose(input);
}
