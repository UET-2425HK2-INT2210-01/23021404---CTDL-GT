#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(NULL), next(NULL) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(NULL), tail(NULL) {}

    void append(int value) {
        Node* newNode = new Node(value);

        if (!head) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    int count_triplets() {
        int count = 0;
        Node* current = head ? head->next : NULL; 

        while (current != NULL && current->next != NULL) {
            int sum = current->prev->data + current->data + current->next->data;
            if (sum == 0) {
                count++;
            }
            current = current->next;
        }

        return count;
    }
};

int main() {
    DoublyLinkedList list;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        list.append(x);
    }

    cout << list.count_triplets() << endl;

    return 0;
}

