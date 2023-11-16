#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a student
struct Student {
    char name[50];
    int rollNumber;
    float marks;
};

// Function to add a new student to the database
void addStudent(struct Student *students, int *count) {
    printf("Enter details for the new student:\n");
    printf("Name: ");
    scanf("%s", students[*count].name);
    printf("Roll Number: ");
    scanf("%d", &students[*count].rollNumber);
    printf("Marks: ");
    scanf("%f", &students[*count].marks);
    (*count)++;
    printf("Student added successfully!\n\n");
}

// Function to display information for a specific student
void displayStudent(struct Student student) {
    printf("Name: %s\n", student.name);
    printf("Roll Number: %d\n", student.rollNumber);
    printf("Marks: %.2f\n", student.marks);
    printf("\n");
}

// Function to display information for all students
void displayAllStudents(struct Student *students, int count) {
    printf("Details for all students:\n");
    for (int i = 0; i < count; ++i) {
        printf("Student %d:\n", i + 1);
        displayStudent(students[i]);
    }
}

// Function to search for a student by roll number
void searchStudent(struct Student *students, int count) {
    int rollToSearch;
    printf("Enter the Roll Number to search: ");
    scanf("%d", &rollToSearch);

    for (int i = 0; i < count; ++i) {
        if (students[i].rollNumber == rollToSearch) {
            printf("Student found!\n");
            displayStudent(students[i]);
            return;
        }
    }

    printf("Student with Roll Number %d not found.\n", rollToSearch);
}

int main() {
    struct Student students[100]; // Assuming a maximum of 100 students
    int studentCount = 0;
    int choice;

    do {
        printf("Student Database Management System\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search for a Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &studentCount);
                break;
            case 2:
                displayAllStudents(students, studentCount);
                break;
            case 3:
                searchStudent(students, studentCount);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
