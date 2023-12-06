#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void positionCalories(int* arr, int num) {
    
    mergeSort(arr, 0, 3);
    int i;
    for(i = 0; i < 3; i++) {
        if (num >= arr[i]) {
            arr[i] = num;
            return;
        }
    }
}

int main(void) {

    int i;
    int final_answer = 0;
    int calories = 0;
    int current_calories = 0;
    char buffer[20];
    int top_three[3] = { 0 };

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

    top_three[0] = current_calories;

    while(fgets(buffer, sizeof buffer, input_file)) {
        if(buffer[0] == '\n') {
            positionCalories(top_three, calories);
            calories = 0;
        }
        calories += atoi(buffer);
    }

    for(i = 0; i < 3; i++) {
        // printf("%d\n", top_three[i]);
        final_answer += top_three[i];
    }

    printf("\n");
    printf("%d\n", final_answer);
    fclose(input_file);

    return 0;
}
