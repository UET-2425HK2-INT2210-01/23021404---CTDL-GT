#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL) return;  
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void printStackReversed(Node* node) {
        if (node == NULL) return;
        printStackReversed(node->next);
        cout << node->data << " ";
    }

    void display() {
        printStackReversed(top);
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    Stack stack;

    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;
        if (operation == "push") {
            int x;
            cin >> x;
            stack.push(x);
        } else if (operation == "pop") {
            stack.pop();
        }
    }

    stack.display();
    return 0;
}
