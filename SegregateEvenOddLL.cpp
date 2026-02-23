#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to divide even and odd
Node* divide(Node* head) {

    if (head == NULL || head->next == NULL)
        return head;

    Node *evenStart = NULL, *even = NULL;
    Node *oddStart = NULL, *odd = NULL;

    Node* curr = head;

    while (curr != NULL) {

        if (curr->data % 2 == 0) {  // Even number

            if (evenStart == NULL) {
                evenStart = curr;
                even = curr;
            } else {
                even->next = curr;
                even = curr;
            }

        } else {  // Odd number

            if (oddStart == NULL) {
                oddStart = curr;
                odd = curr;
            } else {
                odd->next = curr;
                odd = curr;
            }
        }

        curr = curr->next;
    }

    // If no even numbers
    if (evenStart == NULL)
        return head;

    // Join even and odd lists
    even->next = oddStart;

    if (odd != NULL)
        odd->next = NULL;

    return evenStart;
}

// Function to print list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next != NULL)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input" << endl;
        return 0;
    }

    Node* head = NULL;
    Node* tail = NULL;

    cout << "Enter node values: ";

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        Node* newNode = new Node(x);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    head = divide(head);

    cout << "Modified List: ";
    printList(head);

    return 0;
}
