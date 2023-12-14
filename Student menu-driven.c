#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a student record
struct Student {
    int id;
    char name[50];
    float grade;
};

// Function to add a new student record
void addStudent(struct Student *students, int *count) {
    printf("\nEnter student details:\n");

    printf("Enter ID: ");
    scanf("%d", &students[*count].id);

    printf("Enter Name: ");
    scanf("%s", students[*count].name);

    printf("Enter Grade: ");
    scanf("%f", &students[*count].grade);

    (*count)++;
    printf("Student record added successfully!\n");
}

// Function to display all student records
void displayStudents(const struct Student *students, int count) {
    if (count == 0) {
        printf("No student records available.\n");
        return;
    }

    printf("\nStudent Records:\n");
    printf("| %-5s | %-20s | %-5s |\n", "ID", "Name", "Grade");
    printf("|--------|----------------------|--------|\n");

    for (int i = 0; i < count; i++) {
        printf("| %-5d | %-20s | %-5.2f |\n", students[i].id, students[i].name, students[i].grade);
    }
}

// Function to search for a student by ID
void searchStudent(const struct Student *students, int count, int searchId) {
    for (int i = 0; i < count; i++) {
        if (students[i].id == searchId) {
            printf("\nStudent Found:\n");
            printf("| %-5s | %-20s | %-5s |\n", "ID", "Name", "Grade");
            printf("|--------|----------------------|--------|\n");
            printf("| %-5d | %-20s | %-5.2f |\n", students[i].id, students[i].name, students[i].grade);
            return;
        }
    }

    printf("\nStudent with ID %d not found.\n", searchId);
}

// Function to delete a student by ID
void deleteStudent(struct Student *students, int *count, int deleteId) {
    for (int i = 0; i < *count; i++) {
        if (students[i].id == deleteId) {
            // Move the last element to the position of the element to be deleted
            students[i] = students[*count - 1];
            (*count)--;
            printf("\nStudent with ID %d deleted successfully.\n", deleteId);
            return;
        }
    }

    printf("\nStudent with ID %d not found.\n", deleteId);
}

int main() {
    struct Student students[100];  // Assuming a maximum of 100 students
    int count = 0;  // Number of student records

    int choice;
    do {
        printf("\nStudent Record System Menu:\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3: {
                int searchId;
                printf("Enter the ID to search: ");
                scanf("%d", &searchId);
                searchStudent(students, count, searchId);
                break;
            }
            case 4: {
                int deleteId;
                printf("Enter the ID to delete: ");
                scanf("%d", &deleteId);
                deleteStudent(students, &count, deleteId);
                break;
            }
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}
