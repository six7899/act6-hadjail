#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Student {
    int id;
    string firstName;
    string lastName;
    string course;
    float gpa;
};

const int MAX_STUDENTS = 100;
Student students[MAX_STUDENTS];
int studentCount = 0;

bool isDuplicate(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            return true;
        }
    }
    return false;
}

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "Student record is full." << endl;
        return;
    }
    Student newStudent;
    cout << "Enter Student ID: ";
    cin >> newStudent.id;
    if (isDuplicate(newStudent.id)) {
        cout << "Student ID is duplicate." << endl;
        return;
    }
    cout << "Enter First Name: ";
    cin >> newStudent.firstName;
    cout << "Enter Last Name: ";
    cin >> newStudent.lastName;
    cout << "Enter Course: ";
    cin >> newStudent.course;
    cout << "Enter Previous Semestral GPA: ";
    cin >> newStudent.gpa;
    students[studentCount++] = newStudent;
    cout << "Student added successfully." << endl;
}

void editStudent() {
    if (studentCount == 0) {
        cout << "No records available." << endl;
        return;
    }
    int id;
    cout << "Enter Student ID to search: ";
    cin >> id;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            cout << "Found Student: " << students[i].firstName << " " << students[i].lastName << endl;
            cout << "Enter new First Name: ";
            cin >> students[i].firstName;
            cout << "Enter new Last Name: ";
            cin >> students[i].lastName;
            cout << "Enter new Course: ";
            cin >> students[i].course;
            cout << "Enter new Previous Semestral GPA: ";
            cin >> students[i].gpa;
            cout << "Student data updated successfully." << endl;
            return;
        }
    }
    cout << "No record found." << endl;
}

void deleteStudent() {
    int id;
    cout << "Enter Student ID to delete: ";
    cin >> id;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            cout << "Found Student: " << students[i].firstName << " " << students[i].lastName << endl;
            char choice;
            cout << "Delete this record? (y/n): ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y') {
                for (int j = i; j < studentCount - 1; j++) {
                    students[j] = students[j + 1];
                }
                studentCount--;
                cout << "Student deleted successfully." << endl;
            }
            return;
        }
    }
    cout << "No record found." << endl;
}

void viewStudents() {
    int option;
    cout << "View students by: 1. Alphabetically 2. GPA" << endl;
    cin >> option;
    if (option == 1) {
        sort(students, students + studentCount, [](Student a, Student b) {
            return a.lastName < b.lastName;
        });
    } else if (option == 2) {
        sort(students, students + studentCount, [](Student a, Student b) {
            return a.gpa < b.gpa;
        });
    }
    for (int i = 0; i < studentCount; i++) {
        cout << "ID: " << students[i].id << ", Name: " << students[i].firstName << " " << students[i].lastName
             << ", Course: " << students[i].course << ", GPA: " << fixed << setprecision(2) << students[i].gpa << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "Menu: 1. Add Student 2. Edit Student 3. Delete Student 4. View Students 5. Exit" << endl;
        cin >> choice;
        switch (choice) {
            case 1: addStudent(); break;
            case 2: editStudent(); break;
            case 3: deleteStudent(); break;
            case 4: viewStudents(); break;
            case 5: cout << "Exiting program." << endl; break;
            default: cout << "Invalid choice." << endl; break;
        }
    } while (choice != 5);
    return 0;
}


