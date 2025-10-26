#include <iostream>
using namespace std;

class Stack {
    int *arr, top, size;

public:
    Stack(int n) {
        size = n;
        arr = new int[size];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int x) {
        if (isFull()) {
            cout << "⚠️  Stack Overflow!\n\n";
            return;
        }
        arr[++top] = x;
        cout << "✅ Pushed: " << x << "\n\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "⚠️  Stack Underflow!\n\n";
            return;
        }
        cout << "✅ Popped: " << arr[top--] << "\n\n";
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == size - 1);
    }

    void display() {
        if (isEmpty()) {
            cout << "⚠️  Stack is Empty!\n\n";
            return;
        }
        cout << "🧱 Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << "\n\n";
    }

    void peek() {
        if (isEmpty()) {
            cout << "⚠️  Stack is Empty!\n\n";
            return;
        }
        cout << "🔹 Top Element: " << arr[top] << "\n\n";
    }
};

int main() {
    int n;
    cout << "Enter stack size: ";
    cin >> n;
    cout << endl;

    Stack s(n);
    int choice, val;

    do {
        cout << "-------------------------------\n";
        cout << "Which operation do you want to perform?\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";
        cout << "-------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                s.push(val);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                cout << (s.isEmpty() ? "✅ Yes, Stack is Empty\n\n" : "❌ No, Stack is NOT Empty\n\n");
                break;
            case 4:
                cout << (s.isFull() ? "✅ Yes, Stack is Full\n\n" : "❌ No, Stack is NOT Full\n\n");
                break;
            case 5:
                s.display();
                break;
            case 6:
                s.peek();
                break;
            case 7:
                cout << "👋 Exiting program... Thank you!\n";
                break;
            default:
                cout << "⚠️  Invalid choice! Please try again.\n\n";
        }
    } while (choice != 7);

    return 0;
}
