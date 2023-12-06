#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    int elf = 1;
    int elf_answer = 0;
    int calories = 0;
    int current_calories = 0;
    char buffer[20];

    FILE* input_file;
    input_file = fopen("inputfile.txt", "r");

    if (input_file == NULL) {
        fprintf(stderr, "Failed to open the file.\n");
        exit(EXIT_FAILURE);
    }

    while(fgets(buffer, sizeof buffer, input_file)) {
        if(buffer[0] == '\n') {
            break;
        }
        current_calories += atoi(buffer);
    }

    while(fgets(buffer, sizeof buffer, input_file)) {
        if(buffer[0] == '\n') {
            elf++;
            calories = 0;
        }

        calories += atoi(buffer);
        
        if (calories > current_calories) {
            current_calories = calories;
            elf_answer = elf;
        }
    }

    printf("elfs: %d\n", elf);
    printf("max: %d\n", current_calories);
    printf("elf carrying the most: %d\n", elf_answer);
    fclose(input_file);

    return 0;
}
