
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

const int MAX_STUDENTS = 50;
const int SUBJECTS = 3;

const string SUBJECT_NAMES[SUBJECTS] = {
    "Maths", "Physics", "Programming"
};

struct Student {
    int roll;
    string name;
    double marks[SUBJECTS];
};

Student students[MAX_STUDENTS];
int studentCount = 0;

// ---------- Input helpers ----------

string readLine(const string& prompt) {
    string line;

    cout << prompt;

    if (!getline(cin, line)) {
        cout << "\nInput ended. Goodbye!\n";
        exit(0);
    }

    return line;
}

int readInt(const string& prompt, int low, int high) {
    while (true) {
        stringstream ss(readLine(prompt));
        int value;
        char extra;

        if (ss >> value &&
            !(ss >> extra) &&
            value >= low &&
            value <= high) {
            return value;
        }

        cout << "  Enter a whole number from "
             << low << " to " << high << ".\n";
    }
}

double readMarks(const string& prompt) {
    while (true) {
        stringstream ss(readLine(prompt));
        double value;
        char extra;

        if (ss >> value &&
            !(ss >> extra) &&
            isfinite(value) &&
            value >= 0 &&
            value <= 100) {
            return value;
        }

        cout << "  Marks must be a finite number "
             << "between 0 and 100.\n";
    }
}

string readName(const string& prompt) {
    while (true) {
        string name = readLine(prompt);

        size_t start = name.find_first_not_of(" \t");
        size_t end = name.find_last_not_of(" \t");

        if (start != string::npos) {
            name = name.substr(start, end - start + 1);

            if (name.length() <= 100) {
                return name;
            }

            cout << "  Name cannot exceed 100 characters.\n";
        } else {
            cout << "  Name cannot be empty.\n";
        }
    }
}

// ---------- Helper functions ----------

int findStudent(int roll) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].roll == roll) {
            return i;
        }
    }

    return -1;
}

double totalMarks(const Student& student) {
    double total = 0;

    for (int i = 0; i < SUBJECTS; i++) {
        total += student.marks[i];
    }

    return total;
}

double averageMarks(const Student& student) {
    return totalMarks(student) / SUBJECTS;
}

char gradeFor(double average) {
    if (average >= 90) return 'A';
    if (average >= 75) return 'B';
    if (average >= 60) return 'C';
    if (average >= 40) return 'D';

    return 'F';
}

// ---------- Display functions ----------

void printHeader() {
    cout << left
         << setw(6) << "Roll"
         << setw(20) << "Name";

    for (int i = 0; i < SUBJECTS; i++) {
        cout << setw(13) << SUBJECT_NAMES[i];
    }

    cout << setw(9) << "Total"
         << setw(9) << "Avg"
         << "Grade\n";

    cout << string(83, '-') << "\n";
}

void printStudent(const Student& student) {
    cout << left
         << setw(6) << student.roll
         << setw(20) << student.name.substr(0, 19);

    for (int i = 0; i < SUBJECTS; i++) {
        cout << setw(13) << student.marks[i];
    }

    cout << setw(9) << totalMarks(student)
         << setw(9) << averageMarks(student)
         << gradeFor(averageMarks(student))
         << "\n";
}

// ---------- Menu actions ----------

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "Storage full. Maximum capacity is "
             << MAX_STUDENTS << " students.\n";
        return;
    }

    int roll;

    while (true) {
        roll = readInt("Enter roll number (1-9999): ", 1, 9999);

        if (findStudent(roll) == -1) {
            break;
        }

        cout << "  Roll number already exists. "
             << "Enter a different number.\n";
    }

    Student student;
    student.roll = roll;
    student.name = readName("Enter student name: ");

    for (int i = 0; i < SUBJECTS; i++) {
        student.marks[i] = readMarks(
            "Enter marks in " + SUBJECT_NAMES[i] + " (0-100): "
        );
    }

    students[studentCount] = student;
    studentCount++;

    cout << "Student added successfully.\n";
}

void viewAll() {
    if (studentCount == 0) {
        cout << "No records available.\n";
        return;
    }

    cout << fixed << setprecision(1) << "\n";
    printHeader();

    for (int i = 0; i < studentCount; i++) {
        printStudent(students[i]);
    }
}

void searchStudent() {
    if (studentCount == 0) {
        cout << "No records available.\n";
        return;
    }

    int roll = readInt("Enter roll number to search: ", 1, 9999);
    int index = findStudent(roll);

    if (index == -1) {
        cout << "No student found with roll number "
             << roll << ".\n";
        return;
    }

    cout << fixed << setprecision(1) << "\n";
    printHeader();
    printStudent(students[index]);
}

void updateMarks() {
    if (studentCount == 0) {
        cout << "No records available.\n";
        return;
    }

    int roll = readInt("Enter roll number to update: ", 1, 9999);
    int index = findStudent(roll);

    if (index == -1) {
        cout << "No student found with roll number "
             << roll << ".\n";
        return;
    }

    cout << "Updating marks for "
         << students[index].name << "\n";

    for (int i = 0; i < SUBJECTS; i++) {
        students[index].marks[i] = readMarks(
            "New marks in " + SUBJECT_NAMES[i] + " (0-100): "
        );
    }

    cout << "Marks updated successfully.\n";
}

void classStatistics() {
    if (studentCount == 0) {
        cout << "No records available.\n";
        return;
    }

    double classTotal = 0;
    int top = 0;
    int bottom = 0;

    for (int i = 0; i < studentCount; i++) {
        double average = averageMarks(students[i]);

        classTotal += average;

        if (average > averageMarks(students[top])) {
            top = i;
        }

        if (average < averageMarks(students[bottom])) {
            bottom = i;
        }
    }

    cout << fixed << setprecision(2);
    cout << "\n------ Class Statistics ------\n";

    cout << "Total students  : " << studentCount << "\n";
    cout << "Class average   : "
         << classTotal / studentCount << "\n";

    cout << "Highest average : "
         << averageMarks(students[top])
         << " (" << students[top].name
         << ", Roll " << students[top].roll << ")\n";

    cout << "Lowest average  : "
         << averageMarks(students[bottom])
         << " (" << students[bottom].name
         << ", Roll " << students[bottom].roll << ")\n";

    cout << "\nSubject-wise averages:\n";

    for (int subject = 0; subject < SUBJECTS; subject++) {
        double sum = 0;

        for (int i = 0; i < studentCount; i++) {
            sum += students[i].marks[subject];
        }

        cout << "  " << left << setw(13)
             << SUBJECT_NAMES[subject]
             << sum / studentCount << "\n";
    }
}

void formattedReport() {
    if (studentCount == 0) {
        cout << "No records available.\n";
        return;
    }

    cout << "\n========== STUDENT REPORT ==========\n";
    viewAll();

    int gradeCount[5] = {0, 0, 0, 0, 0};
    const string letters = "ABCDF";

    for (int i = 0; i < studentCount; i++) {
        char grade = gradeFor(averageMarks(students[i]));
        size_t index = letters.find(grade);

        if (index != string::npos) {
            gradeCount[index]++;
        }
    }

    cout << "\nGrade distribution:\n";

    for (int i = 0; i < 5; i++) {
        cout << "  Grade " << letters[i]
             << " : " << gradeCount[i] << "\n";
    }

    classStatistics();
}

void showMenu() {
    cout << "\n=====================================\n";
    cout << "       STUDENT MANAGEMENT SYSTEM\n";
    cout << "=====================================\n";
    cout << " 1. Add student\n";
    cout << " 2. View all students\n";
    cout << " 3. Search student by roll number\n";
    cout << " 4. Update student marks\n";
    cout << " 5. Class statistics\n";
    cout << " 6. Formatted report\n";
    cout << " 7. Exit\n";
    cout << "-------------------------------------\n";
}

// ---------- Main function ----------

int main() {
    while (true) {
        showMenu();

        int choice = readInt("Choose an option (1-7): ", 1, 7);

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                viewAll();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateMarks();
                break;

            case 5:
                classStatistics();
                break;

            case 6:
                formattedReport();
                break;

            case 7:
                cout << "Goodbye!\n";
                return 0;
        }
    }
}
