#include<bits/stdc++.h>
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
      Node* tail=NULL;

      public:
      int size=0;
      
      void pushBack(int data){
      
            if(head==NULL and tail==NULL){
                  head=new Node(data);
                  tail=head;
                  size++;
                  return ;
            }
            Node* n=new Node(data);
            tail->next=n;
            tail=n;
            tail->next=head;
            size++;
      }

      void pushFront(int data){
            if(head==NULL) return;
            Node* n=new Node(data);
            n->next=head;
            head=n;
            tail->next=head;
      }

      void display(){
            if(head==NULL and tail==NULL) return;

            Node* ptr=head;
            do{
                  cout<<ptr->data<<"->";
                  ptr=ptr->next;
            }while(ptr!=head);
            cout<<ptr->data<<endl;;
            
      
      }

};

int main(){
      LinkedList ll;
      int n;
      cin>>n;
      while(n--){
            int element;
            cin>>element;
            ll.pushBack(element);
      }
      ll.display();
   
      // ll.reverseList();
      // ll.display();
}