#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int choice, value;
int flag = 0, stack_data[100], n = 10, top = -1;
int lastChoice = -1;
bool repeatedChoice = false;

string warningsMessages[] = {
    "Going for a world record in button pressing? Keep it up!",
    "That choice again? You're nothing if not consistent!",
    "If that choice had frequent flyer miles, you'd be on a beach by now.",
    "Groundhog Day vibes! Same choice, different minute.",
    "If this was a game, you'd have unlocked the 'Persistent Picker' badge by now.",
    "Deja vu? Or is this your favorite number? Either way, rock on!",
    "That choice must have some secret magic I'm not aware of. Enlighten me?",
    "If repetition was an art, you'd be Picasso!",
    "Trying to wear out that key? Well, it's one way to get strong fingers!",
    "You and that choice? Name a more iconic duo. I'll wait."
};

int main() {
    srand(time(0));

    do {
        cout << "---------MENU----------" << endl;
        cout << "1: Create a new stack" << endl;
        cout << "2: Push a value" << endl;
        cout << "3: Pop the value" << endl;
        cout << "4: Display the top value" << endl;
        cout << "5: Purge the stack" << endl;
        cout << "6: Display the whole stack" << endl;
        cout << "0: Exit the program" << endl;
        cout << "----------------------" << endl;
        cout << "\nEnter Selection: ";
        cin >> choice;

        if (choice == lastChoice && choice != 2) {
            int randomIndex = rand() % (sizeof(warningsMessages) / sizeof(warningsMessages[0]));
            cout << warningsMessages[randomIndex] << endl;
            repeatedChoice = true;
        } else {
            if (repeatedChoice) {
                cout << (rand() % 2 == 0 ? "Thank God!" : "Oh Lord, Thank you!") << endl;
                repeatedChoice = false;
            }
        }

        switch (choice) {
            case 1:
                if (flag == 0) {
                    flag = 1;
                    cout << "Stack Successfully Created!" << endl;
                } else {
                    cout << "Stack is already created." << endl;
                }
                break;

            case 2:
                if (flag == 0) {
                    cout << "You can not PUSH value before creating a Stack!" << endl;
                } else {
                    cout << "Enter a value between 0-10 to push onto the Stack" << endl;
                    cin >> value;
                    if (top >= n - 1) {
                        cout << "Stack Overflow!" << endl;
                    } else {
                        top++;
                        stack_data[top] = value;
                    }
                }
                break;

            case 3:
                if (flag == 1) {
                    if (top <= -1) {
                        cout << "Stack Underflow" << endl;
                    } else {
                        cout << "The popped element is " << stack_data[top] << endl;
                        top--;
                    }
                } else {
                    cout << "You can not POP value before creating a Stack!" << endl;
                }
                break;

            case 4:
                if (flag == 1) {
                    if (top <= -1) {
                        cout << "Stack Underflow" << endl;
                    } else {
                        cout << "The top element is " << stack_data[top] << endl;
                    }
                } else {
                    cout << "I thought you are a smart person." << endl;
                }
                break;

            case 5:
                if (flag == 1) {
                    while (top > -1) {
                        stack_data[top] = 0;
                        top--;
                    }
                    flag = 0;
                    cout << "Stack successfully purged." << endl;
                } else {
                    cout << "Are you out of your mind, dude?" << endl;
                }
                break;

            case 6:
                if (flag == 0) {
                    cout << "Stack is empty!" << endl;
                } else {
                    if (top >= 0) {
                        cout << "Stack elements are:" << endl;
                        for (int i = top; i >= 0; i--) {
                            cout << stack_data[i] << " ";
                        }
                        cout << endl;
                    } else {
                        cout << "Stack is empty" << endl;
                    }
                }
                break;

            case 0:
                cout << "exit" << endl;
                break;

            default:
                cout << "You need to make another choice!" << endl;
        }

        lastChoice = choice;
    } while (choice != 0);

    return 0;
}
