#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Function prototypes
void writeInputFile();
void calculateAndWriteOutput();
void displayFilesContent();

int main() {
    writeInputFile();
    calculateAndWriteOutput();
    displayFilesContent();
    return 0;
}

// Function to prompt user to enter 10 integers and write them to "input.txt"
void writeInputFile() {
    FILE *file = fopen("input.txt", "w");
    if (file == NULL) {
        perror("Error opening input.txt for writing");
        exit(EXIT_FAILURE);
    }

    int num;
    printf("Enter %d integers:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        if (scanf("%d", &num) != 1) {
            printf("Invalid input. Exiting.\n");
            fclose(file);
            exit(EXIT_FAILURE);
        }
        fprintf(file, "%d\n", num);
    }

    fclose(file);
}

// Function to read integers from "input.txt", calculate sum and average, and write to "output.txt"
void calculateAndWriteOutput() {
    FILE *inFile = fopen("input.txt", "r");
    if (inFile == NULL) {
        perror("Error opening input.txt for reading");
        exit(EXIT_FAILURE);
    }

    int numbers[SIZE];
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        if (fscanf(inFile, "%d", &numbers[i]) != 1) {
            printf("Error reading number from input.txt\n");
            fclose(inFile);
            exit(EXIT_FAILURE);
        }
        sum += numbers[i];
    }
    fclose(inFile);

    double average = (double)sum / SIZE;

    FILE *outFile = fopen("output.txt", "w");
    if (outFile == NULL) {
        perror("Error opening output.txt for writing");
        exit(EXIT_FAILURE);
    }

    fprintf(outFile, "Sum: %d\n", sum);
    fprintf(outFile, "Average: %.2f\n", average);
    fclose(outFile);
}

// Function to display content of both "input.txt" and "output.txt"
void displayFilesContent() {
    FILE *file;
    char ch;

    printf("\nContent of input.txt:\n");
    file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening input.txt for reading");
        exit(EXIT_FAILURE);
    }
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);

    printf("\nContent of output.txt:\n");
    file = fopen("output.txt", "r");
    if (file == NULL) {
        perror("Error opening output.txt for reading");
        exit(EXIT_FAILURE);
    }
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);
}