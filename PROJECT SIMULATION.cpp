#include <iostream>
using namespace std;

class Stack {
    int arr[5];
    int top;
public:
    Stack() { top = -1; }

    bool isFull()  { return top == 4; }
    bool isEmpty() { return top == -1; }

    void push(int x) {
        cout << "\nPUSH " << x << endl;
        if (isFull()) { cout << "Stack Overflow!\n"; return; }
        arr[++top] = x;
        show();
    }

    void pop() {
        cout << "\nPOP\n";
        if (isEmpty()) { cout << "Stack Underflow!\n"; return; }
        cout << "Popped: " << arr[top--] << endl;
        show();
    }

    void peek() {
        cout << "\nPEEK\n";
        if (isEmpty()) cout << "Stack is Empty\n";
        else cout << "Top Element: " << arr[top] << endl;
        show();
    }

    void display() {
        cout << "\nDISPLAY\nStack: ";
        if (isEmpty()) cout << "Empty";
        else for (int i = top; i >= 0; i--) cout << arr[i] << " ";
        cout << endl;
        show();
    }

    void show() {
        cout << "Internal: [ ";
        for (int i = 0; i < 5; i++) {
            if (i <= top) cout << arr[i] << " ";
            else cout << "_ ";
        }
        cout << "]  TOP = " << top << endl;
    }
};

int main() {
    Stack s;
    int ch, x;

    while (true) {
        cout << "\n1.Push  2.Pop  3.Peek  4.Display  5.Exit\nEnter choice: ";
        cin >> ch;

        switch (ch) {
            case 1: cout << "Enter value: "; cin >> x; s.push(x); break;
            case 2: s.pop(); break;
            case 3: s.peek(); break;
            case 4: s.display(); break;
            case 5: return 0;
            default: cout << "Invalid choice\n";
        }
    }
}

