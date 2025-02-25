#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(NULL) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(NULL) {}

    void insert(int position, int value) {
        Node* newNode = new Node(value);

        if (position == 0) { 
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        for (int i = 0; i < position - 1 && current != NULL; i++) {
            current = current->next;
        }

        if (current == NULL) {
            cout << "Invalid position\n";
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    void deleteAt(int position) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        if (position == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        for (int i = 0; i < position - 1 && current->next != NULL; i++) {
            current = current->next;
        }

        if (current->next == NULL) {
            cout << "Invalid position\n";
            return;
        }

        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }

    void display() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }
};

int main() {
    LinkedList list;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;

        if (operation == "insert") {
            int p, x;
            cin >> p >> x;
            list.insert(p, x);
        } else if (operation == "delete") {
            int p;
            cin >> p;
            list.deleteAt(p);
        }
    }

    list.display();

    return 0;
}

