#include <iostream>
#include <cstddef>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = prev = NULL;
    }
};

// Function to insert a new node at the end of the doubly linked list
void insertAtTail(Node*& head, Node*& tail, int value) {
    Node* newNode = new Node(value);
    if (head == NULL) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

// Function to count triplets where sum of (p-1, p, p+1) == 0
int count_triplets(Node* head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL)
        return 0;

    int count = 0;
    Node* current = head->next; // Start from the second node

    while (current->next != NULL) { // Ensure there is a p-1 and p+1
        if (current->prev->data + current->data + current->next->data == 0) {
            count++;
        }
        current = current->next;
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    
    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertAtTail(head, tail, value);
    }

    cout << count_triplets(head) << endl;

    return 0;
}

