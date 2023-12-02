#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
    FILE *file = fopen("input.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    char** calibrationValue = (char**)malloc(sizeof(char*) * 1); // Allocate space for an array of strings
    char value[100];
    int index = 0;
    int size = 0;

    while (fgets(value, 100, file)) {
        char firstDigit[2];
        char secondDigit[2];
        size++;

        for (int i = 0; i < strlen(value); i++) {
            if (isdigit(value[i])) {
                firstDigit[0] = value[i];
                break;
            }
        }

        for (int i = strlen(value) - 1; i >= 0; i--) {
            if (isdigit(value[i])) {
                secondDigit[0] = value[i];
                break;
            }
        }

        firstDigit[1] = '\0'; // Null-terminate the string
        secondDigit[1] = '\0'; // Null-terminate the string

        char* concatenatedDigit = (char*)malloc(strlen(firstDigit) + strlen(secondDigit) + 1);
        strcpy(concatenatedDigit, firstDigit);
        strcat(concatenatedDigit, secondDigit);

        calibrationValue[index] = concatenatedDigit;

        char** calibrateArray = (char**)realloc(calibrationValue, (size + 1) * sizeof(char*));
        calibrationValue = calibrateArray;
        index++;
    }

    fclose(file);

    int toInt = 0;
    for (int i = 0; i < size; i++) {
        toInt += atoi(calibrationValue[i]);
        free(calibrationValue[i]); 
    }

    free(calibrationValue); 

    printf("%d\n", toInt);

    return 0;
}
