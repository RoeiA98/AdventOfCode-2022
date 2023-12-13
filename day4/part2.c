#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(void) {

    FILE* input = fopen("input2.txt", "r");
    int counter = 0;
    int a, b, c, d = 0;

    while(fscanf(input,"%d-%d, %d-%d\n", &a, &b, &c, &d) > 0) { // ! fscanf() READS TILL EOF

        if ((b < c) || (a > d)) {
            continue;
        } 
        counter++;
    }

    printf("answer: %d\n", counter);
    fclose(input);
    return 0;
}
