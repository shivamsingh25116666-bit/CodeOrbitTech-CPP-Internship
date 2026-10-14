// ============================================================
// Task 2: Student Management System
// CodSoft C++ Internship
// Concepts: arrays, structs, functions, loops, validation.
// Features: add, view, search, update marks, class statistics,
//           formatted report with grades.
// ============================================================
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

const int MAX_STUDENTS = 50;   // capacity of the array
const int SUBJECTS = 3;
const string SUBJECT_NAMES[SUBJECTS] = {"Maths", "Physics", "Programming"};

struct Student {
    int roll;
    string name;
    double marks[SUBJECTS];
};

Student students[MAX_STUDENTS];   // the array that stores all records
int studentCount = 0;             // how many records are currently used

// ---------- Input helpers (validation) ----------
string readLine(const string& prompt) {
    string line;
    cout << prompt;
    if (!getline(cin, line)) { cout << "\nInput ended.\n"; exit(0); }
    return line;
}

int readInt(const string& prompt, int low, int high) {
    while (true) {
        stringstream ss(readLine(prompt));
        int v; char extra;
        if (ss >> v && !(ss >> extra) && v >= low && v <= high) return v;
        cout << "  Enter a whole number from " << low << " to " << high << ".\n";
    }
}

double readMarks(const string& prompt) {
    while (true) {
        stringstream ss(readLine(prompt));
        double v; char extra;
        if (ss >> v && !(ss >> extra) && v >= 0 && v <= 100) return v;
        cout << "  Marks must be a number between 0 and 100.\n";
    }
}

string readName(const string& prompt) {
    while (true) {
        string name = readLine(prompt);
        // trim spaces at both ends
        size_t start = name.find_first_not_of(" \t");
        size_t end = name.find_last_not_of(" \t");
        if (start != string::npos) return name.substr(start, end - start + 1);
        cout << "  Name cannot be empty.\n";
    }
}

// ---------- Helper functions ----------
// Returns the array index of a roll number, or -1 if not found.
int findStudent(int roll) {
    for (int i = 0; i < studentCount; i++)
        if (students[i].roll == roll) return i;
    return -1;
}

double totalMarks(const Student& s) {
    double sum = 0;
    for (int i = 0; i < SUBJECTS; i++) sum += s.marks[i];
    return sum;
}

double averageMarks(const Student& s) { return totalMarks(s) / SUBJECTS; }

char gradeFor(double avg) {
    if (avg >= 90) return 'A';
    if (avg >= 75) return 'B';
    if (avg >= 60) return 'C';
    if (avg >= 40) return 'D';
    return 'F';
}

void printHeader() {
    cout << left << setw(6) << "Roll" << setw(20) << "Name";
    for (int i = 0; i < SUBJECTS; i++) cout << setw(13) << SUBJECT_NAMES[i];
    cout << setw(9) << "Total" << setw(9) << "Avg" << "Grade\n";
    cout << string(6 + 20 + 13 * SUBJECTS + 9 + 9 + 5, '-') << "\n";
}

void printStudent(const Student& s) {
    cout << left << setw(6) << s.roll << setw(20) << s.name.substr(0, 19);
    for (int i = 0; i < SUBJECTS; i++) cout << setw(13) << s.marks[i];
    cout << setw(9) << totalMarks(s) << setw(9) << averageMarks(s)
         << gradeFor(averageMarks(s)) << "\n";
}

// ---------- Menu actions ----------
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "Storage full. Cannot add more than " << MAX_STUDENTS << " students.\n";
        return;
    }
    int roll;
    while (true) {
        roll = readInt("Enter roll number (1-9999): ", 1, 9999);
        if (findStudent(roll) == -1) break;
        cout << "  That roll number already exists. Use a different one.\n";
    }
    Student s;
    s.roll = roll;
    s.name = readName("Enter name: ");
    for (int i = 0; i < SUBJECTS; i++)
        s.marks[i] = readMarks("Enter marks in " + SUBJECT_NAMES[i] + " (0-100): ");
    students[studentCount++] = s;
    cout << "Student added successfully.\n";
}

void viewAll() {
    if (studentCount == 0) { cout << "No records available.\n"; return; }
    cout << fixed << setprecision(1) << "\n";
    printHeader();
    for (int i = 0; i < studentCount; i++) printStudent(students[i]);
}

void searchStudent() {
    if (studentCount == 0) { cout << "No records available.\n"; return; }
    int roll = readInt("Enter roll number to search: ", 1, 9999);
    int idx = findStudent(roll);
    if (idx == -1) { cout << "No student found with roll number " << roll << ".\n"; return; }
    cout << fixed << setprecision(1) << "\n";
    printHeader();
    printStudent(students[idx]);
}

void updateMarks() {
    if (studentCount == 0) { cout << "No records available.\n"; return; }
    int roll = readInt("Enter roll number to update: ", 1, 9999);
    int idx = findStudent(roll);
    if (idx == -1) { cout << "No student found with roll number " << roll << ".\n"; return; }
    cout << "Updating marks for " << students[idx].name << "\n";
    for (int i = 0; i < SUBJECTS; i++)
        students[idx].marks[i] = readMarks("New marks in " + SUBJECT_NAMES[i] + " (0-100): ");
    cout << "Marks updated successfully.\n";
}

void classStatistics() {
    if (studentCount == 0) { cout << "No records available.\n"; return; }
    double classTotal = 0;
    int top = 0, bottom = 0;
    for (int i = 0; i < studentCount; i++) {
        classTotal += averageMarks(students[i]);
        if (averageMarks(students[i]) > averageMarks(students[top])) top = i;
        if (averageMarks(students[i]) < averageMarks(students[bottom])) bottom = i;
    }
    cout << fixed << setprecision(2);
    cout << "\n----- Class Statistics -----\n";
    cout << "Total students   : " << studentCount << "\n";
    cout << "Class average    : " << classTotal / studentCount << "\n";
    cout << "Highest average  : " << averageMarks(students[top]) << "  ("
         << students[top].name << ", Roll " << students[top].roll << ")\n";
    cout << "Lowest average   : " << averageMarks(students[bottom]) << "  ("
         << students[bottom].name << ", Roll " << students[bottom].roll << ")\n";
    cout << "\nSubject-wise averages:\n";
    for (int s = 0; s < SUBJECTS; s++) {
        double sum = 0;
        for (int i = 0; i < studentCount; i++) sum += students[i].marks[s];
        cout << "  " << left << setw(13) << SUBJECT_NAMES[s] << sum / studentCount << "\n";
    }
}

void formattedReport() {
    if (studentCount == 0) { cout << "No records available.\n"; return; }
    cout << "\n================ STUDENT REPORT ================\n";
    viewAll();
    int gradeCount[5] = {0, 0, 0, 0, 0};   // A B C D F
    const string letters = "ABCDF";
    for (int i = 0; i < studentCount; i++)
        gradeCount[letters.find(gradeFor(averageMarks(students[i])))]++;
    cout << "\nGrade distribution:\n";
    for (int g = 0; g < 5; g++)
        cout << "  Grade " << letters[g] << " : " << gradeCount[g] << "\n";
    classStatistics();
}

void showMenu() {
    cout << "\n=====================================\n";
    cout << "     STUDENT MANAGEMENT SYSTEM\n";
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

int main() {
    while (true) {
        showMenu();
        int choice = readInt("Choose an option (1-7): ", 1, 7);
        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewAll(); break;
            case 3: searchStudent(); break;
            case 4: updateMarks(); break;
            case 5: classStatistics(); break;
            case 6: formattedReport(); break;
            case 7: cout << "Goodbye!\n"; return 0;
        }
    }
}
