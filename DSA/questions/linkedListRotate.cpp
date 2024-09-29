// You are using GCC
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int data){
        this->data=data;
        next=NULL;
    }
};

class LinkedList{
    
    
    Node* head=NULL;
    public:
    
       void pushBack(int data) {
        if (head == NULL) {
            head = new Node(data);
            return;
        }
        Node* ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new Node(data);
    }
    
    void rotate(Node* head){
        
    }
    
    void display(){
        if(head==NULL){
            return;
        }
        Node* ptr=head;
        while(ptr!=NULL){
            cout<<ptr->data<<"->";
            ptr=ptr->next;
        }
        
    }
    
};

int main(){
    
    LinkedList ll;
    
    int arr[]={10,20,30,40,50,60};
    for(int i=0;i<6;i++){
        ll.pushBack(arr[i]);
    }
    ll.display();
    
    // int n;
    // cin>>n;
    
    
    
}