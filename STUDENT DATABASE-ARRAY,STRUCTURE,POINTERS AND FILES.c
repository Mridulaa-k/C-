#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure called Student
struct Student {
    char name[50];
    int age;
    float gpa;
};

// Function prototypes
void writeToFile(struct Student *students, int n);
void readFromFile();

int main() {
    FILE *fptr;
    struct Student students[100];  // Array to hold multiple students
    struct Student *ptr;           // Pointer to access students
    int n, i;
    
    // Get the number of students
    printf("Enter the number of students: ");
    scanf("%d", &n);
    
    // Assign pointer to the students array
    ptr = students;
    
    // Input details of each student
    for (i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", (ptr + i)->name);
        printf("Age: ");
        scanf("%d", &(ptr + i)->age);
        printf("GPA: ");
        scanf("%f", &(ptr + i)->gpa);
    }

    // Write students data to the file
    writeToFile(students, n);
    
    // Read and display data from the file
    printf("\nData in the file:\n");
    readFromFile();
    
    return 0;
}

// Function to write student data to a file
void writeToFile(struct Student *students, int n) {
    FILE *fptr = fopen("student_data.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    
    for (int i = 0; i < n; i++) {
        fprintf(fptr, "Name: %s\n", (students + i)->name);
        fprintf(fptr, "Age: %d\n", (students + i)->age);
        fprintf(fptr, "GPA: %.2f\n", (students + i)->gpa);
        fprintf(fptr, "--------------------\n");
    }

    fclose(fptr);
    printf("Data written to file successfully.\n");
}

// Function to read student data from a file
void readFromFile() {
    FILE *fptr = fopen("student_data.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    
    char c;
    while ((c = fgetc(fptr)) != EOF) {
        putchar(c);
    }
    
    fclose(fptr);
}
