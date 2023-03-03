#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> s;
    int choice, value;

    while (true) {
        cout << "---------MENU----------" << endl;
        cout << "1: Push a value" << endl;
        cout << "2: Pop the value" << endl;
        cout << "3: Display the top value" << endl;
        cout << "4: Display the whole stack" << endl;
        cout << "0: Exit the program" << endl;
        cout << "----------------------" << endl;
        cout << "Enter Selection: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to be pushed: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                if (s.empty()) {
                    cout << "Stack Underflow" << endl;
                } else {
                    cout << "The popped element is " << s.top() << endl;
                    s.pop();
                }
                break;

            case 3:
                if (s.empty()) {
                    cout << "Stack Underflow" << endl;
                } else {
                    cout << "The top element is " << s.top() << endl;
                }
                break;

            case 4:
                if (s.empty()) {
                    cout << "Stack is empty" << endl;
                } else {
                    cout << "Stack elements are: ";
                    stack<int> temp = s;
                    while (!temp.empty()) {
                        cout << temp.top() << " ";
                        temp.pop();
                    }
                    cout << endl;
                }
                break;

            case 0:
                cout << "Exit" << endl;
                return 0;

            default:
                cout << "You need to make another choice!" << endl;
                break;
        }
    }
}
