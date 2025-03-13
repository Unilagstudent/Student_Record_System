#include <stdio.h>
#include <string.h>

struct Student {
    char name[20];
    int RollNumber;
    double Score;
};

struct Student student[50]; // size of student array is set to max of 50
int i = 0; // initialize index to zero
int j; // global variable for loop iterations

// function to add student
void AddStudent() {
    char choice = 'N'; // choice is initialized to N

    // loop for adding student information to student array
    do {
        printf("Enter Student's Name: ");
        scanf(" %[^\n]", student[i].name);
        printf("Enter Student's Score: ");
        scanf("%lf", &student[i].Score);
        student[i].RollNumber = i + 1; // assigns roll number based on index
        printf("Student %s has been assigned a Roll Number of %d \n", student[i].name, student[i].RollNumber);
        printf("Do you want to continue? (Y/N) \n");
        getchar(); // to consume the newline character left by scanf
        scanf(" %c", &choice);

        i++; // proceeds to the next index on the student array
    } while (choice == 'Y' || choice == 'y');
}

// Function to edit student records
void EditStudent() {
    if (i == 0) { // check if any student info has been added.
        printf("No Student Info to Edit.\n");
        return;
    }

    int roll, found = 0;

    printf("Enter Roll Number to edit: ");
    scanf("%d", &roll);

    for (int j = 0; j < i; j++) {
        if (student[j].RollNumber == roll) {
            printf("Editing record for %s (Roll No: %d)\n", student[j].name, roll);

            printf("Enter new name: ");
            scanf(" %[^\n]", student[j].name);

            printf("Enter correct score: ");
            scanf("%lf", &student[j].Score);

            printf("Student record updated successfully!\n");
            found = 1; // Mark student as found
            break;
        }
    }

    if (!found) { // If no student was found
        printf("Student with Roll Number %d not found!\n", roll);
    }
}

// Function to display ONLY Student records that exist.
void DisplayStudent() {
    // check if any student info has been added.
    if (i == 0) {
        printf("No student records available.\n");
        return;
    }

    printf("\n%-10s %-25s %-10s\n", "Roll Number", "Name", "Score");
    printf("-------------------------------------------------\n");

    for (int j = 0; j < i; j++) {
        printf("%-10d %-25s %-10.2f\n", student[j].RollNumber, student[j].name, student[j].Score);
    }
}

// function to clear all student records
void DeleteStudent() {
    memset(student, 0, sizeof(student)); // Set all bytes in student to 0
    i = 0; // resets array index to zero
    printf("Student records Successfully Cleared!\n");
}

// Function to print/ download student records
void DownloadStudent() {
    if (i == 0) {
        printf("No student records available.\n");
        return;
    }

    FILE *fp = fopen("C:\\Users\\USER\\Downloads\\Student.txt", "w"); // opens student file in the download folder and sets mode to write.
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // loop to write ONLY student information that has been added to file
    for (int j = 0; j < i; j++) {
        fprintf(fp, "%-1d, %-1s, %-1.2f\n", student[j].RollNumber, student[j].name, student[j].Score);
    }

    fclose(fp);
    printf("Student records successfully Downloaded!\n");
    printf("Check Your Download folder for your students file.\n");
}

// Function to upload student records from a file
void UploadStudent() {
    FILE *fp = fopen("C:\\Users\\USER\\Downloads\\Student.txt", "r"); // opens student file in the download folder and sets mode to read.
    if (fp == NULL) {
        printf("Error opening file! Make sure the file exists.\n");
        return;
    }

    // Clear existing records
    DeleteStudent();

    // Read student records from the file
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), fp)) { // Read each line from the file
        // Debugging: Print the line being read
        printf("Read line: %s", buffer);

        // Parse the line using sscanf
        if (sscanf(buffer, "%d, %[^,], %lf", &student[i].RollNumber, student[i].name, &student[i].Score) == 3) {
            // Debugging: Print the parsed data
            printf("Parsed: RollNumber=%d, Name=%s, Score=%.2f\n", student[i].RollNumber, student[i].name, student[i].Score);

            i++; // Increment the student count
            if (i >= 50) { // Prevent array overflow
                printf("Warning: Maximum number of students reached. Some records may not be loaded.\n");
                break;
            }
        }
    }

    fclose(fp);
    printf("Student records successfully uploaded from file!\n");
}

// Function to search for a student by ID
void SearchStudent() {
    int searchId;
    printf("Enter Roll Number of Student to be found:"); //prompt the user to enter roll number
    scanf("%d", &searchId);
    int found = 0;//used to track whether the student is found or not//
    for (int j = 0; j < i; j++) {
        if (student[j].RollNumber == searchId) {//if statement checks if the current student's ID (students[i].id) matches the searchId.//
            //i is used to access the current element in the students array students[i])//
            printf("Student found:\n");
            printf("Roll Number: %d\n", student[j].RollNumber);
            printf("Name: %s\n", student[j].name);
            printf("Score: %.2f\n", student[j].Score);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student with Roll Number %d not found.\n", searchId);
    }
}

// Function to calculate and display average score of all students
void StudentAverage () {

    float sum = 0;
    for (int j = 0; j < i; j++) {
        sum += student[j].Score;
    }
    float average = sum / i;
    printf("\nThe average score of all students: %.2f\n", average);
}

/// Function to sort student scores in ascending order
void StudentSort() {
    if (i == 0) { // check if any student info has been added.
        printf("No student records available to sort.\n");
        return;
    }

    // Bubble Sort algorithm to sort students by score in ascending order
    for (int k = 0; k < i - 1; k++) { // Outer loop for passes
        for (int j = 0; j < i - 1 - k; j++) { // Inner loop for comparisons
            if (student[j].Score > student[j + 1].Score) { // Swap if current score is greater than next
                // Swap the students
                struct Student temp = student[j];
                student[j] = student[j + 1];
                student[j + 1] = temp;
            }
        }
    }

    printf("\nSorted student scores in ascending order:\n");
    for (int j = 0; j < i; j++) { // Loop to display sorted students
        printf("Roll Number: %d, Name: %s, Score: %.2f\n", student[j].RollNumber, student[j].name, student[j].Score);
    }
}

int main() {
    // declares FirstName as a string and sets max. size to 20
    char FirstName[20];
    printf("Please enter your first name: \n"); // prompts user to enter name
    scanf("%s", FirstName); // saves input to variable FirstName
    printf("Good day %s, welcome!\n", FirstName); // Prints out personalized greeting.

    printf("click 'Enter' to continue\n");
    getchar(); // to consume the newline character left by scanf
    getchar(); // wait for user to press enter

    // displays and prompts user for choice
    int Choice = -1;
    // loop to return user to dialogue unless they exit.
    while (Choice != 0) {
        printf("Please select an option (e.g 1/2/3/4/5/6/0): \n ");
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
        if (scanf("%d", &Choice) != 1) { // If invalid input, clear buffer
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            Choice = -1; // Reset choice to continue loop
        }

        switch (Choice) {
            case 1:
                AddStudent();
                break;
            case 2:
                EditStudent();
                break;
            case 3:
                DisplayStudent();
                break;
            case 4:
                DeleteStudent();
                break;
            case 5:
                DownloadStudent();
                break;
            case 6:
                UploadStudent();
                break;
            case 7:
                SearchStudent();
                break;
            case 8:
                StudentAverage();
                break;
            case 9:
                StudentSort();
                break;
            case 0:
                printf("Thank you for using this program.\n");
                break;
            default:
                printf("Please enter a valid choice.\n");
        }
    }
    return 0;
}