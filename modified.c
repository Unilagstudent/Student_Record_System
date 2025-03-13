#include <stdio.h>

// Structure for Student
struct Student {
    char name[20];
    int RollNumber;
    double Score;
};

// Function to Add Student Records
void AddStudent() {
    struct Student student[100];  // Array of students
    char choice = 'N';  // Initialize choice
    int i = 0;          // Student index

    do {
        printf("Enter Student's Name: ");
        scanf(" %19[^\n]", student[i].name);  // Allows spaces in names, prevents buffer overflow

        printf("Enter Student's Roll Number: ");
        scanf("%d", &student[i].RollNumber);

        printf("Enter Student's Score: ");
        scanf("%lf", &student[i].Score);

        printf("\nDo you want to add another student? (Y/N): ");

        getchar(); // FIX: Clear newline character from buffer
        scanf("%c", &choice);  // Read the choice

        i++; // Move to next student
    } while (choice == 'Y' || choice == 'y');  // Continue if user chooses 'Y' or 'y'
}


int main() {
    // Declare FirstName
    char FirstName[20];

    // Prompt user for first name
    printf("Please enter your first name: ");
    scanf("%s", FirstName);
    printf("Good day %s, welcome!\n", FirstName);

    // Wait for user input to continue
    printf("Press 'Enter' to continue\n");
    getchar(); // Clear newline left in input buffer
    getchar(); // Wait for Enter key

    int Choice;

    // Display menu
    printf("Please select an option (e.g 1/2/3/4/5/6/0): \n");
    printf("1. Add Students Records\n");
    printf("2. Edit Students Records\n");
    printf("3. Display Students Records\n");
    printf("4. Delete Students Records \n");
    printf("5. Print/Download Students Records\n");
    printf("6. Upload Students Records\n");
    printf("7. Search for Student.\n");
    printf("8. Display Average Score.\n");
    printf("9. Display Students Scores in Ascending Order\n");
    printf("0. Exit\n");

    scanf("%d", &Choice);

    switch (Choice) {
        case 1:
            AddStudent();
            break;
        case 2:
            printf("This feature is not yet available.\n");
            break;
        case 3:
            printf("This feature is not yet available.\n");
            break;
        case 4:
            printf("This feature is not yet available.\n");
            break;
        case 5:
          printf("This feature is not yet available.\n");
          break;
        case 6:
          printf("This feature is not yet available.\n");
          break;
        case 7:
          printf("This feature is not yet available.\n");
          break;
        case 8:
          printf("This feature is not yet available.\n");
          break;
        case 9:
            printf("This feature is not yet available.\n");
            break;
        case 0:
            printf("Thank you for using this program.\n");
            break;
        default:
            printf("Please enter a valid choice.\n");
    }

    return 0;
}