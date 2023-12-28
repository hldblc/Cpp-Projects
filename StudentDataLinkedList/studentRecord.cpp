#include <iostream>
#include <string>
#include <sstream>
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

// Implementations
void createLinkedList(StudentNode*& listHead) {
    if (listHead != nullptr) {
        cout << "List already created!" << endl;
    } else {
        listHead = new StudentNode{0, "", 0.0, nullptr}; // Create a dummy head node
        cout << "New list created." << endl;
    }
}

void addStudent(StudentNode*& listHead, float ID, string name, double gpa) {
    if (listHead == nullptr) {
        cout << "Please create the list first." << endl;
        return;
    }

    StudentNode* newNode = new StudentNode{ ID, name, gpa, NULL };

    if (listHead == NULL) {
        listHead = newNode;
    } else {
        StudentNode* temp = listHead;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteStudent(StudentNode*& listHead, float ID) {
    if (listHead == NULL) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    if (listHead->ID == ID) {
        StudentNode* temp = listHead;
        listHead = listHead->next;
        delete temp;
        return;
    }

    StudentNode* current = listHead, *prev = NULL;
    while (current != NULL && current->ID != ID) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        cout << "Student with ID " << ID << " not found." << endl;
        return;
    }

    prev->next = current->next;
    delete current;
}

void displayStudents(StudentNode* listHead) {
    if (listHead == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    StudentNode* temp = listHead;
    while (temp != NULL) {
        cout << "ID: " << temp->ID << ", Name: " << temp->name << ", GPA: " << temp->gpa << endl;
        temp = temp->next;
    }
}

void modifyStudent(StudentNode* listHead, float ID, string newName, double newGpa) {
    StudentNode* temp = listHead;
    while (temp != NULL) {
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

void purgeList(StudentNode*& listHead) {
    while (listHead != NULL) {
        StudentNode* temp = listHead;
        listHead = listHead->next;
        delete temp;
    }
}

void searchStudent(StudentNode* listHead, float ID) {
    StudentNode* temp = listHead;
    while (temp != NULL) {
        if (temp->ID == ID) {
            cout << "Student found: ID: " << temp->ID << ", Name: " << temp->name << ", GPA: " << temp->gpa << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Student with ID " << ID << " not found." << endl;
}

bool idExists(StudentNode* listHead, float ID) {
    StudentNode* temp = listHead;
    while (temp != NULL) {
        if (temp->ID == ID) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main() {
    StudentNode* listHead = NULL;
    int choice;
    float ID;
    string name;
    double gpa;

    while (true) {
        cout << "========================================" << endl;
        cout << "          STUDENT LINKED LIST           " << endl;
        cout << "========================================" << endl;
        cout << "Enter command:" << endl;
        cout << "1. Create" << endl;
        cout << "2. Add" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Display" << endl;
        cout << "5. Modify" << endl;
        cout << "6. Purge entire list" << endl;
        cout << "7. Search for node" << endl;
        cout << "8. Exit" << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                createLinkedList(listHead);
                break;
            case 2:
                cout << "Enter ID: ";
                cin >> ID;
                cin.ignore();
                cout << "Enter Name: ";
                getline(cin, name);
                cout << "Enter GPA: ";
                cin >> gpa;
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
                purgeList(listHead); // Clean up before exiting
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
