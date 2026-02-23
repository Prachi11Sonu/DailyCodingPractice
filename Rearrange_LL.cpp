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
Node* rearrangeEvenOdd(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* odd=head;
    Node* even=head->next;
    Node* evenHead=even;
    while(even!=NULL && even->next!=NULL){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    odd->next=evenHead;

}
void printList(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        if(head->next!=NULL){
            cout<<"-> ";
        }
        head=head->next;
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    if(n<=0){
        cout<<" Invalid"<<endl;
        return 0;
    }
    Node* head=NULL;
    Node* tail=NULL;
    cout<<"Enter node values: "<<endl;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        Node* newNode=new Node(x);
        if(head==NULL){
            head=newNode;
            tail=newNode;


        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    rearrangeEvenOdd(head);
    cout<<"Rearranges list: "<<endl;
    printList(head);
    return 0;
}