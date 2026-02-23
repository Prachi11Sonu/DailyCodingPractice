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
void deleteNode(Node* del_node){
    if(del_node==NULL || del_node->next==NULL) return;
    del_node->data=del_node->next->data;
    Node* temp=del_node->next;
    del_node->next=temp->next;
    delete temp;
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
    if(n<2){
        cout<<"Need at least 2 nodes."<<endl;
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
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    int val;
    cout<<"Enter value of node to delete: "<<endl;
    cin>>val;
    Node* temp=head;
    while(temp!=NULL && temp->data!=val){
        temp=temp->next;
    }
    if(temp==NULL){
        cout<<"Node not found."<<endl;
    }
    else if(temp->next==NULL){
        cout<<"Cannot delete the last node using this method."<<endl;

    }
    else{
        deleteNode(temp);
        cout<<"Updated list: "<<endl;
        printList(head);
    }
    return 0;
}