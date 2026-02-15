#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};
Node* deleteK(Node* head,int k){
    if(k==1) return NULL;
    Node* curr=head;
    Node* prev=NULL;
    int count=1;
    while(curr!=NULL){
        if(count==k){
            prev->next=curr->next;
            Node* temp=curr;
            curr=curr->next;
            delete temp;
            count=1;
        }
        else{
            prev=curr;
            curr=curr->next;
            count++;
        }
    }
    return head;

}
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    if (n == 0) return 0;

    int x;
    cin >> x;
    Node* head = new Node(x);
    Node* tail = head;

    // create linked list
    for (int i = 1; i < n; i++) {
        cin >> x;
        tail->next = new Node(x);
        tail = tail->next;
    }

    int k;
    cout << "Enter k: ";
    cin >> k;

    head = deleteK(head, k);

    cout << "Result list: ";
    printList(head);

    return 0;
}