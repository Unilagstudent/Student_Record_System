# Student Record System

This is a simple C program to manage student records. It allows users to add, edit, display, delete, download, upload, search, calculate the average score, and sort student records. The program uses a console-based interface for user interaction.

## Features

- **Add Student Records**: Enter student name and score, and automatically assign a roll number.
- **Edit Student Records**: Edit the name and score of an existing student using their roll number.
- **Display Student Records**: Display all student records that have been added.
- **Delete Student Records**: Clear all student records.
- **Download Student Records**: Save student records to a file.
- **Upload Student Records**: Load student records from a file.
- **Search Student Records**: Search for a student by their roll number.
- **Calculate Average Score**: Calculate and display the average score of all students.
- **Sort Student Records**: Sort student records by score in ascending order.

## How to Use

1. **Compile the Program**: Use a C compiler to compile the `main.c` file.
   ```sh
   gcc main.c -o student_record_system
   ```

2. **Run the Program**: Execute the compiled program.
   ```sh
   ./student_record_system
   ```

3. **Main Menu**: Follow the on-screen instructions to navigate the main menu and select options by entering the corresponding number.

## Functions

- `void AddStudent()`: Adds a new student record.
- `void EditStudent()`: Edits an existing student record by roll number.
- `void DisplayStudent()`: Displays all student records.
- `void DeleteStudent()`: Clears all student records.
- `void DownloadStudent()`: Saves student records to a file.
- `void UploadStudent()`: Loads student records from a file.
- `void SearchStudent()`: Searches for a student by roll number.
- `void StudentAverage()`: Calculates and displays the average score of all students.
- `void StudentSort()`: Sorts student records by score in ascending order.

## File Format for Upload/Download

The program reads from and writes to a file in the following format:
```
RollNumber, Name, Score
```

## Example

```
Please select an option (e.g 1/2/3/4/5/6/0): 
1. Add Students Records
2. Edit Students Records
3. Display Students Records
4. Delete Students Records 
5. Print/Download Students Records
6. Upload Students Records
7. Search for Student.
8. Display Average Score.
9. Display Students Scores in Ascending Order
0. Exit
```

## Notes

- The maximum number of students that can be added is 50.
- Ensure the file path for downloading and uploading student records exists and is accessible.

## License

This project is licensed under the MIT License. 

---

This README provides an overview of the Student Record System, detailing its features, usage, and functions. Use this guide to understand and interact with the program effectively.
