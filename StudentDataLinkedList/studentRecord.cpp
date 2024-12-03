#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct StudentNode {
    float ID;
    string name;
    double gpa;
    StudentNode* next;
};

// Function prototypes
void createLinkedList(StudentNode*& listHead);
void addStudent(StudentNode*& listHead, float ID, string name, double gpa);
void deleteStudent(StudentNode*& listHead, float ID);
void displayStudents(StudentNode* listHead);
void modifyStudent(StudentNode* listHead, float ID, string newName, double newGpa);
void purgeList(StudentNode*& listHead);
void searchStudent(StudentNode* listHead, float ID);
bool idExists(StudentNode* listHead, float ID);

// Function to create a new linked list
void createLinkedList(StudentNode*& listHead) {
    if (listHead != nullptr) {
        cout << "List already exists!" << endl;
    } else {
        listHead = nullptr; // Initialize listHead as nullptr
        cout << "New list created. Add students to it!" << endl;
    }
}

// Function to add a student
void addStudent(StudentNode*& listHead, float ID, string name, double gpa) {
    if (idExists(listHead, ID)) {
        cout << "Error: A student with ID " << ID << " already exists." << endl;
        return;
    }

    StudentNode* newNode = new StudentNode{ID, name, gpa, nullptr};

    if (listHead == nullptr) {
        listHead = newNode; // Add the first node
    } else {
        StudentNode* temp = listHead;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode; // Add the node at the end
    }

    cout << "Student added successfully." << endl;
}

// Function to delete a student
void deleteStudent(StudentNode*& listHead, float ID) {
    if (listHead == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    if (listHead->ID == ID) {
        StudentNode* temp = listHead;
        listHead = listHead->next;
        delete temp;
        cout << "Student with ID " << ID << " deleted." << endl;
        return;
    }

    StudentNode* current = listHead;
    StudentNode* prev = nullptr;
    while (current != nullptr && current->ID != ID) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Student with ID " << ID << " not found." << endl;
        return;
    }

    prev->next = current->next;
    delete current;
    cout << "Student with ID " << ID << " deleted." << endl;
}

// Function to display all students
void displayStudents(StudentNode* listHead) {
    if (listHead == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    cout << "Student List:" << endl;
    StudentNode* temp = listHead;
    while (temp != nullptr) {
        cout << "ID: " << temp->ID << ", Name: " << temp->name << ", GPA: " << temp->gpa << endl;
        temp = temp->next;
    }
}

// Function to modify a student
void modifyStudent(StudentNode* listHead, float ID, string newName, double newGpa) {
    StudentNode* temp = listHead;
    while (temp != nullptr) {
        if (temp->ID == ID) {
            temp->name = newName;
            temp->gpa = newGpa;
            cout << "Student with ID " << ID << " updated." << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Student with ID " << ID << " not found." << endl;
}

// Function to purge the list
void purgeList(StudentNode*& listHead) {
    if (listHead == nullptr) {
        cout << "List is already empty." << endl;
        return;
    }

    while (listHead != nullptr) {
        StudentNode* temp = listHead;
        listHead = listHead->next;
        delete temp;
    }

    cout << "All students deleted. List is now empty." << endl;
}

// Function to search for a student
void searchStudent(StudentNode* listHead, float ID) {
    if (listHead == nullptr) {
        cout << "List is empty. No students to search." << endl;
        return;
    }

    StudentNode* temp = listHead;
    while (temp != nullptr) {
        if (temp->ID == ID) {
            cout << "Student found: ID: " << temp->ID << ", Name: " << temp->name << ", GPA: " << temp->gpa << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Student with ID " << ID << " not found." << endl;
}

// Function to check if an ID already exists
bool idExists(StudentNode* listHead, float ID) {
    StudentNode* temp = listHead;
    while (temp != nullptr) {
        if (temp->ID == ID) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Main program
int main() {
    StudentNode* listHead = nullptr;
    int choice;
    float ID;
    string name;
    double gpa;

    while (true) {
        cout << "========================================" << endl;
        cout << "          STUDENT LINKED LIST           " << endl;
        cout << "========================================" << endl;
        cout << "1. Create New List" << endl;
        cout << "2. Add Student" << endl;
        cout << "3. Delete Student" << endl;
        cout << "4. Display All Students" << endl;
        cout << "5. Modify Student" << endl;
        cout << "6. Purge Entire List" << endl;
        cout << "7. Search for Student" << endl;
        cout << "8. Exit" << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number between 1 and 8." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                createLinkedList(listHead);
                break;
            case 2:
                cout << "Enter ID: ";
                if (!(cin >> ID)) {
                    cout << "Invalid ID. Try again." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                cin.ignore();
                cout << "Enter Name: ";
                getline(cin, name);
                cout << "Enter GPA: ";
                if (!(cin >> gpa)) {
                    cout << "Invalid GPA. Try again." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                addStudent(listHead, ID, name, gpa);
                break;
            case 3:
                cout << "Enter ID to delete: ";
                cin >> ID;
                deleteStudent(listHead, ID);
                break;
            case 4:
                displayStudents(listHead);
                break;
            case 5:
                cout << "Enter ID to modify: ";
                cin >> ID;
                if (!idExists(listHead, ID)) {
                    cout << "Invalid ID, this ID was not assigned to the list." << endl;
                    break;
                }
                cin.ignore();
                cout << "Enter New Name: ";
                getline(cin, name);
                cout << "Enter New GPA: ";
                cin >> gpa;
                modifyStudent(listHead, ID, name, gpa);
                break;
            case 6:
                purgeList(listHead);
                break;
            case 7:
                cout << "Enter ID to search: ";
                cin >> ID;
                searchStudent(listHead, ID);
                break;
            case 8:
                cout << "Exiting program." << endl;
                purgeList(listHead);
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
