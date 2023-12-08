#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

char findCommon(char* first, char* second, char* third, int firstSize, int secondSize, int thirdSize) {

    int i, j, k;

    for(i = 0; i < firstSize; i++) {
        for(j = 0; j < secondSize; j++) {
            if (first[i] == second[j]) {
                for(k = 0; k < thirdSize; k++) {
                    if (second[j] == third[k]) {
                        return first[i];
                    }
                }
            }
        }
    }

    return -1;
}

int calcSum(char c) {
    if (islower(c)) {
        return c - 96;
    } 
    return c - 38;
}

int main(void) {

    FILE* input = fopen("input2.txt", "r");

    if (input == NULL) {
        printf("error opening the file.\n");
        exit(0);
    }

    char common, first[200], second[200], third[200];
    int sum = 0;

    while(fgets(first, sizeof first, input)) {

        fgets(second, sizeof second, input);
        fgets(third, sizeof third, input);

        common = findCommon(first, second, third, strlen(first)-1, strlen(second)-1, strlen(third)-1);
        sum += calcSum(common);
        
    }

    printf("sum %d\n", sum);
    fclose(input);
}
