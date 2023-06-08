#include<bits/stdc++.h>
using namespace std;

class Node{
      public:
      int data;
      Node* next;
      Node* prev;
      Node(int data,Node* prev=NULL,Node* next=NULL){
            this->data=data;
            this->prev=prev;
            this->next=next;
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
            Node* n=new Node(data,tail,NULL);
            tail->next=n;
            tail=n;
            tail->next=head;
            head->prev=tail;
            size++;
      }


      void display(){
            if(head==NULL and tail==NULL) return;
            Node* ptr=head;

            do{
                  cout<<ptr->data<<"->";
                  ptr=ptr->next;
            }while(ptr!=head);
            cout<<ptr->data<<endl;;

            Node* ptr2=tail;
            
            do{
                  cout<<ptr2->data<<"->";
                  ptr2=ptr2->prev;
            }while(ptr2!=tail);
            cout<<ptr2->data<<endl;
            
      }

};
int main(){
      LinkedList l1;
      int n;
      cin>>n;
      while(n--){
            int x;
            cin>>x;
            l1.pushBack(x);

      }
      l1.display();
}
